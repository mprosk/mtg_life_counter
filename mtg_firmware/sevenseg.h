/***********************************************************************
 *  Seven Segment Display Table
 *
 *  DESCRIPTION
 *      Look-up-table containing the bit patterns for displaying
 *      certain characters on a 7-segment display. This table uses
 *      a high bit to indicate that the segment is illuminated.
 *
 *      The table can be indexed by ASCII value for displaying text,
 *      or by numeric value (0-16).
 *
 *      Characters that cannot be displayed on a 7-segment display
 *      will be blank.
 *
 *      A ~ next to an entry in the table indicates that the displayed
 *      symbol is not immediately recongizable as the desried character
 *
 *   _a_
 * f|   |b
 *	|_g_|
 * e|   |c
 *  |___|
 *    d
 *  _       _   _       _   _   _   _   _
 * | |   |  _|  _| |_| |_  |_    | |_| |_|
 * |_|   | |_   _|   |  _| |_|   | |_|   |
 *
 *      https://jasonacox.github.io/TM1637TinyDisplay/examples/7-segment-animator.html
 *
 ***********************************************************************/

#if !defined(INC_SEVENSEG_H)
#define INC_SEVENSEG_H

#include <stdint.h>

/*=====================================================================*
    Public Data
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      SEG
 *
 *  DESCRIPTION
 *      Seven-segment patterns indexed by ASCII character value
 *---------------------------------------------------------------------*/
extern const uint8_t SEG[];

/*---------------------------------------------------------------------*
 *  NAME
 *      DIRECTION
 *
 *  DESCRIPTION
 *      Contains the 7-segment display pattern that points to the given
 * direction
 *---------------------------------------------------------------------*/
extern const uint8_t DIRECTION[4];

#endif /* !defined(INC_SEVENSEG_H) */
