/* INCLUDES */
#include <avr/sleep.h>
#include "config.h"
#include "switches.h"
#include "sevenseg.h"

////////////////////////////////////////////////////////////////////////////////
// DEFINES
////////////////////////////////////////////////////////////////////////////////
/* PINS */
#define POWER_SWITCH_PIN  (2)
#define MODE_SWITCH_PIN   (A1)
#define ROLL_BTN_PIN      (6)
#define RESET_BTN_PIN     (7)
#define RNG_PIN           (A0)


////////////////////////////////////////////////////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void counter_sleep(void);
void counter_wakeup(void);
void counter_reset(void);


////////////////////////////////////////////////////////////////////////////////
// LOCAL TYPES
////////////////////////////////////////////////////////////////////////////////
typedef struct LifeCounter
{
  int16_t life_total;                         // Life Total (-999...9999)
  uint8_t commander_dmg[PLAYER_COUNT - 1];    // Commander Damage (0..21)
} LifeCounter;


////////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
////////////////////////////////////////////////////////////////////////////////
static const uint8_t STARTING_LIFE[2] = {20, 40};
static LifeCounter life_counters[PLAYER_COUNT];
static SwitchState switch_states[2];
static uint8_t sw = 0;
static uint8_t sw_last = 1;


////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);

  // Initialize Top-Level
  pinMode(POWER_SWITCH_PIN, INPUT);
  pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);
  pinMode(ROLL_BTN_PIN, INPUT_PULLUP);
  pinMode(RESET_BTN_PIN, INPUT_PULLUP);
  

  // Initialize 7-Segment Display Driver
  Serial.print("Initializing 7-seg... ");
  // TODO: 7-set init
  Serial.println("DONE");

  // Initialize Switch Sensing
  Serial.print("Initializing switch sensing... ");
  switches_init();
  switches_update(&switch_states[sw_last]);
  Serial.println("DONE");

  // Reset counters
  Serial.print("Resetting counters... ");
  counter_reset();
  Serial.println("DONE");
  
  Serial.println("Initialization complete");
}

int main() {
  uint8_t game_mode = 0;
 

  // MAIN LOOP
  while(1)
  {
    // Check for power off state
    if (digitalRead(POWER_SWITCH_PIN) == 0)
    {
      Serial.println("Going to sleep");
      counter_sleep();
      Serial.println("Woke up");
      counter_reset();
    }

    // Read switch states
    switches_update(&switch_states[sw]);

    // Check for differences
    
    
    // Update internal switch states
    sw ^= 1;
    sw_last ^= 1;
  }
}

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Attatches a wake-up interrupt to the power switch and puts the Arduino to sleep
 */
void counter_sleep(void)
{
  // display_disbale();
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_wakeup, RISING);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_cpu();
}

/*
 * Wakes up the Arduino and removes the wake-up interrupt
 */
void counter_wakeup(void)
{
  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN));
}

/*
 * Resets all the life counters
 */
void counter_reset(void)
{
  uint8_t life = STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)];

  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    life_counters[i].life_total = life;
    for (uint8_t j = 0; i < PLAYER_COUNT - 1; j++)
    {
      life_counters[i].commander_dmg[j] = 0;
    }
  }
}
