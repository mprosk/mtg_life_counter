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

/*=====================================================================*
    Public Data
 *=====================================================================*/
static const uint8_t SEG[] = {
//   abcdefg.
    B11111100,	// 0:  0
    B01100000,	// 1:  1
    B11011010,	// 2:  2
    B11110010,	// 3:  3
    B01100110,	// 4:  4
    B10110110,	// 5:  5
    B10111110,	// 6:  6
    B11100000,	// 7:  7
    B11111110,	// 8:  8
    B11110110,	// 9:  9
    B11101110,  // 10: A
    B00111110,  // 11: B
    B10011100,  // 12: C
    B01111010,  // 13: D
    B10011110,  // 14: E
    B10001110,  // 15: F
    0,          // 16
    0,          // 17
    0,          // 18
    0,          // 19
    0,          // 20
    0,          // 21
    0,          // 22
    0,          // 23
    0,          // 24
    0,          // 25
    0,          // 26
    0,          // 27
    0,          // 28
    0,          // 29
    0,          // 30
    0,          // 31
    B00000000,  // 32: Space
    0,          // 33
    B01000100,  // 34: "
    0,          // 35
    0,          // 36
    0,          // 37
    0,          // 38
    B00000100,  // 39: '
    0,          // 40
    0,          // 41
    0,          // 42
    B01100010,  // 43: +
    B00001000,  // 44: , 
    B00000010,  // 45: -
    0,          // 46
    0,          // 47
    B11111100,  // 48: 0
    B01100000,  // 49: 1
    B11011010,  // 50: 2
    B11110010,  // 51: 3
    B01100110,  // 52: 4
    B10110110,  // 53: 5
    B10111110,  // 54: 6
    B11100000,  // 55: 7
    B11111110,  // 56: 8
    B11110110,  // 57: 9
    0,          // 58
    0,          // 59
    0,          // 60
    B00010010,  // 61: =
    0,          // 62
    0,          // 63
    0,          // 64
    B11101110,  // 65: A
    B00111110,  // 66: B
    B10011100,  // 67: C
    B01111010,  // 68: D
    B10011110,  // 69: E
    B10001110,  // 70: F
    B10111100,  // 71: G
    B01101110,  // 72: H
    B00001100,  // 73: I
    B01111000,  // 74: J
    B00000000,  // 75: K  N/A
    B00011100,  // 76: L
    B11001100,  // 77: M  (half)
    B00101010,  // 78: N
    B11111100,  // 79: O
    B11001110,  // 80: P
    B11011100,  // 81: Q
    B00001010,  // 82: R
    B10110110,  // 83: S
    B00011110,  // 84: T
    B01111100,  // 85: U
    B00110000,  // 86: V
    B00111100,  // 87: W  (half)
    B00000000,  // 88: X  N/A
    B01110110,  // 89: Y
    B10010010,  // 90: Z  ~
    B10011100,  // 91: [
    0,          // 92
    B11110000,  // 93: ]
    0,          // 94
    B00010000,  // 95: _
    0,          // 96
    0,          // 97: a
    0,          // 98: b
    0,          // 99: c
    0,          // 100: d
    0,          // 101: e
    0,          // 102: f
    0,          // 103: g
    0,          // 104: h
    0,          // 105: i
    0,          // 106: j
    0,          // 107: k
    0,          // 108: l
    B11100100,  // 109: m
    0,          // 110: n
    0,          // 111: o
    0,          // 112: p
    0,          // 113: q
    0,          // 114: r
    0,          // 115: s
    0,          // 116: t
    0,          // 117: u
    0,          // 118: v
    B01111000,  // 119: w
    0,          // 120: x
    0,          // 121: y
    0,          // 122: z
};

/*---------------------------------------------------------------------*
 *  NAME
 *      DIRECTION        
 *
 *  DESCRIPTION
 *      Contains the 7-segment display pattern that points to the given direction
 *---------------------------------------------------------------------*/
static const uint8_t DIRECTION[4] = {
    B10000100,  // 0: Upper Left
    B11000000,  // 1: Upper Right
    B00110000,  // 2: Lower Right
    B00011000,  // 3: Lower Left
};

#endif /* !defined(INC_SEVENSEG_H) */
