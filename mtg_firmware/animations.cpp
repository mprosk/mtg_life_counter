/***********************************************************************
 *  MTG Life Counter - Roll Animations
 *
 *  DESCRIPTION
 *      Contains look-up-tables for the animations to display during a roll
 **********************************************************************/

#include "animations.h"
#include <Arduino.h>

/*=====================================================================*
    Private Data - Animation Frames
 *=====================================================================*/

static const uint8_t TWO_SEG_SPIN[] = {
    B11000000,
    B01100000,
    B00110000,
    B00011000,
    B00001100,
    B10000100,
};

static const uint8_t FIGURE_EIGHT[] = {
    B10000000,
    B01000000,
    B00000010,
    B00001000,
    B00010000,
    B00100000,
    B00000010,
    B00000100,
};

static const uint8_t BOUNCE[] = {
    B10000000,
    B01000100,
    B00101000,
    B00010000,
    B01000100,
    B00101000,
};

static const uint8_t SPIN[] = {
    B10000000,
    B01000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
};

static const uint8_t OPPOSITE[] = {
    B10010000,
    B01001000,
    B00100100,
};

static const uint8_t NEGATIVE_SPIN[] = {
    B01111100,
    B10111100,
    B11011100,
    B11101100,
    B11110100,
    B11111000,
};

static const uint8_t DASH[] = {
    B00000010,
    B00000000,
    B00000000,
    B00000000,
};

static const uint8_t UPDOWN[] = {
    B10000000,
    B00000010,
    B00010000,
    B00000010,
};

/*=====================================================================*
    Public Data
 *=====================================================================*/

const uint8_t ANIMATION_LENGTH[ANIMATION_COUNT] = {6, 8, 6, 6, 3, 6, 4, 4};

const uint8_t* const ANIMATIONS[ANIMATION_COUNT] = {
    TWO_SEG_SPIN,
    FIGURE_EIGHT,
    BOUNCE,
    SPIN,
    OPPOSITE,
    NEGATIVE_SPIN,
    DASH,
    UPDOWN,
};
