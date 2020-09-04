/***********************************************************************
 *  MTG Life Counter - Roll Button Engine
 *
 *  DESCRIPTION
 *      This module provides functions for enabling the roll feature
 *      of the counter. This feature allows players to randomly select
 *      one of the players (for randomly select first player or 
 *      damage targets). The result of the roll is shown on the display
 *
 *  REFERENCES
 *      None
 ***********************************************************************/


/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "roll.h"


/*=====================================================================*
    Private Defines
 *=====================================================================*/
#ifdef ROLL_ADAPTIVE_MODE
#endif


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
void animate_roll(bool animate);


static int8_t roll_result_last = -1;


/*=====================================================================*
    Public Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      roll_init
 *
 *  DESCRIPTION
 *      Initializes the roll button pin
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void roll_init(void)
{
    pinMode(PIN_ROLL_BTN, INPUT_PULLUP);
    roll_result_last = -1;
}

/*---------------------------------------------------------------------*
 *  NAME
 *      roll
 *
 *  DESCRIPTION
 *      Performs all state transitions and animations for the roll feature
 *
 *  RETURNS
 *      True if a roll animation occurred
 *---------------------------------------------------------------------*/
bool roll(void)
{
    static uint8_t roll_state = 0;
    static uint8_t roll_state_last = digitalRead(PIN_ROLL_BTN);
    bool roll_happened = 0;
    
    roll_state = digitalRead(PIN_ROLL_BTN);
    if ((roll_state == 0) && roll_state_last)
    {
        roll_happened = 1;

        // Button pressed
        Serial.println("Roll started");
        uint8_t roll_counter = 0;
        uint8_t result_count = 4;
        uint8_t player_map[PLAYER_COUNT] = {0, 1, 2, 3};
        if (roll_result_last >= 0)
        {
            result_count = 3;
            uint8_t i = 0;
            for (uint8_t p = 0; p < PLAYER_COUNT; p++)
            {
                if (p != roll_result_last)
                {
                    player_map[i] = p;
                    i++;
                }
            }
        }
        animate_roll(0);  // Reset the animation
        do
        {
            // Button held
            roll_counter = (roll_counter + 1) % result_count;
            digitalWrite(PIN_DEBUG_1, roll_counter == 0);
            roll_state = digitalRead(PIN_ROLL_BTN);
            animate_roll(1);
        }
        while(roll_state == 0);

        // Button released
        uint8_t roll_result = player_map[roll_counter];
#ifdef ROLL_ADAPTIVE_MODE
        roll_result_last = roll_result;
#endif
        
        // Generate roll result display
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            if (i == roll_result)
            {
                display_set_string(i, "PLAY");  
            }
            else
            {
                display_fill(i, ' ');
            }
        }
        Serial.print("Result: ");
        Serial.println(roll_result);
        delay(ROLL_RESULT_DURATION_MS);
    }
    roll_state_last = roll_state;
    
    return roll_happened;
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      animate_roll
 *
 *  DESCRIPTION
 *      Updates the roll animation.
 *      'animate' = False: Reset
 *      'animate' = True : Run animation
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void animate_roll(bool animate)
{
    static uint8_t animation = ANIMATION_COUNT - 1;
    static uint8_t x = 0;
    static uint32_t inc_time = 0;

    if (!animate)
    {
        inc_time = millis() - ANIMATION_SPEED_MS;
        animation = (animation + 1) % ANIMATION_COUNT;
        return;
    }
    
    if ((millis() - inc_time) > ANIMATION_SPEED_MS)
    {
        // Update display buffer
        for (uint8_t i = 0; i < PLAYER_COUNT; i++)
        {
            for (uint8_t j = 0; j < DISPLAY_PLAYER_WIDTH; j++)
            {
                display_set_digit(i, j, ANIMATIONS[animation][(x + j) % ANIMATION_LENGTH[animation]]);
            }
        }
        // increment
        x = (x + 1) % ANIMATION_LENGTH[animation];
        inc_time = millis();
    }
}
