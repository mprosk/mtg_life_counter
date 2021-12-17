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
#include "roll.h"


/* PIN DEFINES */
#define PIN_MODE_SWITCH   (9)
#define PIN_RESET_BTN     (8)


/* CONFIG OPTIONS */
// #define PLAY_TO_WIN           // Enables the PlayToWin easter egg
// #define ROTARY_SP5T           // Enables poison counter mode with the 5pos switch


/*=====================================================================*
    Private Data Types
 *=====================================================================*/
typedef enum DisplayMode_t
{
    SELF,
    CMDR1,
    CMDR2,
    CMDR3,  
    POISON
} DisplayMode_t;

typedef struct LifeCounter_t
{
  int16_t life[PLAYER_COUNT + 1];   // Life/Damage amounts (self, commander, poison)
  DisplayMode_t  mode;               // Indicates which display mode the counter is in
  int16_t delta;                    // The change in life that the user has entered
  uint32_t last_changed;            // the millis timestamp that the counter was last adjusted
  DisplayMode_t *mode_mapping;     // Maps rotary index to the specific mode for this player
} LifeCounter_t;


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
void update_display(uint8_t player_id);
void update_display_all(void);
void counter_reset(uint8_t player_id, int16_t starting_life);
void counter_reset_all(int16_t starting_life);


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

/*---------------------------------------------------------------------*
 *  NAME
 *      MODE_SEQ_x       
 *
 *  DESCRIPTION
 *      Maps the rotary switch position to the display mode that should be applied
 *---------------------------------------------------------------------*/
static const DisplayMode_t MODE_SEQ_1[] = {SELF, POISON, CMDR3, CMDR2, CMDR1};
static const DisplayMode_t MODE_SEQ_2[] = {POISON, CMDR3, CMDR2, CMDR1, SELF};


/*=====================================================================*
    Private Data
 *=====================================================================*/
static LifeCounter_t counters[PLAYER_COUNT];


/*=====================================================================*
    Arduino Hooks
 *=====================================================================*/

void setup()
{
    /* HARDWARE INITIALIZATION */
    Serial.begin(115200);
    Serial.println("Startup");

    // Initialize Top-Level
    pinMode(PIN_MODE_SWITCH, INPUT_PULLUP);
    pinMode(PIN_RESET_BTN, INPUT_PULLUP);
    pinMode(PIN_DEBUG_1, OUTPUT);
    pinMode(PIN_DEBUG_2, OUTPUT);

    // Initialize counter
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
    update_display_all();

    // Initialize roll
    roll_init();

    // Initialize 7-segment display driver
    display_init();
    display_start();

    Serial.println("Initialization complete"); Serial.flush();

    // Tests
    display_test();
    // encoder_test();
}

/*=====================================================================*/

void loop()
{
    static uint8_t reset_state_last = digitalRead(PIN_RESET_BTN);
    static uint8_t mode_state_last = digitalRead(PIN_MODE_SWITCH);

    digitalWrite(PIN_DEBUG_2, HIGH);
    
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


    // Handle delta displays
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        if (counters[player_id].delta != 0)
        {
            if ((millis() - counters[player_id].last_changed) > LIFE_CHANGE_DURATION_MS)
            {
                counters[player_id].delta = 0;
                update_display(player_id);
            }
        }
    }

    digitalWrite(PIN_DEBUG_2, LOW);
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

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
    DisplayMode_t mode = counters[player_id].mode;
    int16_t value = counters[player_id].life[mode];
    
    if (counters[player_id].delta != 0)
    {
        value = counters[player_id].delta;
    }
    
    // Write the value to the screen and add any additional symbols
    display_set_int(player_id, value);
    if (mode == SELF)
    {
        return;
    }
    else if (mode == POISON)
    {
        // Poison counter mode
        display_set_char(player_id, 0, 'P');
    }
    else
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
void counter_reset(uint8_t player_id, int16_t starting_life)
{
    counters[player_id].delta = 0;
    counters[player_id].life[SELF] = starting_life;
    counters[player_id].life[CMDR1] = 0;
    counters[player_id].life[CMDR2] = 0;
    counters[player_id].life[CMDR3] = 0;
    counters[player_id].life[POISON] = 0;    
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
        counter_reset(player_id, starting_life);
    }
}


/*=====================================================================*
    Tests
 *=====================================================================*/

void display_test(void)
{
    display_set_string(0, "ONE ");
    display_set_string(1, "TWwO");
    display_set_string(2, "THRE");
    display_set_string(3, "FOUR");
    while (1) {}
}
