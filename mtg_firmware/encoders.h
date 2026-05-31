/***********************************************************************
 *  MTG Life Counter - Rotary Encoder Input
 *
 *  DESCRIPTION
 *      Reads encoder rotation and button state for each player
 *
 *  REFERENCES
 *      MTG Life Counter Schematic
 ***********************************************************************/

#if !defined(INC_ENCODERS_H)
#define INC_ENCODERS_H

/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include "config.h"
#include <Arduino.h>

/*=====================================================================*
    Public Data Types
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      encoder_state_t
 *
 *  DESCRIPTION
 *      Snapshot of encoder and button input for all players
 *---------------------------------------------------------------------*/
typedef struct encoder_state_t {
    bool changed; // Indicates if any encoders changed
    int8_t
        encoder[PLAYER_COUNT]; // Array of encoder changes since the last update
    uint8_t button[PLAYER_COUNT]; // Array of button states
} encoder_state_t;

/*=====================================================================*
    Public Functions
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      encoders_init
 *
 *  DESCRIPTION
 *      Initializes the GPIO for the encoders
 *---------------------------------------------------------------------*/
void encoders_init(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      encoders_poll
 *
 *  DESCRIPTION
 *      Reads encoder shift-register state over SPI and updates the
 *      given encoder_state_t. Stops and restarts the display interrupt
 *      internally so callers do not need to coordinate SPI access.
 *---------------------------------------------------------------------*/
void encoders_poll(encoder_state_t* encoders);

#endif /* !defined(INC_ENCODERS_H) */
