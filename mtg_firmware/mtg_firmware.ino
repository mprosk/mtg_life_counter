/* INCLUDES */
#include <avr/sleep.h>
#include "config.h"
#include "display.h"
#include "switches.h"
#include "animations.h"
#include "coretemp.h"

////////////////////////////////////////////////////////////////////////////////
// DEFINES
////////////////////////////////////////////////////////////////////////////////
/* PINS */
#define POWER_SWITCH_PIN  (2)
#define MODE_SWITCH_PIN   (A1)
#define ROLL_BTN_PIN      (6)
#define RESET_BTN_PIN     (7)
#define RNG_PIN           (A0)
#define DEBUG_PIN1        (4)
#define DEBUG_PIN2        (5)
/* CONFIG OPTIONS */
//#define CPU_SLEEP_ENABLE                    // If defined the MCU will enter sleep mode when the power switch is turned off (doesn't work)
//#define PLAY_TO_WIN                         // If defined, enable the PlayToWin easter egg
//#define TEMP_MONITOR                        // If defined, write CPU temp to serial port

////////////////////////////////////////////////////////////////////////////////
// LOCAL TYPES
////////////////////////////////////////////////////////////////////////////////
typedef struct LifeCounter_t
{
  int16_t life[PLAYER_COUNT + 1];   // Life/Damage amounts (self, commander, poison)
  uint8_t mode;                     // Indicates which display mode the counter is in
  int16_t delta;                    // The change in life that the user has entered
  uint32_t timeout;                 // 
} LifeCounter_t;


////////////////////////////////////////////////////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void counter_sleep(void);
void counter_wakeup(void);
void counter_reset(LifeCounter_t *counter, int16_t starting_life);
void counter_reset_all(int16_t starting_life);
void update_display(uint8_t player);
void update_display_all(void);
void rotary_init(void);
void set_buffer(uint8_t * buf, int16_t x);
void animate_roll(uint8_t reset);
void play_to_win(void);
float average_temp();

/*---------------------------------------------------------------------*
 *  NAME
 *      LIFE_MODE_MIN        
 *
 *  DESCRIPTION
 *      The minimum possible counter value for each display mode
 *      Self, Cmdr 1, Cmdr 2, Cmdr 3, Poison
 *---------------------------------------------------------------------*/
static const int16_t LIFE_MODE_MIN[PLAYER_COUNT + 1] = {DISPLAY_MIN, 0, 0, 0, 0};

/*---------------------------------------------------------------------*
 *  NAME
 *      LIFE_MODE_MAX       
 *
 *  DESCRIPTION
 *      The maximum possible counter value for each display mode
 *      Self, Cmdr 1, Cmdr 2, Cmdr 3, Poison
 *---------------------------------------------------------------------*/
static const int16_t LIFE_MODE_MAX[PLAYER_COUNT + 1] = {
    DISPLAY_MAX, COMMANDER_DAMAGE, COMMANDER_DAMAGE, COMMANDER_DAMAGE, POISON_COUNTERS
};

////////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
////////////////////////////////////////////////////////////////////////////////
static LifeCounter_t counters[PLAYER_COUNT];
static SwitchState_t switch_state[2];
static uint8_t sw = 0;
static uint8_t sw_last = 1;


////////////////////////////////////////////////////////////////////////////////

void setup() {
    /* HARDWARE INITIALIZATION */
    Serial.begin(115200);

    // Initialize Top-Level
    pinMode(POWER_SWITCH_PIN, INPUT);
    pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);
    pinMode(ROLL_BTN_PIN, INPUT_PULLUP);
    pinMode(RESET_BTN_PIN, INPUT_PULLUP);
    pinMode(DEBUG_PIN1, OUTPUT);
    pinMode(DEBUG_PIN2, OUTPUT);

    // Initialize 7-Segment Display Driver
    display_init();

    // Initialize Switch Sensing
    switches_init();

#ifdef TEMP_MONITOR
    coretemp_init();
#else
    Serial.println("Initialization complete"); Serial.flush();
#endif
}

