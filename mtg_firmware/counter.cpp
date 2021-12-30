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

/*---------------------------------------------------------------------*
 *  NAME
 *      display_mode_t       
 *
 *  DESCRIPTION
 *      Enum listing the different display modes the counter can be in
 *---------------------------------------------------------------------*/
typedef enum display_mode_t
{
    CMDR_1,
    CMDR_2,
    CMDR_3,
    POISON,
    SELF,
    NUM_DISPLAY_MODES,   // Invalid enum value. Used to indicate number of modes
} display_mode_t;

/*---------------------------------------------------------------------*
 *  NAME
 *      life_counter_t       
 *
 *  DESCRIPTION
 *      Container struct for a single life counter and associated data
 *---------------------------------------------------------------------*/
typedef struct life_counter_t
{
    // Counters
    int16_t life[NUM_DISPLAY_MODES];
    int16_t partner_dmg[PLAYER_COUNT - 1];  // Secondary counters for partner damage only
    // State
    display_mode_t  mode;       // Current display mode of the counter
    bool partner_enabled[PLAYER_COUNT -1];  // Flag if the player at this index has a partner
    bool partner_selected;      // Flag if the partner damage of the current commander is selected
    int16_t delta;              // The change in life that the user has entered
    uint32_t last_changed;      // The millis timestamp that the counter was last adjusted
    bool button;                // Current state of the button
    bool button_last;           // Previous state of the button
} life_counter_t;


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
void update_display(uint8_t player_id);


/*=====================================================================*
    Private Constants
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      COUNTER_MODE_MAX_VALUE
 *
 *  DESCRIPTION
 *      List of the maximum value for each counter mode
 *---------------------------------------------------------------------*/
static const int16_t COUNTER_MODE_MAX_VALUE[NUM_DISPLAY_MODES] = {
    COMMANDER_DAMAGE,
    COMMANDER_DAMAGE,
    COMMANDER_DAMAGE,
    POISON_COUNTERS,
    DISPLAY_MAX,
};

/*=====================================================================*
    Private Data
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      counters
 *
 *  DESCRIPTION
 *      Array of four life_counter_t structs used to contain game state
 *---------------------------------------------------------------------*/
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
    for (uint8_t i = 0; i < NUM_DISPLAY_MODES; i++)
    {
        counters[player_id].life[i] = 0;
    }

    for (uint8_t i = 0; i < PLAYER_COUNT - 1; i++)
    {
        counters[player_id].partner_dmg[i] = 0;
        counters[player_id].partner_enabled[i] = false;
    }

    counters[player_id].life[SELF] = starting_life;
    
    counters[player_id].mode = SELF;
    counters[player_id].partner_selected = false;
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
 *      counter_reset_on_button
 *
 *  DESCRIPTION
 *      Resets an individual counter if its encoder button is pressed
 *      Returns the number of counters that were reset.
 *      Zero if no counters were changed
 *---------------------------------------------------------------------*/
uint8_t counter_reset_on_button(int16_t starting_life)
{
    uint8_t ret = 0;
    for (uint8_t player_id = 0; player_id < PLAYER_COUNT; player_id++)
    {
        if (counters[player_id].button)
        {
            counter_reset(player_id, starting_life);
            ret ++;
        }
    }
    return ret;
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
        life_counter_t * c = &counters[i];

        bool update = false;

        // Process button presses (low = pressed)
        c->button_last = c->button;
        c->button = !encoders->button[i];
        update = (c->button != c->button_last);

        // Process rotary encoder changes
        int8_t enc = encoders->encoder[i];
        if (enc != 0)
        {
            if (c->button)
            {
                // Button is held - change display mode
                c->mode = (uint8_t)((int8_t)c->mode + enc) % NUM_DISPLAY_MODES;
                c->delta = 0;
                update = true;
            }
            else
            {
                // Button not held - change counter value

                // Determine where the change will put us
                int16_t target = c->life[c->mode] + (int16_t)enc;

                // Check that the change is within the upper bounds for this mode
                if (target <= COUNTER_MODE_MAX_VALUE[c->mode])
                {
                    // Check that the change is within the lower bounds
                    // Normal life total min = display min, others = 0
                    if (((c->mode == SELF) && (target >= DISPLAY_MIN)) || (target >= 0))
                    {
                        // Increment the counter
                        c->delta += (int16_t)enc;
                        c->life[c->mode] = target;
                        update = true;
                    }
                }
            }
            // Update the timestamp
            c->last_changed = millis();
        }

        // Clear the delta display if the delay has expired
        if (c->delta != 0)
        {
            if ((millis() - c->last_changed) > LIFE_CHANGE_DURATION_MS)
            {
                c->delta = 0;
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
    display_mode_t mode = counters[player_id].mode;

    // Get the value to display based on the current mode
    int16_t value = counters[player_id].life[mode];

    // If there is a current delta, display that instead
    if (counters[player_id].delta != 0)
    {
        value = counters[player_id].delta;
    }

    // Write the value to the display
    display_set_int(player_id, value);

    // Write any additional symbols to the screen based on mode
    switch (mode)
    {
        case SELF:
            if (counters[player_id].button)
            {
                display_set_direction(player_id, PLAYER_COUNT - 1);
            }
            break;

        case POISON:
            display_set_char(player_id, 0, 'P');
            break;

        case CMDR_1:
        case CMDR_2:
        case CMDR_3:
            // uint8_t commander_index = ((uint8_t)mode - 1) >> 1;
            display_set_direction(player_id, mode);
            break;

        default:
            // Invalid state
            display_set_char(player_id, 0, 0xFF);
            break;
    }
}
