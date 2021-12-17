/***********************************************************************
 *  MTG Life Counter - Configuration and Constants
 *
 *  DESCRIPTION
 *      Contains general configuration values and
 *      implementation-specific constants
 ***********************************************************************/

#if !defined(INC_CONFIG_H)
#define INC_CONFIG_H

/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <arduino.h>


/*=====================================================================*
    Public Pin Assignments
 *=====================================================================*/
#define PIN_DEBUG_1       (4)
#define PIN_DEBUG_2       (5)


/*=====================================================================*
    Public Defines
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      PLAYER_COUNT
 *
 *  DESCRIPTION
 *      Number of players the counter supports
 *---------------------------------------------------------------------*/
#define PLAYER_COUNT                (4)

/*---------------------------------------------------------------------*
 *  NAME
 *      BUTTONS_PER_PLAYER
 *
 *  DESCRIPTION
 *      Number of buttons each player has
 *---------------------------------------------------------------------*/
#define BUTTONS_PER_PLAYER          (2)

/*---------------------------------------------------------------------*
 *  NAME
 *      BUTTON_COUNT
 *
 *  DESCRIPTION
 *      Number of players
 *---------------------------------------------------------------------*/
#define BUTTON_COUNT	            (PLAYER_COUNT * BUTTONS_PER_PLAYER)

/*---------------------------------------------------------------------*
 *  NAME
 *      COMMANDER_DAMAGE
 *
 *  DESCRIPTION
 *      Maximum amount of commander damage a player can receive
 *---------------------------------------------------------------------*/
#define COMMANDER_DAMAGE            (21)

/*---------------------------------------------------------------------*
 *  NAME
 *      POISON_COUNTERS
 *
 *  DESCRIPTION
 *      Maximum amount of poison counters a player can receive
 *---------------------------------------------------------------------*/
#define POISON_COUNTERS             (10)

/*---------------------------------------------------------------------*
 *  NAME
 *      LIFE_CHANGE_DURATION_MS
 *
 *  DESCRIPTION
 *      Time in ms that the change in life total will be displayed
 *---------------------------------------------------------------------*/
#define LIFE_CHANGE_DURATION_MS     (1000)


/*=====================================================================*
    Public Data
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      STARTING_LIFE        
 *
 *  DESCRIPTION
 *      Starting life totals for the different gamemodes
 *---------------------------------------------------------------------*/
static const int16_t STARTING_LIFE[3] = {20, 40, 30};

/*---------------------------------------------------------------------*
 *  NAME
 *      BUTTON_PLAYER_MAPPING        
 *
 *  DESCRIPTION
 *      Indicates which player a given button belongs to
 *      Input = Button Index, Output = Player Index
 *---------------------------------------------------------------------*/
static const uint8_t BUTTON_PLAYER_MAPPING[] = {2, 2, 3, 3, 0, 0, 1, 1};

/*---------------------------------------------------------------------*
 *  NAME
 *      BUTTON_DIRECTION_MAPPING        
 *
 *  DESCRIPTION
 *      Indicates the direction a given button refers to
 *      Input = Button Index, Output = Button direction (0 = down, 1 = up)
 *---------------------------------------------------------------------*/
static const int8_t BUTTON_DIRECTION_MAPPING[] = {1, 0, 0, 1, 0, 1, 0, 1};

/*---------------------------------------------------------------------*
 *  NAME
 *      BUTTON_INCREMENT        
 *
 *  DESCRIPTION
 *      Indicates the change in life total each player's button should incur
 *      Input = Player Button Index, Output = Button increment
 *---------------------------------------------------------------------*/
static const int8_t BUTTON_INCREMENT[] = {-1, 1};

/*---------------------------------------------------------------------*
 *  NAME
 *      SWITCH_PLAYER_MAPPING        
 *
 *  DESCRIPTION
 *      Indicates which player a given rotary switch belongs to
 *      Input = Switch Index, Output = Player Index
 *---------------------------------------------------------------------*/
static const uint8_t SWITCH_PLAYER_MAPPING[] = {1, 0, 3, 2};

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

/*---------------------------------------------------------------------*
 *  NAME
 *      CMDR_DMG_MAP        
 *
 *  DESCRIPTION
 *      Contains the DIRECTION index that points from a given player
 *      to another given player. Adjusted to use the commander damage index
 *      
 *      Input = Player index FROM, Commander damage index TO; Output = DIRECTION index
 *---------------------------------------------------------------------*/
static const uint8_t CMDR_DMG_MAP[PLAYER_COUNT][PLAYER_COUNT] = {
    {2, 1, 0, 3},
    {3, 0, 1, 2},
    {2, 1, 0, 3},
    {3, 0, 1, 2},
};

#endif /* !defined(INC_CONFIG_H) */
