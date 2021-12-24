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
#include "encoders.h"


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
#define ENCODER_MASK    (0x2)


/*=====================================================================*
    Private Data Types
 *=====================================================================*/
/* None */


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
/* None */


/*=====================================================================*
    Private Data
 *=====================================================================*/
static const uint8_t ENCODER_INDEX[PLAYER_COUNT] = {2, 3, 0, 1};
static const int8_t ENCODER_DIRECTION[2] = {1, -1};


/*=====================================================================*
    Public Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      encoders_init
 *
 *  DESCRIPTION
 *      Initializes the GPIO for the encoders
 *---------------------------------------------------------------------*/
void encoders_init()
{
    pinMode(ENCODERS_LATCH_PIN, OUTPUT);
    digitalWrite(ENCODERS_LATCH_PIN, HIGH);

}

/*---------------------------------------------------------------------*
 *  NAME
 *      encoders_update
 *
 *  DESCRIPTION
 *      Reads the current encoder state from the shift register
 *      WARNING: the display interrupt MUST be stopped
 *              before running this function
 *---------------------------------------------------------------------*/
void encoders_update(uint8_t state, encoder_state_t *encoders)
{
    static uint8_t enc_last = 0xFF;
    encoders->changed = false;
    if (state != enc_last)
    {
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            uint8_t bit_index = (i << 1);
            uint8_t mask = ENCODER_MASK << bit_index;
            uint8_t enc = state & mask;
            // Check if this encoder is different than last time
            // AND that the current state has both bits high
            if ((enc != (enc_last & mask)) && (enc == mask))
            {
                // Get the lower bit of the previous reading
                uint8_t dir = ((enc_last & (1 << bit_index)) >> bit_index);
                encoders->changed = true;
                encoders->encoder[ENCODER_INDEX[i]] = ENCODER_DIRECTION[dir];
            }
            else
            {
                encoders->encoder[ENCODER_INDEX[i]] = 0;
            }
        }
        enc_last = state;
    }
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/
/* None */
