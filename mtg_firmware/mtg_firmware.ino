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

/* INCLUDES */
#include <avr/sleep.h>
#include "config.h"
#include "display.h"
#include "switches.h"
#include "roll.h"
#include "coretemp.h"

/* PIN DEFINES */
#define PIN_POWER_SWITCH  (2)
#define PIN_MODE_SWITCH   (A1)
#define PIN_RESET_BTN     (7)
#define PIN_RNG           (A0)


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
    pinMode(PIN_POWER_SWITCH, INPUT);
    pinMode(PIN_MODE_SWITCH, INPUT_PULLUP);
    pinMode(PIN_RESET_BTN, INPUT_PULLUP);
    pinMode(PIN_DEBUG_1, OUTPUT);
    pinMode(PIN_DEBUG_2, OUTPUT);

    // Initialize 7-segment display driver
    display_init();

    // Initialize switch sensing
    switches_init();

    // Initialize roll
    roll_init();

#ifdef TEMP_MONITOR
    // Initialize internal temperature sensor
    coretemp_init();
#endif

    // Initialize counter
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
    rotary_init();

    // Turn on the display if power is on
    if (digitalRead(PIN_POWER_SWITCH))
    {
        display_start();
        switches_start();
#ifdef PLAY_TO_WIN
        play_to_win();
#endif
        update_display_all();
    }

#ifndef TEMP_MONITOR
    Serial.println("Initialization complete"); Serial.flush();
#endif
}

/*=====================================================================*/

void loop() {
    static uint8_t reset_state = 0;
    static uint8_t reset_state_last = digitalRead(PIN_RESET_BTN);
    
    static uint8_t mode_state = 0;
    static uint8_t mode_state_last = digitalRead(PIN_MODE_SWITCH);

    digitalWrite(PIN_DEBUG_2, HIGH);

#ifdef TEMP_MONITOR
    Serial.println(coretemp_average(100));
#endif

    // Check for a power-off state
    if (digitalRead(PIN_POWER_SWITCH) == 0)
    {
        counter_sleep();
    }
    
    // Check for reset button activation
    reset_state = digitalRead(PIN_RESET_BTN);
    if ((reset_state == 0) && reset_state_last)
    {
        counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
        update_display_all();
        Serial.print("Counter reset. Mode ");
        Serial.println(counters[0].life[0]);
    }
    reset_state_last = reset_state;
    
    // Check for a mode switch activation
    mode_state = digitalRead(PIN_MODE_SWITCH);
    if (mode_state != mode_state_last)
    {
        uint8_t mode = digitalRead(PIN_MODE_SWITCH);
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
    
    // Handle roll button
    if(roll())
    {
        // Reset display after roll animation complete
        update_display_all();
    }

    // Get new switch states
    switches_update(&switch_state);

    // Process rotary switch changes
    if (switch_state.rotaries_changed)
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
    if (switch_state.buttons_changed)
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
                    counter_reset(&counters[player], STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
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

    digitalWrite(PIN_DEBUG_2, LOW);
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*
 * Updates the display buffer with the selected counter data for all players
 */
void update_display(uint8_t player_id)
{
    uint8_t mode = counters[player_id].mode;
    display_set_int(player_id, counters[player_id].life[mode]);
    if (mode == PLAYER_COUNT)
    {
        // Poison counter mode
        display_set_char(player_id, 0, 'P');
    }
    else if (mode)
    {
        // Commander damage mode
        display_set_digit(player_id, 0, DIRECTION[CMDR_DMG_MAP[player_id][mode]]);
    }
}

/*
 * Updates the display buffer for all players
 */
void update_display_all(void)
{
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        update_display(player_id);
    }
}

/*
 * Resets the given counter
 */
void counter_reset(LifeCounter_t *counter, int16_t starting_life)
{
    counter->life[0] = starting_life;
    for (uint8_t player_id = 1; player_id < PLAYER_COUNT + 1; player_id++)
    {
        counter->life[player_id] = 0;
    }
}

/*
 * Resets all the life counters
 */
void counter_reset_all(int16_t starting_life)
{
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        counter_reset(&counters[player_id], starting_life);
    }
}



/*
 * Sets the display modes when the unit is first started
 */
void rotary_init(void)
{
    switches_update(&switch_state);
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        int8_t setting = switch_state.rotary_state[player_id];
        if (setting >= 0)
        {
            counters[player_id].mode = (uint8_t)setting;
        }
        else
        {
            // On a bad init read, just assume we're in own life mode
            counters[player_id].mode = 0;
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
    attachInterrupt(digitalPinToInterrupt(PIN_POWER_SWITCH), counter_wakeup, RISING);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_cpu();
#else
    // Wait for the power to get switched back on
    while(digitalRead(PIN_POWER_SWITCH) == 0)
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
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
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
    detachInterrupt(digitalPinToInterrupt(PIN_POWER_SWITCH));
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
