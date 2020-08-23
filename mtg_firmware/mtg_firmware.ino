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
#define DEBUG_PIN1        (4)
#define DEBUG_PIN2        (5)

/* CONFIG */
//#define CPU_SLEEP_ENABLE
#define ANIMATION_SPEED_MS        (50)
#define COMMANDER_DAMAGE          (21)
#define POISON_COUNTERS           (10)
#define ROLL_RESULT_DURATION_MS   (2000)

////////////////////////////////////////////////////////////////////////////////
// LOCAL TYPES
////////////////////////////////////////////////////////////////////////////////
typedef struct LifeCounter_t
{
  uint8_t life[PLAYER_COUNT];
  uint8_t mode;
  int16_t delta;
  uint32_t timeout;
} LifeCounter_t;


////////////////////////////////////////////////////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
void counter_sleep(void);
void counter_wakeup(void);
void counter_reset(LifeCounter_t *counter);
void counter_reset_all(void);
void update_display(uint8_t player);
void update_display_all(void);
void rotary_init(void);
void set_buffer(uint8_t * buf, int16_t x);
void animate_roll(uint8_t reset);
//void play_to_win(void);

////////////////////////////////////////////////////////////////////////////////
// LOCAL CONSTANTS
////////////////////////////////////////////////////////////////////////////////
static const uint8_t STARTING_LIFE[2] = {20, 40};
static const uint8_t BUTTON_PLAYER_MAPPING[] = {2, 2, 3, 3, 0, 0, 1, 1};
static const uint8_t SWITCH_PLAYER_MAPPING[] = {1, 0, 3, 2};
static const int8_t BUTTON_INCREMENT_MAPPING[] = {1, -1, -1, 1, -1, 1, -1, 1};
static const uint8_t DIRECTION[4] = {
  B10000100,  // 0: Upper Left
  B11000000,  // 1: Upper Right
  B00110000,  // 2: Lower Right
  B00011000,  // 3: Lower Left
};
static const uint8_t PLAYER_MAP[PLAYER_COUNT][PLAYER_COUNT] = {   // Player-to-direction mapping
  {2, 3, 0, 1},
  {2, 3, 0, 1},
  {0, 1, 2, 3},
  {0, 1, 2, 3},
};
static const uint8_t CMDR_DMG_MAP[PLAYER_COUNT][PLAYER_COUNT] = {   // Player-to-direction mapping
  {2, 1, 0, 3},
  {3, 0, 1, 2},
  {2, 1, 0, 3},
  {3, 0, 1, 2},
};
static const uint8_t ROLL_TEXT[][PLAYER_COUNT] = {
  "PLAY", " GO ", " YOU", " YES", "GLHF"
};
static const uint8_t DEATH_TEXT[][PLAYER_COUNT] = {
  "OUCH", " OOF", " GG ", " RIP", "DEAD", "DIED", "  F ", "SRRY", " BYE", "BOOP", " DED", "LOSE"
};


////////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
////////////////////////////////////////////////////////////////////////////////
static LifeCounter_t counters[PLAYER_COUNT];
static SwitchState switch_state[2];
static uint8_t sw = 0;
static uint8_t sw_last = 1;


////////////////////////////////////////////////////////////////////////////////

void setup() {
  /* HARDWARE INITIALIZATION */
  Serial.begin(115200);
  Serial.println("Online"); Serial.flush();
  
  // Initialize Top-Level
  pinMode(POWER_SWITCH_PIN, INPUT);
  pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);
  pinMode(ROLL_BTN_PIN, INPUT_PULLUP);
  pinMode(RESET_BTN_PIN, INPUT_PULLUP);
  pinMode(DEBUG_PIN1, OUTPUT);
  pinMode(DEBUG_PIN2, OUTPUT);

  // Initialize 7-Segment Display Driver
  Serial.print("Initializing display.. "); Serial.flush();
  display_init();
  Serial.println("DONE");

  // Initialize Switch Sensing
  Serial.print("Initializing switch sensing... ");
  switches_init();
  Serial.println("DONE");

  Serial.println("Initialization complete"); Serial.flush();
  
  // Attach power switch interrupt
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_sleep, LOW);
}

