/***********************************************************************
 *  MTG Life Counter - Configuration and Constants
 *
 *  DESCRIPTION
 *      Definitions for general configuration values and lookup tables
 ***********************************************************************/

#include "config.h"

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
const int16_t STARTING_LIFE[3] = {20, 40, 30};

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
const uint8_t CMDR_DMG_MAP[PLAYER_COUNT][PLAYER_COUNT] = {
    {3, 0, 1, 2},
    {0, 1, 2, 3},
    {3, 0, 1, 2},
    {0, 1, 2, 3},
};