void loop() {
    uint8_t reset_state = 0;
    uint8_t reset_state_last = digitalRead(RESET_BTN_PIN);
    
    uint8_t mode_state = 0;
    uint8_t mode_state_last = digitalRead(MODE_SWITCH_PIN);
    
    counter_reset_all(STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)]);
    rotary_init();
    if (digitalRead(POWER_SWITCH_PIN))
    {
        display_start();
        switches_start();
#ifdef PLAY_TO_WIN
        play_to_win();
#endif
        update_display_all();
    }
  
    /* MAIN LOOP */
    while(1)
    {
        digitalWrite(DEBUG_PIN2, HIGH);

#ifdef TEMP_MONITOR
        Serial.println(coretemp_average(100));
#endif

        // Check for a power-off state
        if (digitalRead(POWER_SWITCH_PIN) == 0)
        {
            counter_sleep();
        }
        
        // Check for reset button activation
        reset_state = digitalRead(RESET_BTN_PIN);
        if ((reset_state == 0) && reset_state_last)
        {
            counter_reset_all(STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)]);
            update_display_all();
            Serial.print("Counter reset. Mode ");
            Serial.println(counters[0].life[0]);
        }
        reset_state_last = reset_state;
        
        mode_state = digitalRead(MODE_SWITCH_PIN);
        if (mode_state != mode_state_last)
        {
            uint8_t mode = digitalRead(MODE_SWITCH_PIN);
            if (reset_state == 0)
            {
                // Switch to 30 life mode if the reset button is held when the mode switch changes
                mode = 2;
            }
            counter_reset_all(STARTING_LIFE[mode]);
            update_display_all();
            Serial.print("Mode changed. Mode ");
            Serial.println(counters[0].life[0]);
        }
        mode_state_last = mode_state;
        
        // Handle roll button activation
        uint8_t roll_state = roll();

        // Read switch states
        switches_update(&switch_state[sw]);

        // Process rotary switch changes
        uint8_t rotary_changed = 0;
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            // Check if this rotary switch changed
            if (switch_state[0].rotary_position[i] != switch_state[1].rotary_position[i])
            {
                // If the reading is valid
                int8_t setting = switch_state[sw].rotary_position[i];
                if (setting >= 0)
                {
                    // Update the display mode for this player
                    uint8_t player = SWITCH_PLAYER_MAPPING[i];
                    rotary_changed = 1;
                    counters[player].mode = (uint8_t)setting;
                    update_display(player);
                }
            }
        }

        // Process button changes
        uint8_t changes = switch_state[sw].button_state ^ switch_state[sw_last].button_state;
        if (changes && !roll_state)
        {
            for (uint8_t i = 0; i < BUTTON_COUNT; i++)
            {
                uint8_t mask = (1 << i);
                uint8_t player = BUTTON_PLAYER_MAPPING[i];

                // Check if both buttons in that player group are held
                if (i % 2 == 1)
                {
                    uint8_t mask2 = (1 << (i - 1));
                    if ((switch_state[sw].button_state & mask) &&
                            (switch_state[sw].button_state & mask2))
                    {
                        counter_reset(&counters[player], STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)]);
                        update_display(player);
                        continue;
                    }
                }
                
                // Check if this button was pressed
                if ((switch_state[sw].button_state & mask) && (changes & mask))
                {
                    uint8_t mode = counters[player].mode;
                    int8_t increment = BUTTON_INCREMENT_MAPPING[i];
                    int16_t target = counters[player].life[mode] + increment;
                    if ((target >= LIFE_MODE_MIN[mode]) && (target <= LIFE_MODE_MAX[mode]))
                    {
                        // Only change values if we're within the acceptable range for this display mode
                        counters[player].life[mode] = target;
                        update_display(player);
                    }
                }
            }
        }

        // Debug printout
#ifndef TEMP_MONITOR
        if (changes || rotary_changed)
        {
        switches_print(&switch_state[sw]);
        }
#endif

        // Update internal switch states
        sw ^= 1;
        sw_last ^= 1;

        digitalWrite(DEBUG_PIN2, LOW);
        // delay(5);
    }
}

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Performs all state transitions and animations for the roll feature
 */
uint8_t roll(void)
{
    static uint8_t roll_state = 0;
    static uint8_t roll_state_last = digitalRead(ROLL_BTN_PIN);
    static uint32_t roll_timeout = 0;
    static uint8_t roll_hold = 0;
    
    roll_state = digitalRead(ROLL_BTN_PIN);
    if ((roll_state == 0) && roll_state_last)
    {
        // Button pressed
        Serial.println("Roll started");
        uint8_t roll_counter = 0;
        animate_roll(0);  // Reset the animation
        do
        {
            // Button held
            roll_counter++;
            digitalWrite(DEBUG_PIN1, roll_counter == 0);
            roll_state = digitalRead(ROLL_BTN_PIN);
            animate_roll(1);
        }
        while(roll_state == 0);

        // Button released
        uint8_t roll_result = roll_counter % PLAYER_COUNT;
        roll_hold = 1;
        roll_timeout = millis() + ROLL_RESULT_DURATION_MS;   // TODO: THIS IS NOT ROLLOVER RESISTANT
        // Generate roll result display
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            if (i == roll_result)
            {
                display_set_string(roll_result, "PLAY");  
            }
            else
            {
                display_fill_pattern(i, DIRECTION[PLAYER_MAP[i][roll_result]]);
            }
        }
        Serial.print("Result: ");
        Serial.println(roll_result);
    }
    roll_state_last = roll_state;

    // Clear roll display if timeout expired
    if (roll_hold)
    {
        if (millis() >= roll_timeout)
        {
            roll_hold = 0;
            update_display_all();
        }
    }
    return roll_hold;
}

