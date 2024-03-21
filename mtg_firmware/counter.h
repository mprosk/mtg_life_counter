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



/*=====================================================================*
    Public Data Types
 *=====================================================================*/




/*=====================================================================*
    Public Functions
 *=====================================================================*/

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
 *      counter_reset_on_button
 *
 *  DESCRIPTION
 *      Resets an individual counter if its encoder button is pressed
 *      Returns the number of counters that were reset.
 *      Zero if no counters were changed
 *---------------------------------------------------------------------*/
uint8_t counter_reset_on_button(int16_t starting_life);

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
