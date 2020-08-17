void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint32_t count = 0;
  float data[4] = {0, 0, 0, 0};
  while(1)
  {
    data[analogRead(A5) % 4]++;
    count ++;
    for (uint8_t i = 0; i < 4; i++)
    {
      Serial.print(data[i] / count);
      Serial.print(" ");
    }
    Serial.println();
  }
}
