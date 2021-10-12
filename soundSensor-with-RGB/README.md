
This system is a flashing LED TV backlights that contains a sensitive mic sensor that allows the LED lights to dance to the music tempo. 
The device uses a mic sensor as an input as it receives the sound signal and inputs a signal into the microcontroller (Arduino Nano). 
Microcontroller outputs bits (0 = 0v or 1 = 5v) depending on the frequency of the sound signal received from sound sensor module. 
The output load consists of RGB LEDs strip which runs on 12-volt DC, however Arduino Nano only produces 5v out and its not enough to turn on 12v LED strip. 
To solve this problem, 3 MOSFETS were used to provide RGB LEDs 12 volts * 2 Amper power from the external power source and controlling the inputs of the MOSFET with the Microcontroller PWM pins to control the N-type junction. 
The lights flash when music is heard by the mic sensor.
