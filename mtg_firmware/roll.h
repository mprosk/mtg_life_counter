/***********************************************************************
 *  MTG Life Counter - Roll Button Engine
 *
 *  DESCRIPTION
 *      This module provides functions for enabling the roll feature
 *      of the counter. This feature allows players to randomly select
 *      one of the players (for randomly select first player or 
 *      damage targets). The result of the roll is shown on the display
 *
 *  REFERENCES
 *      None
 ***********************************************************************/

#if !defined(INC_ROLL_H)
#define INC_ROLL_H


/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <Arduino.h>
#include "config.h"
#include "animations.h"
#include "display.h"


/*=====================================================================*
    Public Defines
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      PIN_ROLL_BTN
 *
 *  DESCRIPTION
 *      Pin number of the roll button
 *---------------------------------------------------------------------*/
#define PIN_ROLL_BTN      (7)

/*---------------------------------------------------------------------*
 *  NAME
 *      ANIMATION_SPEED_MS
 *
 *  DESCRIPTION
 *      Delay in ms between frames of the roll animations
 *---------------------------------------------------------------------*/
#define ANIMATION_SPEED_MS          (50)

/*---------------------------------------------------------------------*
 *  NAME
 *      ROLL_RESULT_DURATION_MS
 *
 *  DESCRIPTION
 *      Time in ms that the roll result will be displayed
 *---------------------------------------------------------------------*/
#define ROLL_RESULT_DURATION_MS     (2000)

/*---------------------------------------------------------------------*
 *  NAME
 *      ROLL_ADAPTIVE_MODE
 *
 *  DESCRIPTION
 *      If enabled, causes roll results to never pick the player that
 *      won the previous roll
 *---------------------------------------------------------------------*/
#define ROLL_ADAPTIVE_MODE


/*=====================================================================*
    Public Functions
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      roll_init
 *
 *  DESCRIPTION
 *      Initializes the roll button pin
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void roll_init(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      roll
 *
 *  DESCRIPTION
 *      Handles the roll button input and sends animations to the display
 *
 *  RETURNS
 *      True if the roll animation occurred
 *---------------------------------------------------------------------*/
bool roll(void);


#endif /* !defined(INC_ROLL_H) */
