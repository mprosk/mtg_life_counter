/***********************************************************************
 *  Project Reference <<TODO>>
 *
 *  DESCRIPTION
 *      <<TODO>> Tells you what the code in the file does.
 *
 *  REFERENCES
 *      <<TODO>> Requirements Specification
 *      <<TODO>> Software Specification
 ***********************************************************************/

#if !defined(INC_COUNTER_H)
#define INC_COUNTER_H


/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <Arduino.h>
#include "config.h"
#include "encoders.h"
#include "display.h"


/*=====================================================================*
    Public Defines
 *=====================================================================*/
#define PIN_BUTTON_1       (A5)
#define PIN_BUTTON_2       (A2)
#define PIN_BUTTON_3       (5)
#define PIN_BUTTON_4       (2)


/*=====================================================================*
    Public Data Types
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
    SELF,
    COMMANDER,
    POISON,
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
    int16_t life;
    uint8_t poison;
    uint8_t commander_dmg[OPPONENT_COMMANDER_COUNT];
    // State
    display_mode_t  mode;        // Current display mode of the counter
    bool partner;               // Indicates the partner commander should be used
    uint8_t commander;          // Index of the opponent commander damage
    int16_t delta;              // The change in life that the user has entered
    uint32_t last_changed;      // the millis timestamp that the counter was last adjusted
} life_counter_t;


/*=====================================================================*
    Public Functions
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_init
 *
 *  DESCRIPTION
 *      Initializes the button GPIO for the counters
 *---------------------------------------------------------------------*/
void counter_init(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_reset
 *
 *  DESCRIPTION
 *      Reset the life counter with the given index and updates the display
 *---------------------------------------------------------------------*/
void counter_reset(uint8_t player_id, int16_t starting_life);

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_reset_all
 *
 *  DESCRIPTION
 *      Resets all life counters and updates the display
 *---------------------------------------------------------------------*/
void counter_reset_all(int16_t starting_life);

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_update_all
 *
 *  DESCRIPTION
 *      Updates all the counters based on the new encoder state
 *      and writes the changes to the display
 *---------------------------------------------------------------------*/
void counter_update_all(encoder_state_t *encoders);

/*---------------------------------------------------------------------*
 *  NAME
 *      counter_redraw_all
 *
 *  DESCRIPTION
 *      Rewrites all counters to the display
 *---------------------------------------------------------------------*/
void counter_redraw_all(void);

#endif /* !defined(INC_COUNTER_H) */
