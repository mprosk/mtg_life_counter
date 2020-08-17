/*
 * 
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  uint8_t count = 0;
  
  // main loop
  while (1)
  {
    if(digitalRead(A0) == 0)
    {
      delay(5);
      digitalWrite(13, HIGH);
      while(digitalRead(A0) == 0)
      {
        count++;
        digitalWrite(2, count == 0);
      }
      digitalWrite(13, LOW);
//      Serial.print(count);
//      Serial.print(" ");
      Serial.println(count % 4);
      delay(100);
    }

    
  }
}
