# incubatorNoiseArduino
College project which integrates a lolin v3 "nodeMCU", equipped with a sound detector and 3 LEDs, to Dweet.io for data interpretation in the JavaFX system in this repository, named 'incubatorManagerFX'.
The code provided is in C.

## Hardware
The hardware required is as follows:
- Protoboard (any size will do, so as long as you're willing to use flat cables to extend the ports' reach).
- NodeMCU or similar arduino boards with a WiFi module
- 3 LEDs (preferably Green-Yellow-Red)
- 3 resistors
- Sound level detector. They usually contain both digital and analogic outputs. In this project, only the analogic input is used

## Software
The software is written in C, on Arduino IDE (but any IDE will do). The language used in the prints and println's' is portuguese, although it's pretty straightforward once you read the actual code.

## Bottom line

The code provided sends the noise level to Dweet.io, and lights up the LEDs accordingly.
In neonate incubators, the ideal noise is between 35-45 Db. An ideal solution would also contain a 7-segment panel for precise Decibel displaying.

If you're going to use this code for a personal project, please include this page on your references.

Contact me if you need help with anything @ marcelluiz96@hotmail.com
