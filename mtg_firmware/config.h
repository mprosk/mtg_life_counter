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
    Public Defines
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      PLAYER_COUNT
 *
 *  DESCRIPTION
 *      Number of players the counter supports
 *---------------------------------------------------------------------*/
#define PLAYER_COUNT        (4)

/*---------------------------------------------------------------------*
 *  NAME
 *      PLAYER COUNT
 *
 *  DESCRIPTION
 *      Number of players
 *---------------------------------------------------------------------*/
#define BUTTON_COUNT	    (PLAYER_COUNT * 2)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_WIDTH
 *
 *  DESCRIPTION
 *      Number of digits on each player's display
 *---------------------------------------------------------------------*/
#define DISPLAY_WIDTH       (4)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_MAX
 *
 *  DESCRIPTION
 *      Maximum integer value that the counter can display
 *---------------------------------------------------------------------*/
#define DISPLAY_MAX         (pow(10, DISPLAY_WIDTH) - 1)

/*---------------------------------------------------------------------*
 *  NAME
 *      DISPLAY_MIN
 *
 *  DESCRIPTION
 *      Minimum integer value that the counter can display
 *---------------------------------------------------------------------*/
#define DISPLAY_MIN         (-pow(10, DISPLAY_WIDTH - 1) + 1)

/*---------------------------------------------------------------------*
 *  NAME
 *      COMMANDER_DAMAGE
 *
 *  DESCRIPTION
 *      Maximum amount of commander damage a player can receive
 *---------------------------------------------------------------------*/
#define COMMANDER_DAMAGE          (21)

/*---------------------------------------------------------------------*
 *  NAME
 *      POISON_COUNTERS
 *
 *  DESCRIPTION
 *      Maximum amount of poison counters a player can receive
 *---------------------------------------------------------------------*/
#define POISON_COUNTERS           (10)

/*---------------------------------------------------------------------*
 *  NAME
 *      ANIMATION_SPEED_MS
 *
 *  DESCRIPTION
 *      Delay in ms between frames of the roll animations
 *---------------------------------------------------------------------*/
#define ANIMATION_SPEED_MS        (50)

/*---------------------------------------------------------------------*
 *  NAME
 *      ROLL_RESULT_DURATION_MS
 *
 *  DESCRIPTION
 *      Time in ms that the roll result will be displayed
 *---------------------------------------------------------------------*/
#define ROLL_RESULT_DURATION_MS   (2000)    // Time in ms that the roll result will be displayed

/*---------------------------------------------------------------------*
 *  NAME
 *      LIFE_CHANGE_DURATION_MS
 *
 *  DESCRIPTION
 *      Time in ms that the change in life total will be displayed
 *---------------------------------------------------------------------*/
#define LIFE_CHANGE_DURATION_MS   (1000)


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
 *      LIFE_MODE_MIN        
 *
 *  DESCRIPTION
 *      The minimum possible counter value for each display mode
 *      Self, Cmdr 1, Cmdr 2, Cmdr 3, Poison
 *---------------------------------------------------------------------*/
static const int16_t LIFE_MODE_MIN[PLAYER_COUNT + 1] = {DISPLAY_MIN, 0, 0, 0, 0};

/*---------------------------------------------------------------------*
 *  NAME
 *      LIFE_MODE_MAX       
 *
 *  DESCRIPTION
 *      The maximum possible counter value for each display mode
 *      Self, Cmdr 1, Cmdr 2, Cmdr 3, Poison
 *---------------------------------------------------------------------*/
static const int16_t LIFE_MODE_MAX[PLAYER_COUNT + 1] = {
  DISPLAY_MAX, COMMANDER_DAMAGE, COMMANDER_DAMAGE, COMMANDER_DAMAGE, POISON_COUNTERS
};

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
 *      BUTTON_INCREMENT_MAPPING        
 *
 *  DESCRIPTION
 *      Indicates the change in life total a given button should incur
 *      Input = Button Index, Output = Increment amount
 *---------------------------------------------------------------------*/
static const int8_t BUTTON_INCREMENT_MAPPING[] = {1, -1, -1, 1, -1, 1, -1, 1};

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
 *      PLAYER_MAP        
 *
 *  DESCRIPTION
 *      Contains the DIRECTION index that points from a given player
 *      to another given player
 *      Input = Player index FROM, Player index TO; Output = DIRECTION index
 *---------------------------------------------------------------------*/
static const uint8_t PLAYER_MAP[PLAYER_COUNT][PLAYER_COUNT] = {
    {2, 3, 0, 1},
    {2, 3, 0, 1},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
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

static const uint8_t ROLL_TEXT[][PLAYER_COUNT] = {
    "PLAY", " GO ", " YOU", " YES", "GLHF"
};

static const uint8_t DEATH_TEXT[][PLAYER_COUNT] = {
    "OUCH", " OOF", " GG ", " RIP", "DEAD", "DIED", "  F ", "SRRY", " BYE", "BOOP", " DED", "LOSE"
};


#endif /* !defined(INC_CONFIG_H) */
