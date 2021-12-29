/***********************************************************************
 *  MTG Life Counter
 *
 *  DESCRIPTION
 *      Four player life counter for Magic: The Gathering
 *      Life totals are displayed on 7-segement displays
 *      Players adjust life using up/down buttons, and can
 *      track commander damage and poison counters using a 
 *      rotary switch to change display modes.
 *
 *  REFERENCES
 *      MTG Life Counter Schematic
 ***********************************************************************/

/* INCLUDES */
#include "config.h"
#include "display.h"
#include "counter.h"
#include "encoders.h"
#include "roll.h"


/* PIN DEFINES */
#define PIN_MODE_SWITCH     (9)
#define PIN_RESET_BTN       (8)

/* CONFIG OPTIONS */


/*=====================================================================*
    Private Data Types
 *=====================================================================*/


/*=====================================================================*
    Private Constants
 *=====================================================================*/


/*=====================================================================*
    Private Data
 *=====================================================================*/
static encoder_state_t encoders;


/*=====================================================================*
    Arduino Hooks
 *=====================================================================*/

void setup()
{
    /* HARDWARE INITIALIZATION */
    Serial.begin(115200);
    Serial.println("Startup");

    // Initialize top-level GPIO
    pinMode(PIN_MODE_SWITCH, INPUT_PULLUP);
    pinMode(PIN_RESET_BTN, INPUT_PULLUP);
    pinMode(PIN_DEBUG_1, OUTPUT);
    pinMode(PIN_DEBUG_2, OUTPUT);

    // Initialize encoders
    encoders_init();

    // Initialize counters
    counter_reset_all(STARTING_LIFE[digitalRead(PIN_MODE_SWITCH)]);

    // Initialize roll
    roll_init();

    // Initialize display
    display_init();
    display_start();

    Serial.println("Initialization complete"); Serial.flush();

    // Tests
//     display_test();
    // encoder_test();

    // Splash screen
//    splash_screen();
  }

/*=====================================================================*/

void loop()
{
    static uint8_t reset_state_last = digitalRead(PIN_RESET_BTN);
    static uint8_t mode_state_last = digitalRead(PIN_MODE_SWITCH);

    digitalWrite(PIN_DEBUG_2, HIGH);

    // Read the current state of the reset button and mode switch
    uint8_t reset_state = digitalRead(PIN_RESET_BTN);
    uint8_t mode_state = digitalRead(PIN_MODE_SWITCH);
    bool reset_pressed = (reset_state == 0) && (reset_state_last);
    bool mode_changed = (mode_state != mode_state_last);

    // Reset the display if the reset button was pressed OR the mode switch was changed
    if (reset_pressed || mode_changed)
    {
        uint8_t mode = mode_state;
        if (reset_pressed && mode_changed)
        {
            // Switch to 30 life mode if the reset button is held when the mode switch changes
            mode = 2;
        }
        counter_reset_all(STARTING_LIFE[mode]);
        Serial.print("Counter reset. Mode ");
        Serial.println(STARTING_LIFE[mode]);
    }
    reset_state_last = reset_state;
    mode_state_last = mode_state;

    // Handle roll button
    if(roll())
    {
        // Reset display after roll animation complete
        counter_redraw_all();
    }

    // Process encoder changes
    update_encoders(&encoders);

    // Update the counters
    counter_update_all(&encoders);

    digitalWrite(PIN_DEBUG_2, LOW);
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      update_encoders
 *
 *  DESCRIPTION
 *      Processes encoder 
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void update_encoders(encoder_state_t * encoders)
{
    // Stop the display interrupt
    display_stop();

    // Read the current encoder state
    digitalWrite(ENCODERS_LATCH_PIN, LOW);
    digitalWrite(ENCODERS_LATCH_PIN, HIGH);
    uint8_t state = SPI.transfer(0);

    // Restart the display interrupt
    display_start();

    // Decode the encoder changes
    encoders_update(state, encoders);
}

/*---------------------------------------------------------------------*
 *  NAME
 *      splash_screen
 *
 *  DESCRIPTION
 *      Generates the startup message
 *---------------------------------------------------------------------*/
void splash_screen()
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, "MmEN");
    }
    delay(500);
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, " TAL");
    }
    delay(500);
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, "MmIS");
    }
    delay(500);
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        display_set_string(i, "PLAY");
    }
    delay(500);
    counter_redraw_all();
}

/*=====================================================================*
    Tests
 *=====================================================================*/

void display_test(void)
{
    display_set_string(0, "ONE_");
    display_set_string(1, "TWwO");
    display_set_string(2, "THRE");
    display_set_string(3, "FOUR");
    uint8_t i = 0;
    while (1)
    {
        Serial.println(i);
        i++;
        delay(1000);
    }
}

void encoder_test(void)
{
    int16_t vals[PLAYER_COUNT] = {0, 0, 0, 0};

    while (1)
    {
        update_encoders(&encoders);
        if (encoders.changed)
        {
            for (uint8_t i = 0; i < PLAYER_COUNT; i++)
            {
                Serial.print(encoders.encoder[i]);
                Serial.print(" ");
                vals[i] += encoders.encoder[i];
                display_set_int(i, vals[i]);
            }
            Serial.println("");
        }
        delayMicroseconds(100);
    }
}
