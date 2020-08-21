/* INCLUDES */
#include <avr/sleep.h>
#include "config.h"
#include "display.h"
#include "switches.h"
#include "animations.h"

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
#define ANIMATION_SPEED_MS  (50)

////////////////////////////////////////////////////////////////////////////////
// LOCAL TYPES
////////////////////////////////////////////////////////////////////////////////
typedef struct LifeCounter_t
{
  int16_t life;                           // Life Total (-999...9999)
  uint8_t commander[PLAYER_COUNT - 1];    // Commander Damage (0..21)
} LifeCounter_t;


////////////////////////////////////////////////////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void counter_sleep(void);
void counter_wakeup(void);
void counter_reset(LifeCounter_t *counter);
void counter_reset_all(void);
void update_display(void);
void set_buffer(uint8_t * buf, int16_t x);
void animate_roll(uint8_t animation, uint8_t reset);

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
static const uint8_t BUTTON_PLAYER_MAPPING[] = {2, 2, 3, 3, 0, 0, 1, 1};
static const int8_t BUTTON_INCREMENT_MAPPING[] = {1, -1, -1, 1, -1, 1, -1, 1};

////////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
////////////////////////////////////////////////////////////////////////////////
static LifeCounter_t counters[PLAYER_COUNT];
static SwitchState switch_state[2];
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
  switches_update(&switch_state[sw_last]);
  Serial.println("DONE");

  // Reset counters
  Serial.print("Resetting counters... ");
  counter_reset_all();
  Serial.println("DONE");

  // Attach power switch interrupt
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_sleep, LOW);
  
  Serial.println("Initialization complete");
  Serial.println(DISPLAY_MAX);
  Serial.println(DISPLAY_MIN);
}

void loop() {
  uint8_t reset_state = 0;
  uint8_t reset_state_last = digitalRead(RESET_BTN_PIN);
 
  uint8_t mode_state = 0;
  uint8_t mode_state_last = digitalRead(MODE_SWITCH_PIN);
  
  update_display();
  display_enable();
    
  // MAIN LOOP
  while(1)
  {

    // Check for reset button activation or mode switch change
    reset_state = digitalRead(RESET_BTN_PIN);
    mode_state = digitalRead(MODE_SWITCH_PIN);
    if (
      ((reset_state == 0) && reset_state_last) 
      | (mode_state != mode_state_last))
    {
      counter_reset_all();
      update_display();
      Serial.print("Counter reset. Mode ");
      Serial.println(counters[0].life);
    }
    reset_state_last = reset_state;
    mode_state_last = mode_state;
    
    // Check for roll button activation
    roll();


    // Read switch states
    switches_update(&switch_state[sw]);


    // Check for differences
    uint8_t changes = switch_state[sw].button_state ^ switch_state[sw_last].button_state;
    //if (switches_changed(&switch_state[0], &switch_state[1]))
    if (changes)
    {
      for (uint8_t i = 0; i < BUTTON_COUNT; i++)
      {
        uint8_t mask = (1 << i);

        // Check if both
        
        // Check if this button was pressed
        if ((switch_state[sw].button_state & mask) && (changes & mask))
        {
          counters[BUTTON_PLAYER_MAPPING[i]].life += BUTTON_INCREMENT_MAPPING[i];
          display_set_int(BUTTON_PLAYER_MAPPING[i], counters[BUTTON_PLAYER_MAPPING[i]].life);
        }
      }
      switches_print(&switch_state[sw]);
    }
    
    
    
    // Update internal switch states
    sw ^= 1;
    sw_last ^= 1;
  }
}

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

void roll(void)
{
  static uint8_t roll_state = 0;
  static uint8_t roll_state_last = digitalRead(ROLL_BTN_PIN);
  
  roll_state = digitalRead(ROLL_BTN_PIN);
  if ((roll_state == 0) && roll_state_last)
  {
    // Button pressed
    Serial.println("Roll started");
    uint8_t roll_counter = 0;
    animate_roll(0);  // Reset the animation
    do
    {
      // Button held
      roll_counter++;
      digitalWrite(DEBUG_PIN, roll_counter == 0);
      roll_state = digitalRead(ROLL_BTN_PIN);
      animate_roll(1);
    }
    while(roll_state == 0);

    // Button released
    Serial.print("Result: ");
    Serial.println(roll_counter % PLAYER_COUNT);
    update_display();
  }
  roll_state_last = roll_state;
}

/*
 * Updates the display buffer with the counter data
 */
void update_display(void)
{
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    display_set_int(i, counters[i].life);
  }
}

/*
 * Resets the given counter
 */
void counter_reset(LifeCounter_t *counter)
{
  counter->life = STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)];
  for (uint8_t i = 0; i < PLAYER_COUNT - 1; i++)
  {
    counter->commander[i] = 0;
  }
}

/*
 * Resets all the life counters
 */
void counter_reset_all(void)
{
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    counter_reset(&counters[i]);
  }
}

/*
 * Updates the roll animation
 * 0 = reset, 1 = animate
 */
void animate_roll(uint8_t animate)
{
  static uint8_t animation = ANIMATION_COUNT;
  static uint8_t x = 0;
  static uint32_t inc_time = 0;

  if (animate == 0)
  {
    inc_time = 0;
    animation = (animation + 1) % ANIMATION_COUNT;
    return;
  }
  
  if (millis() >= inc_time)
  {
    inc_time = millis() + ANIMATION_SPEED_MS;
    
    // Update display buffer
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
      for (uint8_t j = 0; j < DISPLAY_WIDTH; j++)
      {
        display_set_digit(i, j, ANIMATIONS[animation][(x + j) % ANIMATION_LENGTH[animation]]);
      }
    }
    // increment
    x = (x+1) % ANIMATION_LENGTH[animation];
  }
}

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
    delay(100);
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
  update_display();
  display_enable();
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_sleep, LOW);
}
