# WIP: MTG Life Counter
Four player life counter for *Magic: The Gathering*

![MTG Life Counter](https://raw.githubusercontent.com/mprosk/mtg_life_counter/master/img/counter.jpg)

## Features

- Easily track the life of up to four players
- Each player can track poison counters and commander damage from the other three players, including partner commanders
- Supported life totals of -999 to 9999
- Selectable starting life of 20, 30, or 40
- "Roll" button for randomly selecting the starting player

## Hardware

- Arduino Nano (ATmega328P)
- 4x common cathode 4-digit 7-segment displays
- 4x rotary encoders with switches and detents
- 2x 12mm tactile switches
- 4x 74HC595 for segment driving
- 2x TPIC6B595 for sinking digit current
- 1x 74HC165 for encoder capture

## Operating Instructions

### Power and Reset

1. Plug a USB Type C cable into the counter and set the power switch to ON
2. The display will initialize to the starting life total selected by the starting life switch.
3. At any time, you can press the yellow reset button to clear the counters and set them to the starting value
4. To turn off the display, move the power switch to the OFF position or unplug the USB cable
5. Use the 20/40 switch to change between starting life totals. Note that moving this switch will reset all the counters
   1. To set a starting life of 30, press and hold the RESET button while changing the 20/40 switch to any position


### Using the Counters

1. 

### Roll Button

The ROLL button on the counter allows you to quickly and easily select a player at random, useful for determining which player starts, or even for randomly selecting which player you should deal damage to.

To activate this feature, press and hold the blue ROLL button in the middle of the counter. When you are ready, release the button, and the random output will be shown on the displays. The result disappears after a few seconds.

#### Random Number Generation

While the button is held, a counter is continuously incremented. When the button is released, the value of this counter is used to calculate which player won the roll. This counter increments approximately every 1/64,000th of a second, so it is virtually impossible for a human to actuate the button with enough precision to influence the output of the roll.

##  Next Hardware Revision

List of features and fixes that will be considered in the next hardware revision

#### Fixes

- No digital out on A6 and A7 on Nano
- Remove resistor to ground on power switch

#### Possible Features/Improvements

- Add 30 as an option in the staring life selector
- Use rotary encoders
- Look into more economic displays
- SMD components
- Integrated microcontroller
- Smaller form factor
- Battery powered
