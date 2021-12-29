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



/*=====================================================================*
    Private Data
 *=====================================================================*/
static life_counter_t counters[PLAYER_COUNT];


/*=====================================================================*
    Public Function Implementations
 *=====================================================================*/

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
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        bool update = false;

        // Process button presses (low = pressed)
        counters[i].button_last = counters[i].button;
        counters[i].button = !encoders->button[i];
        update = (counters[i].button != counters[i].button_last);
        

        // Process rotary encoder changes
        if (encoders->encoder[i] != 0)
        {
            counters[i].last_changed = millis();
            // TODO: check bounds of life mode
            counters[i].delta += (int16_t)encoders->encoder[i];
            // TODO: increment correct mode
            counters[i].life += (int16_t)encoders->encoder[i];
            update = true;
        }

        // Clear the delta display if the delay has expired
        if (counters[i].delta != 0)
        {
            if ((millis() - counters[i].last_changed) > LIFE_CHANGE_DURATION_MS)
            {
                counters[i].delta = 0;
                update = true;
            }
        }

        // Write changes to the screen
        if (update)
        {
            update_display(i);
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
    int16_t delta = counters[player_id].delta;
    if (delta)
    {
        display_set_int(player_id, delta);
    }

    // Write the value to the screen and add any additional symbols
    switch (counters[player_id].mode)
    {
        case SELF:
            if (delta == 0)
            {
                display_set_int(player_id, counters[player_id].life);
            }
            if (counters[player_id].button)
            {
                display_set_direction(player_id, player_id);
            }
            break;

        case POISON:
            if (delta == 0)
            {
                display_set_int(player_id, counters[player_id].poison);    
            }
            display_set_char(player_id, 0, 'P');
            break;

        case COMMANDER:
            if (delta == 0)
            {
                uint8_t c = counters[player_id].commander;
                display_set_int(player_id, counters[player_id].commander_dmg[c]);
            }
            display_set_direction(player_id, counters[player_id].commander);
            break;

        default:
            break;
    }
}
