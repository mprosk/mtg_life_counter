/***********************************************************************
 *  MTG Life Counter - Switch Sensing
 *
 *  DESCRIPTION
 *      Provides functions for detecting button and switch states
 *
 *  REFERENCES
 *      74x151 Datasheet
 *      MTG Life Counter Schematic
 ***********************************************************************/

/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "switches.h"


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
static void read_switches(void);
static int8_t decode_rotary(uint8_t switch_state);


/*=====================================================================*
    Private Data
 *=====================================================================*/
static uint16_t rotary_latch[PLAYER_COUNT] = {0, 0, 0, 0};
static uint8_t button_state = 0;
static uint8_t button_state_last = 0;
static int8_t rotary_state[2][PLAYER_COUNT] = { {0, 0, 0, 0}, {0, 0, 0, 0} };
static uint8_t sw = 0;
static uint8_t sw_last = 1;


/*=====================================================================*
    Public Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_init
 *
 *  DESCRIPTION
 *      Initializes the switch sensing hardware
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_init(void)
{
    pinMode(SWITCH_RB1_PIN, INPUT);
    pinMode(SWITCH_RB2_PIN, INPUT);
    pinMode(BUTTON_RB_PIN, INPUT);
}

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_start
 *
 *  DESCRIPTION
 *      Starts switch scanning and enables the hardware
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_start(void)
{
    pinMode(MUX_SELECT_0, OUTPUT);
    pinMode(MUX_SELECT_1, OUTPUT);
    pinMode(MUX_SELECT_2, OUTPUT);
    read_switches();
}

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_stop
 *
 *  DESCRIPTION
 *      Stops the switch scanning and disables the hardware
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_stop(void)
{
    digitalWrite(MUX_SELECT_0, LOW);
    digitalWrite(MUX_SELECT_1, LOW);
    digitalWrite(MUX_SELECT_2, LOW);
    pinMode(MUX_SELECT_0, INPUT);
    pinMode(MUX_SELECT_1, INPUT);
    pinMode(MUX_SELECT_2, INPUT);
}

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_update
 *
 *  DESCRIPTION
 *      Scans through the multiplexers and reads the switch states
 *      Compares the current state to the previous state and updates
 *      the given data structure accordingly. Data in the structure
 *      is placed in player-index order (hardware order of the switches
 *      is un-maped)
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_update(SwitchState_t *state_ptr)
{
    // Update the internal switch states
    read_switches();

    // Process rotary switch changes
    uint8_t rotary_changes = 0;
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        uint8_t player_id = SWITCH_PLAYER_MAPPING[i];
        bool changed = (rotary_state[sw][i] != rotary_state[sw_last][i]);

        // Handle debounce of null-state rotary
        if (rotary_state[sw][i] == PLAYER_COUNT)
        {
            // Reset the latch counter if this is the first null reading
            if (changed)
            {
                rotary_latch[i] = 1;
                state_ptr->rotary_changes[player_id] = 0;
            }
            else if (rotary_latch[i] > ROTARY_THRESHOLD)
            {
                // Threshold met, set the output
                state_ptr->rotary_state[player_id] = rotary_state[sw][i];
                state_ptr->rotary_changes[player_id] = 1;
                rotary_changes = 1;
                Serial.println(rotary_latch[i]);
                rotary_latch[i] = 0;    // stop the counter
            }
            else if (rotary_latch[i])
            {
                // Increment the counter
                rotary_latch[i]++;
                state_ptr->rotary_changes[player_id] = 0;
            }
            else
            {
                // Debounce expired, just show as the null state unchanged
                state_ptr->rotary_state[player_id] = rotary_state[sw][i];
                state_ptr->rotary_changes[player_id] = 0;
            }
        }
        else
        {
            // Update the state structure
            state_ptr->rotary_state[player_id] = rotary_state[sw][i];
            state_ptr->rotary_changes[player_id] = changed;
            rotary_changes |= changed;
        }
    }
     state_ptr->rotaries_changed = rotary_changes;

    // Process button changes
    uint8_t changes = button_state ^ button_state_last;
    for (uint8_t i = 0; i < BUTTON_COUNT; i++)
    {
        // Get the mapping to player index
        uint8_t mask = (1 << i);
        uint8_t player_id = BUTTON_PLAYER_MAPPING[i];
        uint8_t button = BUTTON_DIRECTION_MAPPING[i];

        // Update the state structure with the new state info
        state_ptr->button_state[player_id][button] = (button_state & mask) >> i;
        state_ptr->button_changes[player_id][button] = (changes & mask) >> i;
    }
    state_ptr->buttons_changed = changes;   // Convert to logical
    
    // Swap current and last to get ready for the next reading
    button_state_last = button_state;
    sw ^= 1;
    sw_last ^= 1;
}

/*---------------------------------------------------------------------*
 *  NAME
 *      switches_print
 *
 *  DESCRIPTION
 *      Prints the state position to the screen
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void switches_print(SwitchState_t *state_ptr)
{
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        for (uint8_t j = 0; j < BUTTONS_PER_PLAYER; j++)
        {
            Serial.print(state_ptr->button_state[i][j]);
            Serial.print(" ");
        }
    }
    Serial.print("| ");
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        Serial.print(state_ptr->rotary_state[i]);
        Serial.print(" ");
    }
    Serial.println();
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      read_switches
 *
 *  DESCRIPTION
 *      Cycles through the multiplexers and reads all switch states
 *      into the internal state variables
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
static void read_switches(void)
{
    uint8_t this_rotary[4] = {0, 0, 0, 0};

    // Scan through the mux and read back
    for (uint8_t i = 0; i < 8; i++)
    {
        // Update the select bus
        digitalWrite(MUX_SELECT_0, i & (1 << 0));
        digitalWrite(MUX_SELECT_1, i & (1 << 1));
        digitalWrite(MUX_SELECT_2, i & (1 << 2));

        // Read button state
        if (digitalRead(BUTTON_RB_PIN))
        {
            button_state |= (1 << i);
        }
        else
        {
            button_state &= ~(1 << i);
        }
        
        // Read rotary switch state
        this_rotary[(i / 4) + 0] |= digitalRead(SWITCH_RB1_PIN) << (i % 4);
        this_rotary[(i / 4) + 2] |= digitalRead(SWITCH_RB2_PIN) << (i % 4);
    }

    // Decode the 1-hot encoding
    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        rotary_state[sw][i] = decode_rotary(this_rotary[i]);
    }
}

/*---------------------------------------------------------------------*
 *  NAME
 *      decode_rotary
 *
 *  DESCRIPTION
 *      Converts the one-hot encoded switch setting into an integer representation
 *
 *  RETURNS
 *      The numeric setting of the rotary switch. -1 if invalid
 *---------------------------------------------------------------------*/
static int8_t decode_rotary(uint8_t rotary_state)
{
    if (rotary_state == 0)
    {
        return PLAYER_COUNT;
    }

    for (uint8_t i = 0; i < PLAYER_COUNT; i++)
    {
        if (rotary_state == (1 << i))
        {
        return PLAYER_COUNT - i - 1;
        }
    }

    return -1;
}
