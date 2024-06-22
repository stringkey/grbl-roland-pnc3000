This is a public backup of an experiment to use and Arduino Uno to control my Roland PNC 3000 milling machine

# DISCLAIMER: 
This code is modified to be specific for the Roland PNC 3000 rebuild with a custom piggyback PCB to replace the original motherboard of the machine.
For the vanilla code please check out the original codebase mentioned below.
Use of the code in this repository at your own risk. The inputs for some of the safety features are repurposed for something else, be warned!!!

# The modification
As the modification to GRBL in the Arduino IDE got very complex I decided to use CLion and Platform IO to have more 
IDE features and direct access to all files. I had to rearrange the project and manually place the files in right folders.
The changes that are going to follow are destructive and lead to a non-standard 'product'.

To make it easier to find the changes I am making and to make the process easily reversible (to test if my changes caused) 
I'm going to wrap all modified code in conditional macro blocks. (#define ROLAND_PNC3000, #ifdef #ifndef).

The original repository can be found here https://github.com/gnea/grbl

Why didn't I fork this repository,

I wanted to; 
- use CLion, that is my standard C and C++ IDE
- modify core functionality that is only relevant to my specific project
- to use Platform IO to simplify the process of getting my the modified GRBL code on the Arduino Uno

Why not use GRBL HAL
- I tried and failed
- I already hand soldered an experimentation board to map Arduino Uno Pins to headers for the PNC 3000 and a Mach3 compatible Delta 25 pin connector
- The original arduino software has way less dependencies (and dependency issues) to work with.

Goals
The Roland PNC 3000 has front panel display useful information when the machine is operated.
It consists out of 3 main parts:
1. The speed of the spindle as an 11 segment bar graph display
2. A 5 digits LED display with coordinates of the X/Y/Z axis in 1/100 mm increments 
3. The feed rate in mm/s with an 11 led bar graph, for a range between 2 and 22 mm/s

# 1. Spindle speed
The speed of the spindle is direct feedback from a tacho, the speed is controlled by a potentiometer. This bar graph indicator works out of the box as it is 'directly' connected to the tacho.

# 2. Coordinates
The coordinate displays are connected parallel to the step and direction pulses, this is tested and works. It would be nice though if the coordinates could be reset programmatically, there is a line to reset X and Y as a pair and Z individually. << secondary goal

# 3. The feed rate 
The feed rate indicator works with 4 lines going to the front panel, with 11 different bit combination on these 4 lines one out of 11 LEDs can be enabled. For this 2 BCD (Binary coded decimal) 1 of 10 decoder drivers are used 74LS145.

Now the real goal comes :) Can I read the actual feed rate either the setpoint or the actual feed rate from the GRBL loop and update 4 output pins in such a way that the display on the front panel shows the actual feed rate of the machine.

When you are familiar with GRBL on the Arduino Uno, you probably know that every feature has been completely maxed out.

I don't need mist coolant or some other output set as most of these features are not present on the machine, same applies for a cover that might be opened or closed.
So any pin that I can reuse means that I have to strip some code and replace it at minimum with a nibble of data that can be used to control the feed rate indicator.  




# NOTES:

The PNC 3000 does not support a PWM controlled spindle and since I'm using as much of the original components I need to just toggle the motor on (M03 CW/M04 CCW) and off (M05). This is standard in GRBL, just comment out the VARIABLE_SPINDLE define in config.h to disable PWM.  
