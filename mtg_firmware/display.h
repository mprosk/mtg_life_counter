/*
 * Zero-life messages
 * OUCH
 * OOF
 * GG
 * rIP
 * dEAd
 * F
 * Srry
 * byE
 * diEd
 * bOOP
 * dEd
 * 
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <arduino.h>
#include <SPI.h>
#include "config.h"
#include "sevenseg.h"

////////////////////////////////////////////////////////////////////////////////
// DEFINES
////////////////////////////////////////////////////////////////////////////////
/* PINS */
#define DISPLAY_DATA_PIN    (11)
#define DISPLAY_CLOCK_PIN   (13)
#define DISPLAY_LATCH_PIN   (9)
#define DISPLAY_NENABLE_PIN (8)     // Enable displays. ACTIVE LOW
/* CONFIG */
#define SPI_BUS_SPEED_HZ    (1e6)   // Speed in Hertz of the SPI bus
#define MATRIX_DEPTH        (2)     // Nnumber of multiplexed groups
#define MATRIX_WIDTH        (8)     // Number of digits in each multiplexed group
#define PLAYERS_PER_BANK    (MATRIX_WIDTH / PLAYER_COUNT)     // Number of player displays in each multiplexed group
#define DISPLAY_MAX         (pow(10, DISPLAY_WIDTH) - 1)
#define DISPLAY_MIN         (-pow(10, DISPLAY_WIDTH - 1) + 1)

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void display_init(void);
void display_enable(void);
void display_disable(void);
void display_set_int(uint8_t player, int16_t value);
void display_set_digit(uint8_t player, uint8_t pos, uint8_t chr);
void display_fill(uint8_t player, uint8_t fill_char);

#endif /* _DISPLAY_H_ */
