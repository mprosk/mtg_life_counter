#define RESET   (4)
#define ITERATIONS (1e6)
#define FUNC    micros

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {

  Serial.println("------------");
  
  uint8_t count = 0;
  Serial.print("IF: "); Serial.flush();
  uint32_t start_time = FUNC();
  for (uint32_t i = 0; i < ITERATIONS; i++)
  {
    count++;
    if (count >= RESET)
    {
      count = 0;
    }
  }
  uint32_t end_time = FUNC() - start_time; 
  Serial.println(end_time);


  count = 0;
  Serial.print("MOD: "); Serial.flush();
  start_time = FUNC();
  for (uint32_t i = 0; i < ITERATIONS; i++)
  {
    count = (count + 1) % RESET;
  }
  end_time = FUNC() - start_time; 
  Serial.println(end_time);

  count = 0;
  Serial.print("MASK: "); Serial.flush();
  start_time = FUNC();
  for (uint32_t i = 0; i < ITERATIONS; i++)
  {
    count = (count + 1) & 0x03;
  }
  end_time = FUNC() - start_time; 
  Serial.println(end_time);
 
  while(1){};
}
