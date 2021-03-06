/***********************************************************************
 *  MTG Life Counter - Matrixed 7-Segment Display Driver
 *
 *  DESCRIPTION
 *      Provides the driving capabilities and convenience functions
 *      for using a multiplexed array of 7-segment displays
 *
 *  REFERENCES
 *      TPIC6B595 Datasheet
 *      74x959 Datasheet
 *      MTG Life Counter Schematic
 ***********************************************************************/

#if !defined(INC_DISPLAY_H)
#define INC_DISPLAY_H

/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <arduino.h>
#include <SPI.h>
#include "config.h"
#include "sevenseg.h"

/*=====================================================================*
    Public Defines
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_DATA_PIN
 *
 *  DESCRIPTION
 *      Pin number of the SPI MOSI line
 *---------------------------------------------------------------------*/
#define DISPLAY_DATA_PIN    (11)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_CLOCK_PIN
 *
 *  DESCRIPTION
 *      Pin number of the SPI SCK (Clock) line
 *---------------------------------------------------------------------*/
#define DISPLAY_CLOCK_PIN   (13)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_LATCH_PIN
 *
 *  DESCRIPTION
 *      Pin number of the shift register IC latch line
 *---------------------------------------------------------------------*/
#define DISPLAY_LATCH_PIN   (9)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_NENABLE_PIN
 *
 *  DESCRIPTION
 *      Pin number of the shift register output enable line
 *      ACTIVE LOW
 *---------------------------------------------------------------------*/
#define DISPLAY_NENABLE_PIN (8)     // ACTIVE LOW

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_SPI_CLK_HZ
 *
 *  DESCRIPTION
 *      Clock speed in Hertz of the SPI bus driving the shift register ICs
 *---------------------------------------------------------------------*/
#define DISPLAY_SPI_CLK_HZ    (1e6)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_PLAYER_WIDTH
 *
 *  DESCRIPTION
 *      Number of digits on each player's display
 *---------------------------------------------------------------------*/
#define DISPLAY_PLAYER_WIDTH       (4)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_PLAYERS_PER_BANK
 *
 *  DESCRIPTION
 *      Number of player displays in each multiplexed group
 *---------------------------------------------------------------------*/
#define DISPLAY_PLAYERS_PER_BANK   (2)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_MATRIX_DEPTH
 *
 *  DESCRIPTION
 *      Number of multiplexed groups (banks)
 *---------------------------------------------------------------------*/
#define DISPLAY_MATRIX_DEPTH        (2)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_MATRIX_WIDTH
 *
 *  DESCRIPTION
 *      Number of digits in each multiplexed group
 *---------------------------------------------------------------------*/
#define DISPLAY_MATRIX_WIDTH        (DISPLAY_PLAYER_WIDTH * DISPLAY_PLAYERS_PER_BANK)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_MAX
 *
 *  DESCRIPTION
 *      Maximum integer value that the counter can display
 *---------------------------------------------------------------------*/
#define DISPLAY_MAX         (pow(10, DISPLAY_PLAYER_WIDTH) - 1)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_MIN
 *
 *  DESCRIPTION
 *      Minimum integer value that the counter can display
 *---------------------------------------------------------------------*/
#define DISPLAY_MIN         (-pow(10, DISPLAY_MATRIX_WIDTH - 1) + 1)

/*=====================================================================*
    Public Functions
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      display_init
 *
 *  DESCRIPTION
 *      Initializes the display hardware
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_init(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_blank
 *
 *  DESCRIPTION
 *      Blanks or unblanks the display
 *      'blank_enable' = 0: un-blanks the display
 *      'blank_enable' = 0: blanks the display
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_blank(bool blank_enable);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_start
 *
 *  DESCRIPTION
 *      Starts the display updates and puts it into a power-on state
 *      Enables SPI bus and sets all DIO to outputs.
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_start(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_stop
 *
 *  DESCRIPTION
 *      Stops the display from updating and puts it into a power-off state
 *      Disables SPI bus and sets all DIO to floating inputs.
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_stop(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_set_int
 *
 *  DESCRIPTION
 *      Sets the given player's display to an integer value
 *      Must be between DISPLAY_MIN and DISPLAY_MAX, inclusive
 *      uint8_t player: index of the player display to update
 *      int16_t value: integer value to show on the display
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_set_int(uint8_t player_id, int16_t integer);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_set_string
 *
 *  DESCRIPTION
 *      Sets the given player's display to the given character array
 *      uint8_t player: index of the player display to update
 *      uint8_t *text: pointer to the character array to display
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_set_string(uint8_t player_id, uint8_t *text);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_set_digit
 *
 *  DESCRIPTION
 *      Sets a specific digit within a given player's display to 
 *      the given seven-sgement pattern
 *      uint8_t player: index of the player display to update
 *      uint8_t pos: index of the digit to update
 *      int16_t pattern: binary seven-segment pattern to display
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_set_digit(uint8_t player_id, uint8_t pos, uint8_t pattern);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_set_char
 *
 *  DESCRIPTION
 *      Sets a specific digit within a given player's display to 
 *      the given character
 *      uint8_t player: index of the player display to update
 *      uint8_t pos: index of the digit to update
 *      int16_t chr: the character to display in the digit
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_set_char(uint8_t player_id, uint8_t pos, uint8_t chr);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_fill
 *
 *  DESCRIPTION
 *      Fills all positions of the given player's display
 *      with the given character
 *      uint8_t player: index of the player display to update
 *      uint8_t chr: character to fill display
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_fill(uint8_t player_id, uint8_t fill_char);

/*---------------------------------------------------------------------*
 *  NAME
 *      display_fill_pattern
 *
 *  DESCRIPTION
 *      Fills all positions of the given player's display
 *      with the given seven-segment pattern
 *      uint8_t player: index of the player display to update
 *      uint8_t pattern: binary seven-segment pattern to display
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_fill_pattern(uint8_t player_id, uint8_t pattern);


#endif /* !defined(INC_DISPLAY_H) */
