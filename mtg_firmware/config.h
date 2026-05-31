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
#include "Arduino.h"

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
#define PLAYER_COUNT (4)

/*---------------------------------------------------------------------*
 *  NAME
 *      COMMANDER_DAMAGE
 *
 *  DESCRIPTION
 *      Maximum amount of commander damage a player can receive
 *---------------------------------------------------------------------*/
#define COMMANDER_DAMAGE (21)

/*---------------------------------------------------------------------*
 *  NAME
 *      POISON_COUNTERS
 *
 *  DESCRIPTION
 *      Maximum amount of poison counters a player can receive
 *---------------------------------------------------------------------*/
#define POISON_COUNTERS (10)

/*---------------------------------------------------------------------*
 *  NAME
 *      LIFE_CHANGE_DURATION_MS
 *
 *  DESCRIPTION
 *      Time in ms that the change in life total will be displayed
 *---------------------------------------------------------------------*/
#define LIFE_CHANGE_DURATION_MS (1000)

/*=====================================================================*
    Public Constants
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      STARTING_LIFE
 *
 *  DESCRIPTION
 *      Starting life totals for the different gamemodes
 *---------------------------------------------------------------------*/
extern const int16_t STARTING_LIFE[3];

/*---------------------------------------------------------------------*
 *  NAME
 *      CMDR_DMG_MAP
 *
 *  DESCRIPTION
 *      Contains the DIRECTION index that points from a given player
 *      to another given player. Adjusted to use the commander damage index
 *
 *      Input = Player index FROM, Commander damage index TO; Output = DIRECTION
 * index
 *---------------------------------------------------------------------*/
extern const uint8_t CMDR_DMG_MAP[PLAYER_COUNT][PLAYER_COUNT];

#endif /* !defined(INC_CONFIG_H) */
