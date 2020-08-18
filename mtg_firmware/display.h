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

////////////////////////////////////////////////////////////////////////////////
// DEFINES
////////////////////////////////////////////////////////////////////////////////
/* PINS */
#define DISPLAY_DATA_PIN    (11)
#define DISPLAY_CLOCK_PIN   (13)
#define DISPLAY_LATCH_PIN   (9)
#define DISPLAY_NENABLE_PIN (8)     // Enable displays. ACTIVE LOW
/* CONFIG */
#define MATRIX_WIDTH        (8)     // Number of digits on one multiplexed group
#define MATRIX_DEPTH        (2)      // Number of multiplexed groups
#define REFRESH_RATE_HZ     (100)   // Digit muxing update rate
#define SPI_BUS_SPEED_HZ    (1e6)   // Speed in Hertz of the SPI bus

////////////////////////////////////////////////////////////////////////////////
// PUBLIC VARIABLE DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
extern volatile uint8_t display_buffer[MATRIX_DEPTH][MATRIX_WIDTH];

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void display_init(void);
void display_enable(void);
void display_disable(void);

#endif /* _DISPLAY_H_ */
