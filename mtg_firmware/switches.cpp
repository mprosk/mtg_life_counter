#include "switches.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Initialize the pins used for switch readback
 */
void switches_init(void)
{
  pinMode(SWITCH_RB1_PIN, INPUT);
  pinMode(SWITCH_RB2_PIN, INPUT);
  pinMode(BUTTON_RB_PIN, INPUT);
  pinMode(MUX_SELECT_0, OUTPUT);
  pinMode(MUX_SELECT_1, OUTPUT);
  pinMode(MUX_SELECT_2, OUTPUT);
}

/*
 * Scans through the multiplexers and reads the switch states
 */
void switches_update(SwitchState * state_ptr)
{
  uint8_t sw_1_2 = 0;
  uint8_t sw_3_4 = 0;

  // Scan through the mux and read back
  for (uint8_t i = 0; i < 8; i++)
  {
    // Update the select bus
    digitalWrite(MUX_SELECT_0, i & (1 << 0));
    digitalWrite(MUX_SELECT_1, i & (1 << 1));
    digitalWrite(MUX_SELECT_2, i & (1 << 2));
//    delay(1);

    // Read button state
    if (digitalRead(BUTTON_RB_PIN))
    {
      state_ptr->button_state |= (1 << i);
    }
    else
    {
      state_ptr->button_state &= ~(1 << i);
    }
    
    // Read rotary switch state
    sw_1_2 |= (digitalRead(SWITCH_RB1_PIN) << i);
    sw_3_4 |= (digitalRead(SWITCH_RB2_PIN) << i);
  }

  // Decode the rotary switch positions
  state_ptr->rotary_position[0] = (sw_1_2 & 0x0F);
  state_ptr->rotary_position[1] = (sw_1_2 & 0xF0) >> 4;
  state_ptr->rotary_position[2] = (sw_3_4 & 0x0F);
  state_ptr->rotary_position[3] = (sw_3_4 & 0xF0) >> 4;
}

/*
 * Returns 1 if the rotray switch settings between two given SwitchStates are different
 */
uint8_t switches_rotary_changed(SwitchState * state_a, SwitchState * state_b)
{
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    if (state_a->rotary_position[i] != state_b->rotary_position[i])
    {
      return 1;
    }
  }
  return 0;
}

/*
 * Prints the state position to the screen
 */
void switches_print(SwitchState *state_ptr)
{
  for (uint8_t i = 0; i < BUTTON_COUNT; i++)
  {
    Serial.print((state_ptr->button_state & (1 << i)) >> i);
    Serial.print(" ");
  }
  Serial.print("| ");
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    Serial.print(state_ptr->rotary_position[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
