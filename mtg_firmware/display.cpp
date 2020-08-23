#include "display.h"

////////////////////////////////////////////////////////////////////////////////
// PRIVATE VARIABLE DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
volatile uint8_t display_buffer[PLAYER_COUNT][DISPLAY_WIDTH];

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Initialize the pins and interface used for driving the displays
 */
void display_init(void)
{
  // Set pin modes
  pinMode(DISPLAY_DATA_PIN, OUTPUT);
  pinMode(DISPLAY_CLOCK_PIN, OUTPUT);
  pinMode(DISPLAY_LATCH_PIN, OUTPUT);
  pinMode(DISPLAY_NENABLE_PIN, OUTPUT);
  digitalWrite(DISPLAY_NENABLE_PIN, HIGH);

  // Start SPI bus
  SPI.begin();
  SPI.beginTransaction(SPISettings(SPI_BUS_SPEED_HZ, LSBFIRST, SPI_MODE0));

  // Initialize timer1 (16-bit)
  TCCR1A = 0;   // set entire TCCR1A register to 0
  TCCR1B = 0;   // same for TCCR1B
  TCNT1  = 0;   //initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 1249;// = (16MHz) / (100Hz * 8 prescale) - 1 (must be <65536)
//  OCR1A = 2499;
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bit for 8 prescaler
  TCCR1B |=  (1 << CS11);
}

/*
 * Enables the timer interrupt and un-blanks the display
 */
void display_enable(void)
{
  // Enable the display
  digitalWrite(DISPLAY_NENABLE_PIN, LOW);

  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
}
 
/*
 * Disables the timer interrupts and blanks the display
 */
void display_disable(void)
{
  // Disable timer compare interrupt
  TIMSK1 &= ~(1 << OCIE1A);
  
  // Blank the display
  digitalWrite(DISPLAY_NENABLE_PIN, HIGH);
}

/*
 * Puts the display into a power-on state
 * Reenables the DIO and SPI pins and starts the refresh interrupt
 */
void display_power_on(void)
{
  // Restore pin modes
  pinMode(DISPLAY_DATA_PIN, OUTPUT);
  pinMode(DISPLAY_CLOCK_PIN, OUTPUT);
  pinMode(DISPLAY_LATCH_PIN, OUTPUT);
  pinMode(DISPLAY_NENABLE_PIN, OUTPUT);
  
  // Start SPI bus
  SPI.begin();
  SPI.beginTransaction(SPISettings(SPI_BUS_SPEED_HZ, LSBFIRST, SPI_MODE0));
  
  // Enable the display
  digitalWrite(DISPLAY_NENABLE_PIN, LOW);

  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
}

/*
 * Puts the display into a power-off state
 * Disables SPI bus and sets all DIO to floating inputs. Disables refresh interrupt
 */
void display_power_off(void)
{
  // Disable timer compare interrupt
  TIMSK1 &= ~(1 << OCIE1A);

  // Disable the SPI bus
  SPI.endTransaction();
  SPI.end();

  // Set any active-high lines to low
  digitalWrite(DISPLAY_NENABLE_PIN, LOW);
  digitalWrite(DISPLAY_DATA_PIN, LOW);

  pinMode(DISPLAY_DATA_PIN, INPUT);
  pinMode(DISPLAY_CLOCK_PIN, INPUT);
  pinMode(DISPLAY_LATCH_PIN, INPUT);
  pinMode(DISPLAY_NENABLE_PIN, INPUT);
}

/*
 * Sets the given player's display to an integer value
 */
void display_set_int(uint8_t player, int16_t value)
{
  // Clear buffer
  for (uint8_t i = 0; i < DISPLAY_WIDTH; i++)
  {
    display_buffer[player][i] = SEG[' '];
  }

  // Set each place
  uint16_t mag = abs(value);
  uint16_t divisor = 1;
  uint8_t pos = DISPLAY_WIDTH - 1;
  do{
    display_buffer[player][pos] = SEG[(mag / divisor) % 10];
    divisor *= 10;
    pos--;
  }while(mag >= divisor);
  
  // Add minus sign if applicable
  if ((value < 0) && (pos < DISPLAY_WIDTH))
  {
    display_buffer[player][pos] = SEG['-'];
  }
}

/*
 * Sets a specific digit within a given player's display to a pattern
 */
void display_set_digit(uint8_t player, uint8_t pos, uint8_t value)
{
  display_buffer[player][pos] = value;
}

/*
 * 
 */
void display_set_char(uint8_t player, uint8_t pos, uint8_t chr)
{
  display_set_digit(player, pos, SEG[chr]);
}

/*
 * 
 */
void display_set_string(uint8_t player, uint8_t* text)
{
  for (uint8_t i = 0; i < DISPLAY_WIDTH; i++)
  {
    display_buffer[player][i] = SEG[text[i]];
  }
}

/*
 * Fills an entire player display with the given raw pattern
 */
void display_fill_raw(uint8_t player, uint8_t fill_char)
{
  for (uint8_t i = 0; i < DISPLAY_WIDTH; i++)
  {
    display_buffer[player][i] = fill_char;
  }
}

/*
 * Fills an entire player display with the given character
 */
void display_fill(uint8_t player, uint8_t fill_char)
{
  display_fill_raw(player, SEG[fill_char]);
}

////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Updates one multiplexed digit on the display
 * Segment Driver 1 --> Segment Driver 2 --> Digit Sink 1 --> Digit Sink 2
 */
ISR(TIMER1_COMPA_vect)
{
  static uint8_t index = 0;

  // Send the digit select mask to the sink chips
  // This is a hack to get the display order to go clockwise around the board
  SPI.transfer(1 << (MATRIX_WIDTH - ((index + DISPLAY_WIDTH) % 8) - 1));
  SPI.transfer(1 << (MATRIX_WIDTH - index - 1));

  // Send the segment data (reverse order)
  for (uint8_t bank = MATRIX_DEPTH - 1; bank < MATRIX_DEPTH; bank--)
  {
    SPI.transfer(display_buffer[(bank * 2) + (index / DISPLAY_WIDTH)][index % DISPLAY_WIDTH]);
  }
  
  // Strobe the latch line
  digitalWrite(DISPLAY_LATCH_PIN, HIGH);
  digitalWrite(DISPLAY_LATCH_PIN, LOW);

  // Increment the index
  index = (index + 1) % MATRIX_WIDTH;
}
