void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint16_t c = 0;
  Serial.println(c);
  delay(1000);
}
