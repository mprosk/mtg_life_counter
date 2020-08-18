/* INCLUDES */
#include <avr/sleep.h>
#include "config.h"
#include "display.h"
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
#define DEBUG_PIN         (4)
/* CONFIG */
//#define CPU_SLEEP_ENABLE

////////////////////////////////////////////////////////////////////////////////
// LOCAL TYPES
////////////////////////////////////////////////////////////////////////////////
typedef struct LifeCounter
{
  int16_t life_total;                         // Life Total (-999...9999)
  uint8_t commander_dmg[PLAYER_COUNT - 1];    // Commander Damage (0..21)
} LifeCounter;


////////////////////////////////////////////////////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void counter_sleep(void);
void counter_wakeup(void);
void counter_reset(LifeCounter *counter);
void counter_reset_all(void);
void switch_test(void);

////////////////////////////////////////////////////////////////////////////////
// LOCAL CONSTANTS
////////////////////////////////////////////////////////////////////////////////
static const uint8_t STARTING_LIFE[2] = {20, 40};
static const uint8_t PLAYER_POSITION[PLAYER_COUNT][PLAYER_COUNT -1] = {
  {2, 1, 3},
  {0, 1, 2},
  {2, 1, 3},
  {0, 1, 2},
};

////////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
////////////////////////////////////////////////////////////////////////////////
extern volatile uint8_t display_buffer[MATRIX_DEPTH][MATRIX_WIDTH];
static LifeCounter life_counters[PLAYER_COUNT];
static SwitchState switch_states[2];
static uint8_t sw = 0;
static uint8_t sw_last = 1;


////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  Serial.println("Online"); Serial.flush();
  // Initialize Top-Level
  pinMode(POWER_SWITCH_PIN, INPUT);
  pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);
  pinMode(ROLL_BTN_PIN, INPUT_PULLUP);
  pinMode(RESET_BTN_PIN, INPUT_PULLUP);
  pinMode(DEBUG_PIN, OUTPUT);  

  // Initialize 7-Segment Display Driver
  Serial.print("Initializing 7-seg... "); Serial.flush();
  display_init();
  Serial.println("DONE");

  // Initialize Switch Sensing
  Serial.print("Initializing switch sensing... ");
  switches_init();
  switches_update(&switch_states[sw_last]);
  Serial.println("DONE");

  // Reset counters
  Serial.print("Resetting counters... ");
  counter_reset_all();
  Serial.println("DONE");

  // Attach power switch interrupt
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_sleep, LOW);
  
  Serial.println("Initialization complete");
}

void loop() {
  static uint8_t reset_state = 1;
  static uint8_t reset_state_last = 1;
  static uint8_t roll_state = 1;
  static uint8_t roll_state_last = 1;
  
  // MAIN LOOP
  while(1)
  {
    
    // Check for power off state
    if (digitalRead(POWER_SWITCH_PIN) == 0)
    {
      
      counter_sleep();
      
    }


    // Check for reset button activation
    reset_state = digitalRead(RESET_BTN_PIN);
    if ((reset_state == 0) && reset_state_last)
    {
      counter_reset_all();
      Serial.print("Counter reset. Mode ");
      Serial.println(life_counters[0].life_total);
    }
    reset_state_last = reset_state;


    // Check for roll button activation
    roll_state = digitalRead(ROLL_BTN_PIN);
    if ((roll_state == 0) && roll_state_last)
    {
      // Button pressed
      Serial.println("Roll started");
      uint8_t roll_counter = 0;
      do
      {
        // Button held
        roll_counter++;
        digitalWrite(DEBUG_PIN, roll_counter == 0);
        roll_state = digitalRead(ROLL_BTN_PIN);
      }
      while(roll_state == 0);

      // Button released
      Serial.print("Result: ");
      Serial.println(roll_counter % PLAYER_COUNT);
    }
    roll_state_last = roll_state;


    // Read switch states
    switches_update(&switch_states[sw]);


    // Check for differences
    if (switches_changed(&switch_states[0], &switch_states[1]))
    {
      switches_print(&switch_states[sw]); 
    }

    
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
  display_disable();
  Serial.println("Going to sleep");
  Serial.flush();
#ifdef CPU_SLEEP_ENABLE
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_wakeup, RISING);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_cpu();
#else
  while(digitalRead(POWER_SWITCH_PIN) == 0)
  {
    delay(10);
  }
  counter_wakeup();
#endif
}

/*
 * Wakes up the Arduino and removes the wake-up interrupt
 */
void counter_wakeup(void)
{
#ifdef CPU_SLEEP_ENABLE
  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN));
#endif
  Serial.println("Woke up");
  counter_reset_all();
  display_enable();
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_sleep, LOW);
}

/*
 * Resets the given counter
 */
void counter_reset(LifeCounter *counter)
{
  counter->life_total = STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)];
  for (uint8_t i = 0; i < PLAYER_COUNT - 1; i++)
  {
    counter->commander_dmg[i] = 0;
  }
}

/*
 * Resets all the life counters
 */
void counter_reset_all(void)
{
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    counter_reset(&life_counters[i]);
  }
}

void switch_test(void)
{ 
  switches_update(&switch_states[sw]);
  switches_print(&switch_states[sw]);
  
  while (1){
    switches_update(&switch_states[sw]);
    if (switches_changed(&switch_states[0], &switch_states[1]))
    {
      switches_print(&switch_states[sw]); 
    }
    sw ^= 1;
    sw_last ^= 1;
  }
}
