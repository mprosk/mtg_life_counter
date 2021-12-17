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


/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "display.h"


/*=====================================================================*
    Private Data
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      display_buffer
 *
 *  DESCRIPTION
 *      Pin number of the SPI MOSI line
 *---------------------------------------------------------------------*/
static volatile uint8_t display_buffer[PLAYER_COUNT][DISPLAY_WIDTH];


/*=====================================================================*
    Public Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      display_init
 *
 *  DESCRIPTION
 *      Initializes the display hardware
 *      Sets GPIO pin modes
 *      Starts the SPI bus
 *      Configures (but does not start) the timer interrupt
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_init(void)
{
    // Set pin modes
    pinMode(DISPLAY_DATA_PIN, OUTPUT);
    pinMode(DISPLAY_CLOCK_PIN, OUTPUT);
    pinMode(DISPLAY_LATCH_PIN, OUTPUT);

    // Start SPI bus
    SPI.begin();
    SPI.beginTransaction(SPISettings(DISPLAY_SPI_CLK_HZ, LSBFIRST, SPI_MODE0));

    // Initialize timer1 (16-bit)
    TCCR1A = 0;   // set entire TCCR1A register to 0
    TCCR1B = 0;   // same for TCCR1B
    TCNT1  = 0;   //initialize counter value to 0
    // set compare match register for desired increment
    OCR1A = 4999;// = (16MHz) / (400Hz * 8 prescale) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS11 bit for 8 prescaler
    TCCR1B |=  (1 << CS11);
}

/*---------------------------------------------------------------------*
 *  NAME
 *      display_start
 *
 *  DESCRIPTION
 *      Enables the display update interrupt
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_start(void)
{
    // Enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
}

/*---------------------------------------------------------------------*
 *  NAME
 *      display_stop
 *
 *  DESCRIPTION
 *      Disables the display update interrupt
 * 
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void display_stop(void)
{
    // Disable timer compare interrupt
    TIMSK1 &= ~(1 << OCIE1A);
}

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
void display_set_int(uint8_t player_id, int16_t integer)
{
    // Clear buffer
    for (uint8_t i = 0; i < DISPLAY_WIDTH; i++)
    {
        display_buffer[player_id][i] = SEG[' '];
    }

    // Set each place
    uint16_t mag = abs(integer);
    uint16_t divisor = 1;
    uint8_t pos = DISPLAY_WIDTH - 1;
    do
    {
        display_buffer[player_id][pos] = SEG[(mag / divisor) % 10];
        divisor *= 10;
        pos--;
    }
    while(mag >= divisor);
    
    // Add minus sign if applicable
    if ((integer < 0) && (pos < DISPLAY_WIDTH))
    {
        display_buffer[player_id][pos] = SEG['-'];
    }
}

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
void display_set_string(uint8_t player_id, uint8_t *text)
{
    for (uint8_t i = 0; i < DISPLAY_WIDTH; i++)
    {
        display_buffer[player_id][i] = SEG[text[i]];
    }
}

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
void display_set_digit(uint8_t player_id, uint8_t pos, uint8_t pattern)
{
    display_buffer[player_id][pos] = pattern;
}

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
void display_set_char(uint8_t player_id, uint8_t pos, uint8_t chr)
{
    display_set_digit(player_id, pos, SEG[chr]);
}

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
void display_fill_pattern(uint8_t player_id, uint8_t pattern)
{
    for (uint8_t i = 0; i < DISPLAY_WIDTH; i++)
    {
        display_buffer[player_id][i] = pattern;
    }
}

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
void display_fill(uint8_t player_id, uint8_t chr)
{
    display_fill_pattern(player_id, SEG[chr]);
}

/*=====================================================================*
    Interrupt Service Routines
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      TIMER1_COMPA ISR
 *
 *  DESCRIPTION
 *      Updates a single multiplexed column on the display
 *      Segment Driver 1 --> Segment Driver 2 --> Digit Sink 1 --> Digit Sink 2
 *
 *  DURATION
 *      40 us
 * 
 *  FREQUENCY
 *      1600 Hz
 *---------------------------------------------------------------------*/
ISR(TIMER1_COMPA_vect)
{
    static uint8_t index = 0;

    // Send the digit select mask to the two current sink chips
    SPI.transfer(0x88 >> (index));
    SPI.transfer(0x88 >> (index));

    // Send the segment data (reverse order)
    for (uint8_t bank = PLAYER_COUNT - 1; bank < PLAYER_COUNT; bank--)
    {
        SPI.transfer(display_buffer[bank][index % DISPLAY_WIDTH]);
    }
    
    // Strobe the latch line
    digitalWrite(DISPLAY_LATCH_PIN, HIGH);
    digitalWrite(DISPLAY_LATCH_PIN, LOW);

    // Increment the index
    index = (index + 1) % DISPLAY_WIDTH;
}
