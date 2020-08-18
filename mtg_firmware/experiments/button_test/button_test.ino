

void setup() {
  // initialize the digital pin as an output.
  pinMode(A5, OUTPUT);
}

void loop() {
  digitalWrite(A5, HIGH);
  delay(250);
  digitalWrite(A5, LOW);
  delay(250);
}
