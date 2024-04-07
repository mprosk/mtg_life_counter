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

#if !defined(INC_ENCODERS_H)
#define INC_ENCODERS_H


/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <Arduino.h>
#include "config.h"


/*=====================================================================*
    Public Defines
 *=====================================================================*/
#define ENCODERS_LATCH_PIN      (3)

#define ENCODERS_BTN_1          (A5)
#define ENCODERS_BTN_2          (A2)
#define ENCODERS_BTN_3          (5)
#define ENCODERS_BTN_4          (2)


/*=====================================================================*
    Public Data Types
 *=====================================================================*/
typedef struct encoder_state_t
{
    bool changed;                   // Indicates if any encoders changed
    int8_t encoder[PLAYER_COUNT];   // Array of encoder changes since the last update
    uint8_t button[PLAYER_COUNT];   // Array of button states
} encoder_state_t;


/*=====================================================================*
    Public Data
 *=====================================================================*/
/* REMOVE THIS SECTION IF NO PUBLIC DATA IS DEFINED */


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
 *      encoders_update
 *
 *  DESCRIPTION
 *      Reads the current encoder state from the shift register
 *      WARNING: the display interrupt MUST be stopped
 *              before running this function
 *---------------------------------------------------------------------*/
void encoders_update(uint8_t state, encoder_state_t *encoders);

#endif /* !defined(INC_ENCODERS_H) */
