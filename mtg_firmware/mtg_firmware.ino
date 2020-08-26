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


/* PIN DEFINES */
#define PIN_POWER_SWITCH  (2)
#define PIN_MODE_SWITCH   (A1)
#define PIN_RESET_BTN     (7)
#define PIN_RNG           (A0)


/* CONFIG OPTIONS */
//#define PLAY_TO_WIN           // Enables the PlayToWin easter egg


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
void process_rotary(void);
void process_buttons(void);
void update_display(uint8_t player);
void update_display_all(void);
void counter_reset(LifeCounter_t *counter, int16_t starting_life);
void counter_reset_all(int16_t starting_life);
void counter_sleep(void);
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

    // Initialize counter
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
    // rotary_init();

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

    Serial.println("Initialization complete"); Serial.flush();
}

/*=====================================================================*/

void loop() {

    static uint8_t reset_state_last = digitalRead(PIN_RESET_BTN);
    static uint8_t mode_state_last = digitalRead(PIN_MODE_SWITCH);

    digitalWrite(PIN_DEBUG_2, HIGH);

    // Check for a power-off state
    if (digitalRead(PIN_POWER_SWITCH) == 0)
    {
        counter_sleep();
    }
    
    // Check for reset button activation
    uint8_t reset_state = digitalRead(PIN_RESET_BTN);
    if ((reset_state == 0) && reset_state_last)
    {
        counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
        update_display_all();
        Serial.print("Counter reset. Mode ");
        Serial.println(counters[0].life[0]);
    }
    reset_state_last = reset_state;
    
    // Check for a mode switch activation
    uint8_t mode_state = digitalRead(PIN_MODE_SWITCH);
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

    // Handle rotary changes
    process_rotary();

    // Handle button changes
    process_buttons();

    // Debug printout
    if (switch_state.buttons_changed || switch_state.rotaries_changed)
    {
        switches_print(&switch_state);
    }

    digitalWrite(PIN_DEBUG_2, LOW);
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      process_rotary
 *
 *  DESCRIPTION
 *      Handles changes to the rotary switches by updating the mode
 *      setting of each player
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void process_rotary(void)
{
    // Process rotary switch changes
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

/*---------------------------------------------------------------------*
 *  NAME
 *      process_buttons
 *
 *  DESCRIPTION
 *      Handles all button changes. Changes counter values or resets
 *      the counter
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void process_buttons(void)
{
    // Process button changes
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        // Check if both buttons are held and that one of them changed states
        bool both_held = (
            switch_state.button_state[player_id][0]
            && switch_state.button_state[player_id][1]);
        bool either_changed = (
            switch_state.button_changes[player_id][0]
            || switch_state.button_changes[player_id][1]);
        if (both_held && either_changed)
        {
            // Reset this display
            counter_reset(&counters[player_id], STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
            update_display(player_id);
            continue;
        }
        
        // Handle single button press
        for (uint8_t button = 0; button < BUTTONS_PER_PLAYER; button++)
        {
            // Check if this button changed state and is now pressed
            if (switch_state.button_changes[player_id][button]
                && switch_state.button_state[player_id][button])
            {
                uint8_t mode = counters[player_id].mode;
                int8_t increment = BUTTON_INCREMENT[button];
                int16_t target = counters[player_id].life[mode] + increment;
                if ((target >= LIFE_MODE_MIN[mode]) && (target <= LIFE_MODE_MAX[mode]))
                {
                    // Only change values if we're within the acceptable range for this display mode
                    counters[player_id].life[mode] = target;
                    update_display(player_id);
                }
                break;
            }
        }
    }
}

/*---------------------------------------------------------------------*
 *  NAME
 *      update_display
 *
 *  DESCRIPTION
 *      Updates the display buffer of the given player
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------*
 *  NAME
 *      update_display_all
 *
 *  DESCRIPTION
 *      Updates the display buffer for all players
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void update_display_all(void)
{
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        update_display(player_id);
    }
}

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_reset
 *
 *  DESCRIPTION
 *      Resets the target life counter to the given starting life value
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void counter_reset(LifeCounter_t *counter, int16_t starting_life)
{
    counter->life[0] = starting_life;
    for (uint8_t player_id = 1; player_id < PLAYER_COUNT + 1; player_id++)
    {
        counter->life[player_id] = 0;
    }
}

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_reset_all
 *
 *  DESCRIPTION
 *      Resets all the life counters to the given starting life value
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void counter_reset_all(int16_t starting_life)
{
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        counter_reset(&counters[player_id], starting_life);
    }
}

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_sleep
 *
 *  DESCRIPTION
 *      Puts the system into a power-off safe state and polls the
 *      power switch readback line until power is restored
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void counter_sleep(void)
{
    display_stop();
    switches_stop();
    Serial.println("Going to sleep"); Serial.flush();

    // Wait for the power to get switched back on
    while(digitalRead(PIN_POWER_SWITCH) == 0)
    {
        delay(250);
    };

    // Post-wakeup cleanup
    Serial.println("Woke up");
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
    display_start();
    switches_start();
#ifdef PLAY_TO_WIN
    play_to_win();
#endif
    update_display_all();
}

/*---------------------------------------------------------------------*
 *  NAME
 *      play_to_win
 *
 *  DESCRIPTION
 *      Play to Win Easter Egg
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
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
