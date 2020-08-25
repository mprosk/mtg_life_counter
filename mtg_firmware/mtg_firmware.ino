/***********************************************************************
 *  MTG Life Counter
 *
 *  DESCRIPTION
 *      Four player life counter for Magic: The Gathering
 *      Life totals are displayed on 7-segement displays
 *      Players adjust life using up/down buttons, and can
 *      track commander damage and poison counters using a 
 *      rotary switch to change display modes.
 *
 *  REFERENCES
 *      MTG Life Counter Schematic
 ***********************************************************************/

/*=====================================================================*
    Interface Header Files
 *=====================================================================*/
#include "config.h"
#include "display.h"
#include "switches.h"
#include "animations.h"
#include "coretemp.h"

/*=====================================================================*
    System-wide Header Files
 *=====================================================================*/
#include <avr/sleep.h>


/*=====================================================================*
    Private Defines
 *=====================================================================*/
/* PINS */
#define POWER_SWITCH_PIN  (2)
#define MODE_SWITCH_PIN   (A1)
#define ROLL_BTN_PIN      (6)
#define RESET_BTN_PIN     (7)
#define RNG_PIN           (A0)
#define DEBUG_PIN1        (4)
#define DEBUG_PIN2        (5)
/* CONFIG OPTIONS */
//#define CPU_SLEEP_ENABLE      // MCU will enter sleep mode when the power switch is turned off (doesn't work)
//#define PLAY_TO_WIN           // Enables the PlayToWin easter egg
//#define TEMP_MONITOR          // Write CPU temp to serial port (slows normal operation)


/*=====================================================================*
    Private Data Types
 *=====================================================================*/
typedef struct LifeCounter_t
{
  int16_t life[PLAYER_COUNT + 1];   // Life/Damage amounts (self, commander, poison)
  uint8_t mode;                     // Indicates which display mode the counter is in
  int16_t delta;                    // The change in life that the user has entered
  uint32_t timeout;                 // 
} LifeCounter_t;


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
void counter_sleep(void);
void counter_wakeup(void);
void counter_reset(LifeCounter_t *counter, int16_t starting_life);
void counter_reset_all(int16_t starting_life);
void update_display(uint8_t player);
void update_display_all(void);
void rotary_init(void);
void animate_roll(uint8_t reset);
void play_to_win(void);


/*=====================================================================*
    Private Constants
 *=====================================================================*/

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


/*=====================================================================*
    Private Data
 *=====================================================================*/
static LifeCounter_t counters[PLAYER_COUNT];
static SwitchState_t switch_state;


/*=====================================================================*
    Arduino Hooks
 *=====================================================================*/

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

/*=====================================================================*/

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
        
        // Check for a mode switch activation
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

        // Get new switch states
        switches_update(&switch_state);

        // Process rotary switch changes
        if (switch_state.rotaries_changed && !roll_state)
        {
            for (uint8_t player = 0; player < PLAYER_COUNT; player++)
            {
                // Check if this rotary switch changed
                if (switch_state.rotary_changes[player])
                {
                    // Check if the reading is valid
                    int8_t setting = switch_state.rotary_state[player];
                    if (setting >= 0)
                    {
                        // Update the display mode for this player
                        counters[player].mode = (uint8_t)setting;
                        update_display(player);
                    }
                }
            }
        }
        
         // Process button changes
        if (switch_state.buttons_changed && !roll_state)
        {
            for (uint8_t player = 0; player < PLAYER_COUNT; player++)
            {
                for (uint8_t button = 0; button < BUTTONS_PER_PLAYER; button++)
                {

                    // Check if both buttons in that player group are held and at least one of the buttons changed
                    if ((button == 1)
                        && switch_state.button_state[player][button]
                        && switch_state.button_state[player][button - 1])
                    {
                        counter_reset(&counters[player], STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)]);
                        update_display(player);
                        continue;
                    }

                    // Check if this button changed state and is now pressed
                    if (switch_state.button_changes[player][button]
                        && switch_state.button_state[player][button])
                    {
                        uint8_t mode = counters[player].mode;
                        int8_t increment = BUTTON_INCREMENT[button];
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
        }

        // Debug printout
#ifndef TEMP_MONITOR
        if (switch_state.buttons_changed || switch_state.rotaries_changed)
        {
            switches_print(&switch_state);
        }
#endif

        digitalWrite(DEBUG_PIN2, LOW);
    }
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

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
    switches_update(&switch_state);
    for (uint8_t player = 0; player < PLAYER_COUNT; player++)
    {
        int8_t setting = switch_state.rotary_state[player];
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
