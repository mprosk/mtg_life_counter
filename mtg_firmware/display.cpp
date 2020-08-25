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
static volatile uint8_t display_buffer[PLAYER_COUNT][DISPLAY_PLAYER_WIDTH];

/*---------------------------------------------------------------------*
 *  NAME
 *      display_buffer
 *
 *  DESCRIPTION
 *      Indicates if the display is enabled
 *      0 = not enabled, others = enabled
 *---------------------------------------------------------------------*/
static uint8_t display_enabled = 0; 


/*=====================================================================*
    Public Function Implementations
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
void display_init(void)
{
    display_enabled = 0;

    // Initialize timer1 (16-bit)
    TCCR1A = 0;   // set entire TCCR1A register to 0
    TCCR1B = 0;   // same for TCCR1B
    TCNT1  = 0;   //initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 1249;// = (16MHz) / (1600Hz * 8 prescale) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS11 bit for 8 prescaler
    TCCR1B |=  (1 << CS11);
}

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
void display_blank(uint8_t blank_enable)
{
    if (display_enabled)
    {
        if (blank_enable)
        {
            // Disable timer compare interrupt
            TIMSK1 &= ~(1 << OCIE1A);
            // Blank the display
            digitalWrite(DISPLAY_NENABLE_PIN, HIGH);
        }
        else
        {
            // Enable the display
            digitalWrite(DISPLAY_NENABLE_PIN, LOW);
            // Enable timer compare interrupt
            TIMSK1 |= (1 << OCIE1A);
        }
    }
}

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
void display_start(void)
{
    display_enabled = 1;

    // Set pin modes
    pinMode(DISPLAY_DATA_PIN, OUTPUT);
    pinMode(DISPLAY_CLOCK_PIN, OUTPUT);
    pinMode(DISPLAY_LATCH_PIN, OUTPUT);
    pinMode(DISPLAY_NENABLE_PIN, OUTPUT);

    // Start SPI bus
    SPI.begin();
    SPI.beginTransaction(SPISettings(DISPLAY_SPI_CLK_HZ, LSBFIRST, SPI_MODE0));
    
    // Enable the display
    digitalWrite(DISPLAY_NENABLE_PIN, LOW);

    // Enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
}

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
void display_stop(void)
{
    // Disable timer compare interrupt
    TIMSK1 &= ~(1 << OCIE1A);

    // Disable the SPI bus
    SPI.endTransaction();
    SPI.end();

    // Set any active-high lines to low
    digitalWrite(DISPLAY_NENABLE_PIN, LOW);
    digitalWrite(DISPLAY_DATA_PIN, LOW);

    // Set pins to inputs
    pinMode(DISPLAY_DATA_PIN, INPUT);
    pinMode(DISPLAY_CLOCK_PIN, INPUT);
    pinMode(DISPLAY_LATCH_PIN, INPUT);
    pinMode(DISPLAY_NENABLE_PIN, INPUT);
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
void display_set_int(uint8_t player, int16_t integer)
{
    // Clear buffer
    for (uint8_t i = 0; i < DISPLAY_PLAYER_WIDTH; i++)
    {
        display_buffer[player][i] = SEG[' '];
    }

    // Set each place
    uint16_t mag = abs(integer);
    uint16_t divisor = 1;
    uint8_t pos = DISPLAY_PLAYER_WIDTH - 1;
    do
    {
        display_buffer[player][pos] = SEG[(mag / divisor) % 10];
        divisor *= 10;
        pos--;
    }
    while(mag >= divisor);
    
    // Add minus sign if applicable
    if ((integer < 0) && (pos < DISPLAY_PLAYER_WIDTH))
    {
        display_buffer[player][pos] = SEG['-'];
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
void display_set_string(uint8_t player, uint8_t *text)
{
  for (uint8_t i = 0; i < DISPLAY_PLAYER_WIDTH; i++)
  {
    display_buffer[player][i] = SEG[text[i]];
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
void display_set_digit(uint8_t player, uint8_t pos, uint8_t pattern)
{
  display_buffer[player][pos] = pattern;
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
void display_set_char(uint8_t player, uint8_t pos, uint8_t chr)
{
  display_set_digit(player, pos, SEG[chr]);
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
void display_fill_pattern(uint8_t player, uint8_t pattern)
{
  for (uint8_t i = 0; i < DISPLAY_PLAYER_WIDTH; i++)
  {
    display_buffer[player][i] = pattern;
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
void display_fill(uint8_t player, uint8_t chr)
{
  display_fill_pattern(player, SEG[chr]);
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
 *      <<TODO>>
 * 
 *  FREQUENCY
 *      1600 Hz
 *---------------------------------------------------------------------*/
ISR(TIMER1_COMPA_vect)
{
    static uint8_t index = 0;

    // Send the digit select mask to the sink chips
    // This is a hack to get the display order to go clockwise around the board
    SPI.transfer(1 << (DISPLAY_MATRIX_WIDTH - ((index + DISPLAY_PLAYER_WIDTH) % 8) - 1));
    SPI.transfer(1 << (DISPLAY_MATRIX_WIDTH - index - 1));

    // Send the segment data (reverse order)
    for (uint8_t bank = DISPLAY_MATRIX_DEPTH - 1; bank < DISPLAY_MATRIX_DEPTH; bank--)
    {
        SPI.transfer(display_buffer[(bank * 2) + (index / DISPLAY_PLAYER_WIDTH)][index % DISPLAY_PLAYER_WIDTH]);
    }
    
    // Strobe the latch line
    digitalWrite(DISPLAY_LATCH_PIN, HIGH);
    digitalWrite(DISPLAY_LATCH_PIN, LOW);

    // Increment the index
    index = (index + 1) % DISPLAY_MATRIX_WIDTH;
}
