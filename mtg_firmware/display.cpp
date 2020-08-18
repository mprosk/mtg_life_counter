#include "display.h"

////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void display_isr(void);

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Initialize the pins and interface used for driving the displays
 */
void display_init(void)
{
  pinMode(DISPLAY_DATA_PIN, OUTPUT);
  pinMode(DISPLAY_CLOCK_PIN, OUTPUT);
  pinMode(DISPLAY_LATCH_PIN, OUTPUT);
  pinMode(DISPLAY_NENABLE_PIN, OUTPUT);
  SPI.begin();
  SPI.beginTransaction(SPISettings(SPI_BUS_SPEED_HZ, LSBFIRST, SPI_MODE0));
}


/*
 * 
 */
void display_enable(void)
{
  // Enable the display
  digitalWrite(DISPLAY_NENABLE_PIN, LOW);

  // TODO: Attach timer interrupt
}
 
/*
 * Disables the timer interrupts and blanks the display
 */
void display_disable(void)
{
  // TODO: Detach timer inerrupt
  
  // Blank the display
  digitalWrite(DISPLAY_NENABLE_PIN, HIGH);
}

////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Updates one multiplexed digit on the display
 * Segment Driver 1 --> Segment Driver 2 --> Digit Sink 1 --> Digit Sink 2
 */
void display_isr(void)
{
  static uint8_t index = 0;

  // Send the digit select mask to the sink chips
  for (uint8_t bank = 0; bank < MATRIX_DEPTH; bank++)
  {
    SPI.transfer(1 << index);
  }

  // Send the segment data (reverse order)
  for (uint8_t bank = MATRIX_DEPTH - 1; bank < MATRIX_DEPTH; bank--)
  {
    SPI.transfer(display_buffer[bank][index]);
  }
  
  // Strobe the latch line
  digitalWrite(DISPLAY_LATCH_PIN, HIGH);
  digitalWrite(DISPLAY_LATCH_PIN, LOW);

  // Increment the index
  index++;
  if (index >= MATRIX_WIDTH)
  {
    index = 0;
  }
}
