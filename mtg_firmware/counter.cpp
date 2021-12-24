/***********************************************************************
 *  Project Reference <<TODO>>
 *
 *  DESCRIPTION
 *      <<TODO>> Tells you what the code in the file does or refers to
 *      accompanying header file.
 *
 *  REFERENCES
 *      <<TODO>> Requirements Specification
 *      <<TODO>> Software Specification
 ***********************************************************************/

/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "counter.h"


/*=====================================================================*
    Interface Header Files
 *=====================================================================*/
/* None */


/*=====================================================================*
    System-wide Header Files
 *=====================================================================*/
/* None */


/*=====================================================================*
    Private Defines
 *=====================================================================*/
/* None */


/*=====================================================================*
    Private Data Types
 *=====================================================================*/
/* None */


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
void update_display(uint8_t player_id);


/*=====================================================================*
    Private Constants
 *=====================================================================*/
static const uint8_t BUTTON_PINS[PLAYER_COUNT] = {
    PIN_BUTTON_1, PIN_BUTTON_2, PIN_BUTTON_3, PIN_BUTTON_4
};


/*=====================================================================*
    Private Data
 *=====================================================================*/
static life_counter_t counters[PLAYER_COUNT];


/*=====================================================================*
    Public Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_init
 *
 *  DESCRIPTION
 *      Initializes the button GPIO for the counters
 *---------------------------------------------------------------------*/
void counter_init(void)
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        pinMode(BUTTON_PINS[i], INPUT_PULLUP);
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
    counters[player_id].life = starting_life;
    counters[player_id].poison = 0;
    for (uint8_t i = 0; i < OPPONENT_COMMANDER_COUNT; i++)
    {
        counters[player_id].commander_dmg[i] = 0;
    }
    counters[player_id].mode = SELF;
    counters[player_id].partner = false;
    counters[player_id].commander = 0;
    counters[player_id].delta = 0;

    update_display(player_id);
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

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_update_all
 *
 *  DESCRIPTION
 *      Updates all the counters based on the new encoder state
 *      Writes the changes to the display
 *---------------------------------------------------------------------*/
void counter_update_all(encoder_state_t *encoders)
{
    static uint8_t buttons_last[PLAYER_COUNT] = {1, 1, 1, 1};
    uint8_t buttons_now[PLAYER_COUNT] = {1, 1, 1, 1};

    // Read the current button states
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        buttons_now[i] = digitalRead(BUTTON_PINS[i]);
    }

    // Process changes
    if (encoders->changed)
    {
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            if (encoders->encoder[i] != 0)
            {
                counters[i].last_changed = millis();
                // TODO: check bounds of life mode
                counters[i].delta += (int16_t)encoders->encoder[i];
                // TODO: increment correct mode
                counters[i].life += (int16_t)encoders->encoder[i];
                update_display(i);

                // Print state
                Serial.print(encoders->encoder[i]);
                Serial.print(" ");
            }
        }
        Serial.println("");
    }

    // Store the current button state as the last button state
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        buttons_last[i] = buttons_now[i];
    }

    // Handle clearing delta displays
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
}

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_redraw_all
 *
 *  DESCRIPTION
 *      Rewrites all counters to the display
 *---------------------------------------------------------------------*/
void counter_redraw_all(void)
{
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        update_display(player_id);
    }
}

/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      update_display
 *
 *  DESCRIPTION
 *      Renders the given counter to the display
 *---------------------------------------------------------------------*/
void update_display(uint8_t player_id)
{
    int16_t value = counters[player_id].life;

    if (counters[player_id].delta != 0)
    {
        value = counters[player_id].delta;
    }

    // Write the value to the screen and add any additional symbols
    display_set_int(player_id, value);
    switch (counters[player_id].mode)
    {
        case SELF:
            break;

        case POISON:
            display_set_char(player_id, 0, 'P');
            break;

        case COMMANDER:
            display_set_direction(player_id, counters[player_id].commander);
            break;

        default:
            break;
    }
}
