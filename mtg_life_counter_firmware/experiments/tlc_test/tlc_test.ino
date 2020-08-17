#include <SPI.h>

#define PIN_TLC_DATA_OUT    (11)    // Serial data in to TLC
#define PIN_TLC_CLOCK       (13)    // Serial data clock. Latched on rising edge
#define PIN_TLC_LATCH       (6)     // Lock in serial data to outputs

void tlc_putchar(uint8_t v)
{
  SPI.transfer(v);
  digitalWrite(PIN_TLC_LATCH, HIGH);
  digitalWrite(PIN_TLC_LATCH, LOW);
}

void setup() {
  pinMode(PIN_TLC_DATA_OUT, OUTPUT);
  pinMode(PIN_TLC_CLOCK, OUTPUT);
  pinMode(PIN_TLC_LATCH, OUTPUT);
  digitalWrite(PIN_TLC_LATCH, LOW);
  
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, LSBFIRST, SPI_MODE0));
}

void loop() {

  tlc_putchar(0xFF);
  
  while(1){};
}
