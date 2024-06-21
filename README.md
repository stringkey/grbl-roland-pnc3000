This is a public backup of an experiment to use and Arduino Uno to control my Roland PNC 3000 milling machine

As the modification to GRBL 

The original repository can be found here https://github.com/gnea/grbl

Why didn't I fork this repository,

I wanted to; 
- use CLion, that is my standard C and C++ IDE
- modify core functionality that is only relevant to my specifc project
- to use Platform IO to simplify the proces of getting my the modified GRBL code on the Arduino Uno

Why not use GRBL HAL
- I tried and failed
- I already hand solderd an experimentation board to map Arduino Uno Pins to headers for the PNC 3000 and a Mach3 compatiple Delta 25 pin connector
- The original arduino software has way less dependencies (and dependency issues) to work with.

Goals
THE Roland PNC 3000 has frontpanel display that can show:
- The speed of the spindle
- The coordinates of the X/Y/Z axis in 1/100 mm
- The feedrate in mm/s (with 11 LEDs for a range between 2 and 22 mm/s)

The speed of the spindle is direct feedback from a tacho, the speed is controlled by a potentiometer. This bar graph indicator workst out of the box as it is 'directly' connected to the tacho.
The coordinate displays are connected parralel to the step and direction pulses, this is tested and works. It would be nice though if the coordinates could be reset programmatically, there is a line to reset X and Y as a pair and Z individually. << secondary goal
The feed rate indicator works with 4 lines going to the frontpanel, with 11 different bit combination on these 4 lines one out of 11 LEDs can be enabled. For this 2 BCD (Binary coded decimal) 1 of 10 decoder drivers are used 74LS145.

Now the real goal comes :) Can I read the actual feed rate either the setpoint or the actual feedrate from the GRBL loop and update 4 output pins in such a way that the display on the front panel shows the actual feedrate of the machine.

When you are familiar with GRBL on the Arduino Uno you already know that every features has been completely maxed out.

I don't need mist coolant or some other output set as most of these features are not present on the machine, same aplies for a cover that might be opened or closed.
So any pin that I can reuse means that I have to strip some code and replace it at minimum with a nibble of data that can be used to control the feed rate indicator.  




NOTES:

The PNC 3000 does not support a PWM controlled spindle and since I'm using as much of the original components I need to just toggle the motor on (M03 CW/M04 CCW) and off (M05). This is standard in GRBL, just comment out the VARIABLE_SPINDLE spindle define in config.h   
