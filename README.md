# MTG Life Counter v1
Four player life counter for *Magic: The Gathering*

![MTG Life Counter](https://raw.githubusercontent.com/mprosk/mtg_life_counter/master/img/counter.jpg)

## Features

- Easily track the life of up to four players
- Each player can track poison counters and commander damage from the other three players
- Supported life totals of -999 to 9999
- Selectable starting life of 20, 30, or 40
- "Roll" button for randomly selecting the starting player

## Hardware

- Arduino Nano (ATmega328P)
- 4x common cathode 4-digit 7-segment displays
- 4x SP5T rotary switches
- 10x 12mm tactile switches
- 2x 74HC595 for segment driving
- 2x TPIC6B595 for sinking digit current
- 3x 74HC151 for switch and button scanning

## Theory of Operation

There are two main subsystems within the counter's design, the button and rotary switch input sensing, and the 7-segment display driving.

The input sensing is achieved using three 74HC151 multiplexers. The select bus for all three are connected together, allowing the Arduino to select from all three at once. The output lines from each multiplexer are sent back to the Arduino. This allows the firmware to monitor 24 digital lines using only 6 GPIO pins by scanning through the range of selections and monitoring all the readback lines.

This project uses four 4-digit common cathode 7-segment displays. The displays are arranged into a matrix with 2 rows, and 8 digits each. For each row, a 74HC959 serial-in-parallel-out shift register acts as the segment driver, while a TPIC6B959 serial-in-parallel-out high-current sink illuminates each digit in turn. The serial bus of all four of these shift registers are cascaded together.

# Operating Instructions

### Power

1. Plug a mini USB cable into the connector and set the power switch to ON. The display will initialize to the selected starting life total
5. To turn off the display, move the power switch to the OFF position or unplug the USB cable. The lights on the blue circuit board will remain lit if the USB cable is plugged in.

### Mode Select

1. To switch the counter between different starting life totals, use the 20/40 switch to select the mode. Changing this switch will reset the counters
2. To select a starting life of 30, press and hold the yellow reset button while changing the 20/40 mode switch. The setting of the switch does not matter so long as the reset button is held while it is changed.

### Tracking Life and Damage

1. Each player uses one corner of the board, which contains the 7-segment display, two push buttons for changing the counter's value, and a rotary switch for selecting which value to adjust and show on the display

#### Selecting Display Mode

1. The rotary switch is used to select between the player's own life, the commander damage from their three opponents, and poison counters.
2. Rotating the knob will immediately change the display. When the counter is displaying the player's life total, the number will appear in the screen alone. When the counter is set to commander damage, the corner of the leftmost digit of the display will points to the opponent from whom you are tracking commander damage. When the switch is set to poison counter mode, the leftmost digit of the display will show a `P`. 

#### Changing the Value

1. Once the desired mode has been selected using the rotary switch, the player can adjust that value by pressing the up/down buttons on the edge of the board
2. When the buttons are pressed, the counter will show the change in value that is being entered. After a brief timeout, the display will switch to showing the new updated value
   1. EXAMPLE: If you wish to log a loss of two points off your starting total, press the bottom button twice. The display will first read `40` before any buttons are pressed. When you press the first button, the display will switch to `-1`,  then when the next button is pressed, it will display `-2`. After a brief timeout, the display will switch to showing the new updated value

#### Resetting the Counters

1. To reset all the counters, press the yellow reset button in the middle of the board
2. You can also reset an individual counter by pressing both the directional buttons for that counter at the same time

### Roll Button

The ROLL button on the counter allows you to quickly and easily select a player at random, useful for determining which player starts, or even for randomly selecting which player you should deal damage to.

To activate this feature, press and hold the blue ROLL button in the middle of the counter. When you are ready, release the button, and the random output will be shown on the displays. It will automatically disappear after a few seconds.

#### Random Number Generation

While the button is held, a counter is continuously incremented. When the button is released, the value of this counter is used to calculate which player won the roll. This counter increments approximately every 1/64,000th of a second, so it is virtually impossible for a human to actuate the button quickly enough or precisely enough to influence the output of the roll.
