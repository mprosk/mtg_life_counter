#ifndef _SWITCHES_H_
#define _SWITCHES_H_

#include <arduino.h>
#include "config.h"

////////////////////////////////////////////////////////////////////////////////
// DEFINES
////////////////////////////////////////////////////////////////////////////////
#define SWITCH_RB1_PIN    (A3)
#define SWITCH_RB2_PIN    (A2)
#define BUTTON_RB_PIN     (A4)
#define MUX_SELECT_0      (A5)
#define MUX_SELECT_1      (A6)
#define MUX_SELECT_2      (A7)

////////////////////////////////////////////////////////////////////////////////
// PUBLIC TYPES
////////////////////////////////////////////////////////////////////////////////
typedef struct SwitchState
{
  uint8_t button_state;         // Bitfield of push button states
  uint8_t rotary_position[PLAYER_COUNT];
} SwitchState;

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void switches_init(void);
void switches_update(SwitchState * state_ptr);
uint8_t switches_changed(SwitchState * state_a, SwitchState * state_b);
void switches_print(SwitchState *state_ptr);


#endif /* _SWITCHES_H_ */
