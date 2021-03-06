# Ryerson Rams Robotics Software Training
  This is my submission for R3 software team
## Overview
For this training module we were required to program an arduino to power 2 gear motors that will replicate the Rover's movement. This includes moving foward, backwards, performing a right turn and performing a left turn all using the following components:
  - 2 motors
  - 1 L293D Motor Driver
  - potentiometer
  - Dip Switch
  - 9V Battery
  
## Process  
I first began by wiring the L293D IC to the motors and the arduino without the dip switch or the potentiometer. This was done to get the movements working and then implement the dip switches and the potentiometer after. The implementation of the movements was initially done by setting each of the pins to `HIGH` and `LOW` to see how the IC interacts with the motor. For reference, The motor on the top of the breadboard is the right motor and the one on the bottom is the left motor. I then seperated each movement into its own function and then implemented the dip switch so that when one of the switch is in the on position it will execute its respective function. All of the code up till now was done `HIGH` and `LOW` however to implement the potentiometer we must use the `analogRead()` to change the speed of the motor according to the position of the potentiometer.
 
 ![image](https://user-images.githubusercontent.com/51526106/96365648-1a1a1d00-1110-11eb-8fd8-7fbc3eb36ba9.png)
 
## Improvements

  Some improvements that I could make are:
  
   - Creating a function that handles the states of the dip switch to make the code more readable
   - avoid writing the code for Arduino pins 10 and 7 as they have no effect on the functionality of the motors


To view and simulate the program click [Here](https://www.tinkercad.com/things/7fixDx3YHXB)
