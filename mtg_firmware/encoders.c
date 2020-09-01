#define PIN_MUX_SEL_0     (2)
#define PIN_MUX_SEL_1     (3)
#define PIN_MUX_SEL_2     (4)
#define PIN_MUX_RB        (5)

static const int8_t increment[] = {-1, 1};

static uint8_t mux_read(uint8_t value)
{
  digitalWrite(PIN_MUX_SEL_0, value & 0x01);
  digitalWrite(PIN_MUX_SEL_1, value & 0x02);
  digitalWrite(PIN_MUX_SEL_2, value & 0x04);
  return digitalRead(PIN_MUX_RB);
}


void setup() {
  Serial.begin(115200);  

  pinMode(PIN_MUX_SEL_0, OUTPUT);
  pinMode(PIN_MUX_SEL_1, OUTPUT);
  pinMode(PIN_MUX_SEL_2, OUTPUT);
  pinMode(PIN_MUX_RB, INPUT);
  
}

void loop() {
  static int16_t count[] = {0, 0, 0, 0};
  static uint8_t encoder_last[4];
  
  bool changed = false;
  for (uint8_t i = 0; i < 4; i++)
  {
    uint8_t mux = i * 2;
    uint8_t state = mux_read(mux);
    if (state != encoder_last[i])
    {
      uint8_t dir = mux_read(mux + 1);
      count[i] += increment[state ^ dir];
      changed = true;
    }
    encoder_last[i] = state;
  }

  if (changed)
  {
    for (uint8_t i = 0; i < 4; i++)
    {
      Serial.print(count[i]);
      Serial.print(" ");
    }
    Serial.println();
  }

  delay(2);
}
