#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

/*
 * 	 _a_
 * f|   |b
 * 	|_g_|
 * e|   |c
 *  |___|
 *    d
 */

#define ANIMATION_COUNT		(8)

static const uint8_t DIRECTION[4] = {
  B10000100,  // Upper Left
  B11000000,  // Upper Right
  B00110000,  // Lower Right
  B00011000,  // Lower Left
};

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

/*
 * Array listing the number of keyframes in each animation
 */
static const uint8_t ANIMATION_LENGTH[ANIMATION_COUNT] = {
  6, 8, 6, 6, 3, 6, 4, 4
};

/* 
 * List of the animations
 */
static const uint8_t* ANIMATIONS[ANIMATION_COUNT] = {
  TWO_SEG_SPIN,
  FIGURE_EIGHT,
  BOUNCE,
  SPIN,
  OPPOSITE,
  NEGATIVE_SPIN,
  DASH,
  UPDOWN,
};


#endif /* _ANIMATIONS_H_ */
