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
#include "config.h"
#include "display.h"
#include "encoders.h"
#include "roll.h"


/* PIN DEFINES */
#define PIN_MODE_SWITCH   (9)
#define PIN_RESET_BTN     (8)


/* CONFIG OPTIONS */
// #define SPLASH_SCREEN           // Enables the splash screen


/*=====================================================================*
    Private Data Types
 *=====================================================================*/
typedef enum DisplayMode_t
{
    CMDR1A,
    CMDR1B,
    CMDR2A,
    CMDR2B,
    CMDR3A,
    CMDR3B,
    POISON,
    SELF,
} DisplayMode_t;

typedef struct life_counter_t
{
    uint8_t id;
    // Counters
    int16_t life;
    uint8_t poison;
    uint8_t commander_dmg[OPPONENT_COMMANDER_COUNT];
    // State
    DisplayMode_t  mode;        // Current display mode of the counter
    bool partner;               // Indicates the partner commander should be used
    int16_t delta;              // The change in life that the user has entered
    uint32_t last_changed;      // the millis timestamp that the counter was last adjusted
} life_counter_t;


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
static life_counter_t counters[PLAYER_COUNT];
static encoder_state_t encoders;


/*=====================================================================*
    Arduino Hooks
 *=====================================================================*/

void setup()
{
    /* HARDWARE INITIALIZATION */
    Serial.begin(115200);
    Serial.println("Startup");

    // Initialize top-level GPIO
    pinMode(PIN_MODE_SWITCH, INPUT_PULLUP);
    pinMode(PIN_RESET_BTN, INPUT_PULLUP);
    pinMode(PIN_DEBUG_1, OUTPUT);
    pinMode(PIN_DEBUG_2, OUTPUT);

    // Initialize counters
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        counters[i].id = i;
    }
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);
    update_display_all();

    // Initialize roll
    roll_init();

    // Initialize encoders
    encoders_init();

    // Initialize display
    display_init();
    display_start();

    Serial.println("Initialization complete"); Serial.flush();

    // Tests
    // display_test();
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
        Serial.println(counters[0].life);
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
        Serial.println(counters[0].life);
    }
    mode_state_last = mode_state;

    // Handle roll button
    if(roll())
    {
        // Reset display after roll animation complete
        update_display_all();
    }

    // Handle encoder changes
    update_encoders(&encoders);
    if (encoders.changed)
    {
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            if (encoders.encoder[i])
            {
                counters[i].last_changed = millis();
                // TODO: check bounds of life mode
                counters[i].delta += (int16_t)encoders.encoder[i];
                // TODO: increment correct mode
                counters[i].life += (int16_t)encoders.encoder[i];
                update_display(&counters[i]);
            }
        }
    }

    // Handle clearing delta displays
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        if (counters[player_id].delta != 0)
        {
            if ((millis() - counters[player_id].last_changed) > LIFE_CHANGE_DURATION_MS)
            {
                counters[player_id].delta = 0;
                update_display(&counters[player_id]);
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
 *      update_encoders
 *
 *  DESCRIPTION
 *      Updates the display buffer of the given player
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void update_encoders(encoder_state_t *encoders)
{
    // Stop the display interrupt
    display_stop();
    // Read the current encoder state
    digitalWrite(ENCODERS_LATCH_PIN, LOW);
    digitalWrite(ENCODERS_LATCH_PIN, HIGH);
    uint8_t state = SPI.transfer(0);
    // Restart the display interrupt
    display_start();

    // Update encoders
    encoders_update(state, encoders);

    if (encoders->changed)
    {
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            Serial.print(encoders->encoder[i]);
            Serial.print(" ");
        }
        Serial.println("");
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
void update_display(life_counter_t *counter)
{
    int16_t value = counter->life;

    if (counter->delta != 0)
    {
        value = counter->delta;
    }

    // Write the value to the screen and add any additional symbols
    display_set_int(counter->id, value);
    switch (counter->mode)
    {
        case SELF:
            break;

        case POISON:
            display_set_char(counter->id, 0, 'P');
            break;

        default:
            // Commander damage mode
            display_set_digit(counter->id, 0, DIRECTION[CMDR_DMG_MAP[counter->id][counter->mode]]);
            break;
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
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
       update_display(&counters[i]);
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
void counter_reset(life_counter_t *counter, int16_t starting_life)
{
    counter->life = starting_life;
    counter->poison = 0;
    for (uint8_t i = 0; i < OPPONENT_COMMANDER_COUNT; i++)
    {
        counter->commander_dmg[i] = 0;
    }
    counter->mode = SELF;
    counter->partner = false;
    counter->delta = 0;
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
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        counter_reset(&counters[i], starting_life);
    }
}


/*=====================================================================*
    Tests
 *=====================================================================*/

void display_test(void)
{
    display_set_string(0, "ONE_");
    display_set_string(1, "TWwO");
    display_set_string(2, "THRE");
    display_set_string(3, "FOUR");
    uint8_t i = 0;
    while (1)
    {
        Serial.println(i);
        i++;
        delay(1000);
    }
}

void encoder_test(void)
{
    int16_t vals[PLAYER_COUNT] = {0, 0, 0, 0};

    while (1)
    {
        update_encoders(&encoders);
        if (encoders.changed)
        {
            for (uint8_t i = 0; i < PLAYER_COUNT; i++)
            {
                Serial.print(encoders.encoder[i]);
                Serial.print(" ");
                vals[i] += encoders.encoder[i];
                display_set_int(i, vals[i]);
            }
            Serial.println("");
        }
        delayMicroseconds(100);
    }
}
