/***********************************************************************
 *  MTG Life Counter - Roll Animations
 *
 *  DESCRIPTION
 *      Contains look-up-tables for the animations to display during a roll
 *
 *   _a_
 * f|   |b
 * 	|_g_|
 * e|   |c
 *  |___|
 *    d
 *
 ***********************************************************************/

#if !defined(INC_ANIMATIONS_H)
#define INC_ANIMATIONS_H

#include <stdint.h>

/*=====================================================================*
    Public Defines
 *=====================================================================*/
#define ANIMATION_COUNT (8)

/*=====================================================================*
    Public Data
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      ANIMATION_LENGTH
 *
 *  DESCRIPTION
 *      Array listing the number of keyframes in each animation
 *---------------------------------------------------------------------*/
extern const uint8_t ANIMATION_LENGTH[ANIMATION_COUNT];

/*---------------------------------------------------------------------*
 *  NAME
 *      ANIMATIONS
 *
 *  DESCRIPTION
 *      Array containing the keyframes of all animation sequences
 *---------------------------------------------------------------------*/
extern const uint8_t* const ANIMATIONS[ANIMATION_COUNT];

#endif /* !defined(INC_ANIMATIONS_H) */
