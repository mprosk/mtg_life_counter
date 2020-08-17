#include <avr/sleep.h>
#define POWER_SWITCH_PIN  (2)

/*
 * Attatches a wake-up interrupt to the power switch and puts the Arduino to sleep
 */
void counter_sleep(void)
{
  // display_disbale();
  digitalWrite(LED_BUILTIN, 0);
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_wakeup, RISING);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_cpu();
  digitalWrite(LED_BUILTIN, 1);
}

/*
 * Wakes up the Arduino and removes the wake-up interrupt
 */
void counter_wakeup(void)
{
  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN));
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(POWER_SWITCH_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Ready");
  digitalWrite(LED_BUILTIN, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(POWER_SWITCH_PIN) == 0)
  {
//    delay(1000);
    Serial.println("Going to sleep");
    delay(10);
    counter_sleep();
    Serial.println("Woke up");
  }
}