void loop() {
  uint8_t reset_state = 0;
  uint8_t reset_state_last = digitalRead(RESET_BTN_PIN);
 
  uint8_t mode_state = 0;
  uint8_t mode_state_last = digitalRead(MODE_SWITCH_PIN);
  
  /* STARTUP */
  counter_reset_all();
  rotary_init();
  update_display_all();
  display_enable();
  switches_print(&switch_state[sw_last]);
//  play_to_win();
    
  /* MAIN LOOP */
  while(1)
  {

    digitalWrite(DEBUG_PIN2, HIGH);

    // Check for reset button activation or mode switch change
    reset_state = digitalRead(RESET_BTN_PIN);
    mode_state = digitalRead(MODE_SWITCH_PIN);
    if (
      ((reset_state == 0) && reset_state_last) 
      | (mode_state != mode_state_last))
    {
      counter_reset_all();
      update_display_all();
      Serial.print("Counter reset. Mode ");
      Serial.println(counters[0].life[0]);
    }
    reset_state_last = reset_state;
    mode_state_last = mode_state;
    
    // Handle roll button activation
    uint8_t roll_state = roll();

    // Read switch states
    switches_update(&switch_state[sw]);

    // Process rotary switch changes
    uint8_t rotary_changed = 0;
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
      // Check if this rotary switch changed
      if (switch_state[0].rotary_position[i] != switch_state[1].rotary_position[i])
      {
        // If the reading is valid
        int8_t setting = switch_state[sw].rotary_position[i];
        if (setting >= 0)
        { 
          uint8_t player = SWITCH_PLAYER_MAPPING[i];
          rotary_changed = 1;
          counters[player].mode = (uint8_t)setting;
          update_display(player);
        }
      }
    }

    // Process button changes
    uint8_t changes = switch_state[sw].button_state ^ switch_state[sw_last].button_state;
    if (changes && !roll_state)
    {
      for (uint8_t i = 0; i < BUTTON_COUNT; i++)
      {
        uint8_t mask = (1 << i);
        uint8_t player = BUTTON_PLAYER_MAPPING[i];

        // Check if both buttons in that player group are held
        if (i % 2 == 1)
        {
          uint8_t mask2 = (1 << i-1);
          if ((switch_state[sw].button_state & mask) &&
                (switch_state[sw].button_state & mask2))
          {
            counter_reset(&counters[player]);
            update_display(player);
            continue;
          }
        }
        
        // Check if this button was pressed
        if ((switch_state[sw].button_state & mask) && (changes & mask))
        {
          uint8_t mode = counters[player].mode;
          int8_t increment = BUTTON_INCREMENT_MAPPING[i];
          int16_t target = counters[player].life[mode] + increment;
          if (mode)
          {
            // Commander damage mode
            if ((target >= 0) && (target <= COMMANDER_DAMAGE))
            {
              // Only change values if we're within the possible commander damage range
              counters[player].life[mode] = target;
              update_display(player);
            }
          }
          else
          {
            // Own life mode
            if ((target >= DISPLAY_MIN) && (target <= DISPLAY_MAX))
            {
              // Only change values if we're within the display-able range
              counters[player].life[mode] = target;
              update_display(player);
            }
          }
        }
      }
    }

    // Debug printout
    if (changes || rotary_changed)
    {
      switches_print(&switch_state[sw]);
    }
    
    // Update internal switch states
    sw ^= 1;
    sw_last ^= 1;

    digitalWrite(DEBUG_PIN2, LOW);
  }
}

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

/*
 * Performs all state transitions and animations for the roll feature
 */
uint8_t roll(void)
{
  static uint8_t roll_state = 0;
  static uint8_t roll_state_last = digitalRead(ROLL_BTN_PIN);
  static uint32_t roll_timeout = 0;
  static uint8_t roll_hold = 0;
  
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
      digitalWrite(DEBUG_PIN1, roll_counter == 0);
      roll_state = digitalRead(ROLL_BTN_PIN);
      animate_roll(1);
    }
    while(roll_state == 0);

    // Button released
    uint8_t roll_result = roll_counter % PLAYER_COUNT;
    roll_hold = 1;
    roll_timeout = millis() + ROLL_RESULT_DURATION_MS;   // THIS IS NOT ROLLOVER RESISTANT
    // Generate roll result display
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
      if (i == roll_result)
      {
        display_set_string(roll_result, "PLAY");  
      }
      else
      {
        display_fill_raw(i, DIRECTION[PLAYER_MAP[i][roll_result]]);
      }
    }
    Serial.print("Result: ");
    Serial.println(roll_result);
  }
  roll_state_last = roll_state;

  // Clear roll display if timeout expired
  if (roll_hold)
  {
    if (millis() >= roll_timeout)
    {
      roll_hold = 0;
      update_display_all();
    }
  }
  return roll_hold;
}

/*
 * Updates the display buffer with the selected counter data for all players
 */
void update_display(uint8_t player)
{
  uint8_t mode = counters[player].mode;
  display_set_int(player, counters[player].life[mode]);
  if (mode)
  {
    // Commander damage mode
    display_set_digit(player, 0, DIRECTION[CMDR_DMG_MAP[player][mode]]);
  }
}

/*
 * Updates the display buffer for all players
 */
void update_display_all(void)
{
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    update_display(i);
  }
}

/*
 * Resets the given counter
 */
void counter_reset(LifeCounter_t *counter)
{
  counter->life[0] = STARTING_LIFE[digitalRead(MODE_SWITCH_PIN)];
  for (uint8_t i = 1; i < PLAYER_COUNT; i++)
  {
    counter->life[i] = 0;
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
  static uint8_t animation = ANIMATION_COUNT - 1;
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
    inc_time = millis() + ANIMATION_SPEED_MS;   // THIS IS NOT ROLLOVER REISTANT
    
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
 * Sets the display modes when the unit is first started
 */
void rotary_init(void)
{
  switches_update(&switch_state[sw_last]);
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    int8_t setting = switch_state[sw_last].rotary_position[i];
    uint8_t player = SWITCH_PLAYER_MAPPING[i];
    if (setting >= 0)
    {
      counters[player].mode = (uint8_t)setting;
    }
    else
    {
      counters[player].mode = 0;
    }
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
  rotary_init();
  update_display_all();
  display_enable();
  attachInterrupt(digitalPinToInterrupt(POWER_SWITCH_PIN), counter_sleep, LOW);
//  play_to_win();
}


void play_to_win(void)
{
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    display_set_string(i, "PLAY");
  }
  delay(500);
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    display_set_string(i, " TO ");
  }
  delay(500);
  for (uint8_t i = 0; i < PLAYER_COUNT; i++)
  {
    display_set_string(i, "  IN");
    display_set_digit(i, 0, B00111100);
    display_set_digit(i, 1, B01111000);
  }
  delay(500);
  update_display_all();
}
