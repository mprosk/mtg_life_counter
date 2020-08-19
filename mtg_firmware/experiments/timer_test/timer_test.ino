
#define PIN   (4)

void setup() {

  pinMode(PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(PIN, HIGH);
  // Initialize timer1 (16-bit)
  TCCR1A = 0;   // set entire TCCR1A register to 0
  TCCR1B = 0;   // same for TCCR1B
  TCNT1  = 0;   //initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 624;// = (16MHz) / (120Hz * 256 prescale) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 bit for 256 prescaler
  TCCR1B |=  (1 << CS12);

  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(PIN, HIGH);
  delay(1);
  digitalWrite(PIN, LOW);
}
