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

/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "switches.h"

/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
static int8_t switches_decode_rotary(uint8_t switch_state);

/*=====================================================================*
    Private Data
 *=====================================================================*/
static uint8_t button_state = 0;
static uint8_t[4] rotary_state = 0;

/*=====================================================================*
    Public Function Implementations
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
void switches_init(void)
{
    pinMode(SWITCH_RB1_PIN, INPUT);
    pinMode(SWITCH_RB2_PIN, INPUT);
    pinMode(BUTTON_RB_PIN, INPUT);
}

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
void switches_start(void)
{
    pinMode(MUX_SELECT_0, OUTPUT);
    pinMode(MUX_SELECT_1, OUTPUT);
    pinMode(MUX_SELECT_2, OUTPUT);
}

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
void switches_stop(void)
{
    digitalWrite(MUX_SELECT_0, LOW);
    digitalWrite(MUX_SELECT_1, LOW);
    digitalWrite(MUX_SELECT_2, LOW);
    pinMode(MUX_SELECT_0, INPUT);
    pinMode(MUX_SELECT_1, INPUT);
    pinMode(MUX_SELECT_2, INPUT);
}

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
void switches_update(SwitchState_t * state_ptr)
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
    state_ptr->rotary_position[0] = switches_decode_rotary(sw_1_2 & 0x0F);
    state_ptr->rotary_position[1] = switches_decode_rotary((sw_1_2 & 0xF0) >> 4);
    state_ptr->rotary_position[2] = switches_decode_rotary(sw_3_4 & 0x0F);
    state_ptr->rotary_position[3] = switches_decode_rotary((sw_3_4 & 0xF0) >> 4);
}

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
void switches_print(SwitchState_t *state_ptr)
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


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/
int8_t switches_decode_rotary(uint8_t rotary_state)
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        if (rotary_state == (1 << i))
        {
        return PLAYER_COUNT - i - 1;
        }
    }
    if (rotary_state == 0)
    {
        // Poison counter
        return PLAYER_COUNT;
    }
    return -1;
}
