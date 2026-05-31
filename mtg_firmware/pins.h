/***********************************************************************
 *  MTG Life Counter - Pin Assignments
 *
 *  DESCRIPTION
 *      GPIO assignments for all board peripherals
 ***********************************************************************/

#if !defined(INC_PINS_H)
#define INC_PINS_H

/* Debug */
#define PIN_DEBUG_1 (4)
#define PIN_DEBUG_2 (6)

/* System controls */
#define PIN_MODE_SWITCH (9)
#define PIN_RESET_BTN   (8)
#define PIN_ROLL_BTN    (7)

/* Rotary encoders (shift register + per-player buttons) */
#define ENCODERS_LATCH_PIN (3)
#define ENCODERS_BTN_1     (A5)
#define ENCODERS_BTN_2     (A2)
#define ENCODERS_BTN_3     (5)
#define ENCODERS_BTN_4     (2)

/* Display (SPI shift registers) */
#define DISPLAY_DATA_PIN  (11)
#define DISPLAY_MISO_PIN  (12)
#define DISPLAY_CLOCK_PIN (13)
#define DISPLAY_LATCH_PIN (10)

#endif /* !defined(INC_PINS_H) */
