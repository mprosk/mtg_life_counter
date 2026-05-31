/***********************************************************************
 *  MTG Life Counter - Rotary Encoder Input
 *
 *  DESCRIPTION
 *      Reads encoder rotation and button state for each player
 *
 *  REFERENCES
 *      MTG Life Counter Schematic
 ***********************************************************************/

/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "encoders.h"
#include "display.h"
#include "pins.h"
#include <SPI.h>

/*=====================================================================*
    Private Defines
 *=====================================================================*/
#define ENCODER_MASK (0x2)

/*=====================================================================*
    Private Data
 *=====================================================================*/
static const uint8_t ENCODER_INDEX[PLAYER_COUNT] = {2, 3, 0, 1};
static const int8_t ENCODER_DIRECTION[2] = {1, -1};

static const uint8_t ENCODER_BUTTON_PINS[PLAYER_COUNT] = {
    ENCODERS_BTN_1, ENCODERS_BTN_2, ENCODERS_BTN_3, ENCODERS_BTN_4};

/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
static void encoders_update(uint8_t state, encoder_state_t* encoders);

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
void encoders_init(void) {
    pinMode(ENCODERS_LATCH_PIN, OUTPUT);
    digitalWrite(ENCODERS_LATCH_PIN, HIGH);

    for (uint8_t i = 0; i < PLAYER_COUNT; i++) {
        pinMode(ENCODER_BUTTON_PINS[i], INPUT_PULLUP);
    }
}

/*---------------------------------------------------------------------*
 *  NAME
 *      encoders_poll
 *
 *  DESCRIPTION
 *      Reads encoder shift-register state over SPI and decodes changes
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void encoders_poll(encoder_state_t* encoders) {
    // Stop the display interrupt before using the shared SPI bus
    display_stop();

    // Read the current encoder state
    digitalWrite(ENCODERS_LATCH_PIN, LOW);
    digitalWrite(ENCODERS_LATCH_PIN, HIGH);
    uint8_t state = SPI.transfer(0);

    // Restart the display interrupt
    display_start();

    encoders_update(state, encoders);
}

/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      encoders_update
 *
 *  DESCRIPTION
 *      Decodes a raw shift-register reading into per-player deltas
 *      and button states
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
static void encoders_update(uint8_t state, encoder_state_t* encoders) {
    static uint8_t enc_last = 0xFF;

    encoders->changed = false;
    for (uint8_t i = 0; i < PLAYER_COUNT; i++) {
        uint8_t bit_index = (i << 1);
        uint8_t mask = ENCODER_MASK << bit_index;
        uint8_t enc = state & mask;

        // Check if this encoder is different than last time
        // AND that the current state has both bits high
        if ((enc != (enc_last & mask)) && (enc == mask)) {
            // Get the lower bit of the previous reading
            uint8_t dir = ((enc_last & (1 << bit_index)) >> bit_index);
            encoders->changed = true;
            encoders->encoder[ENCODER_INDEX[i]] = ENCODER_DIRECTION[dir];
        } else {
            encoders->encoder[ENCODER_INDEX[i]] = 0;
        }

        // Read the button state (low = pressed)
        encoders->button[i] = digitalRead(ENCODER_BUTTON_PINS[i]);
    }
    enc_last = state;
}
