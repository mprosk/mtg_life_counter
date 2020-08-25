/***********************************************************************
 *  MTG Life Counter - Switch Sensing
 *
 *  DESCRIPTION
 *      Provides functions for detecting button and switch states
 *
 *  REFERENCES
 *      74x151 Datasheet
 *      MTG Life Counter Schematic
 ***********************************************************************/

#if !defined(INC_SWITCHES_H)
#define INC_SWITCHES_H

/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <arduino.h>
#include "config.h"

/*=====================================================================*
    Public Defines
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      SWITCH_RB1_PIN
 *
 *  DESCRIPTION
 *      Multiplexer readback pin for the first two rotary switches
 *---------------------------------------------------------------------*/
#define SWITCH_RB1_PIN    (A3)

/*---------------------------------------------------------------------*
 *  NAME
 *      SWITCH_RB2_PIN
 *
 *  DESCRIPTION
 *      Multiplexer readback pin for the second two rotary switches
 *---------------------------------------------------------------------*/
#define SWITCH_RB2_PIN    (A2)

/*---------------------------------------------------------------------*
 *  NAME
 *      BUTTON_RB_PIN
 *
 *  DESCRIPTION
 *      Multiplexer readback pin for the buttons
 *---------------------------------------------------------------------*/
#define BUTTON_RB_PIN     (A4)

/*---------------------------------------------------------------------*
 *  NAME
 *      MUX_SELECT_0
 *
 *  DESCRIPTION
 *      Pin bit 0 of the multiplexer select bus
 *---------------------------------------------------------------------*/
#define MUX_SELECT_0      (A5)

/*---------------------------------------------------------------------*
 *  NAME
 *      MUX_SELECT_1
 *
 *  DESCRIPTION
 *      Pin bit 1 of the multiplexer select bus
 *---------------------------------------------------------------------*/
#define MUX_SELECT_1      (A0)

/*---------------------------------------------------------------------*
 *  NAME
 *      MUX_SELECT_2
 *
 *  DESCRIPTION
 *      Pin bit 2 of the multiplexer select bus
 *---------------------------------------------------------------------*/
#define MUX_SELECT_2      (10)


/*=====================================================================*
    Public Data Types
 *=====================================================================*/
typedef struct SwitchState_t
{
    uint8_t button_state;         // Bitfield of push button states
    int8_t rotary_position[PLAYER_COUNT];
} SwitchState_t;

/*=====================================================================*
    Public Functions
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_init
 *
 *  DESCRIPTION
 *      Initializes the switch sensing hardware
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_init(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_start
 *
 *  DESCRIPTION
 *      Starts switch scanning and enables the hardware
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_start(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_stop
 *
 *  DESCRIPTION
 *      Stops the switch scanning and disables the hardware
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_stop(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_update
 *
 *  DESCRIPTION
 *      Scans through the multiplexers and reads the switch states
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_update(SwitchState_t * state_ptr);

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_print
 *
 *  DESCRIPTION
 *      Prints the state position to the screen
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_print(SwitchState_t *state_ptr);


#endif /* !defined(INC_SWITCHES_H) */