/*
 * Updates the display buffer with the selected counter data for all players
 */
void update_display(uint8_t player)
{
    uint8_t mode = counters[player].mode;
    display_set_int(player, counters[player].life[mode]);
    if (mode == PLAYER_COUNT)
    {
        // Poison counter mode
        display_set_char(player, 0, 'P');
    }
    else if (mode)
    {
        // Commander damage mode
        display_set_digit(player, 0, DIRECTION[CMDR_DMG_MAP[player][mode]]);
    }
}

/*
 * Updates the display buffer for all players
 */
void update_display_all(void)
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        update_display(i);
    }
}

/*
 * Resets the given counter
 */
void counter_reset(LifeCounter_t *counter, int16_t starting_life)
{
    counter->life[0] = starting_life;
    for (uint8_t i = 1; i < PLAYER_COUNT + 1; i++)
    {
        counter->life[i] = 0;
    }
}

/*
 * Resets all the life counters
 */
void counter_reset_all(int16_t starting_life)
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        counter_reset(&counters[i], starting_life);
    }
}

/*
 * Updates the roll animation
 * 0 = reset, 1 = animate
 */
void animate_roll(uint8_t animate)
{
    static uint8_t animation = ANIMATION_COUNT - 1;
    static uint8_t x = 0;
    static uint32_t inc_time = 0;

    if (animate == 0)
    {
        inc_time = 0;
        animation = (animation + 1) % ANIMATION_COUNT;
        return;
    }
    
    if (millis() >= inc_time)
    {
        inc_time = millis() + ANIMATION_SPEED_MS;   // TODO: THIS IS NOT ROLLOVER REISTANT
        
        // Update display buffer
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            for (uint8_t j = 0; j < DISPLAY_PLAYER_WIDTH; j++)
            {
                display_set_digit(i, j, ANIMATIONS[animation][(x + j) % ANIMATION_LENGTH[animation]]);
            }
        }
        // increment
        x = (x + 1) % ANIMATION_LENGTH[animation];
    }
}

/*
 * Sets the display modes when the unit is first started
 */
void rotary_init(void)
{
    switches_update(&switch_state[sw_last]);
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        int8_t setting = switch_state[sw_last].rotary_position[i];
        uint8_t player = SWITCH_PLAYER_MAPPING[i];
        if (setting >= 0)
        {
            counters[player].mode = (uint8_t)setting;
        }
        else
        {
        // On a bad init read, just assume we're in own life mode
            counters[player].mode = 0;
        }
    }
}

/*
 * Attatches a wake-up interrupt to the power switch and puts the Arduino to sleep
 */
void counter_sleep(void)
{
    display_stop();
    switches_stop();
#ifndef TEMP_MONITOR
    Serial.println("Going to sleep");
    Serial.flush();
#endif
#ifdef CPU_SLEEP_ENABLE
    // Enable wakeup interrupt and sleep the CPU
    sleep_enable();
    attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_wakeup, RISING);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_cpu();
#else
    // Wait for the power to get switched back on
    while(digitalRead(POWER_SWITCH_PIN) == 0)
    {
#ifdef TEMP_MONITOR
        Serial.println(average_temp());
#else
        delay(250);
#endif
    };
#endif
#ifndef TEMP_MONITOR
    Serial.println("Woke up");
#endif
    counter_reset_all(STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)]);
    rotary_init();
    display_start();
    switches_start();
#ifdef PLAY_TO_WIN
  play_t    o_win();
#endif
    update_display_all();
}

/*
 * Wakes up the Arduino and removes the wake-up interrupt
 */
void counter_wakeup(void)
{
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN));
}

/*
 * Play To Win easter egg
 */
 #ifdef PLAY_TO_WIN
void play_to_win(void)
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, "PLAY");
    }
    delay(500);
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, " TO ");
    }
    delay(500);
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, "  IN");
        display_set_digit(i, 0, B00111100);
        display_set_digit(i, 1, B01111000);
    }
    delay(500);
}
#endif
