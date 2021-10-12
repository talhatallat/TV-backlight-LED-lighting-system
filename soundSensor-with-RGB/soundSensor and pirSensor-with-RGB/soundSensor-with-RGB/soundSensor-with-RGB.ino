/*
 Programmer Name: Talha Tallat 
 Program name: TV backlight LED lighting system
 Program decription: This system is a flashing LED TV backlights that contains a sensitive mic sensor that allows the LED lights to dance to the music tempo. 
                     The device uses a mic sensor as an input as it receives the sound signal and inputs a signal into the microcontroller (Arduino Nano). 
                     Microcontroller outputs bits (0 = 0v or 1 = 5v) depending on the frequency of the sound signal received from sound sensor module. 
                     The output load consists of RGB LEDs strip which runs on 12-volt DC, however Arduino Nano only produces 5v out and its not enough to turn on 12v LED strip. 
                     To solve this problem, 3 MOSFETS were used to provide RGB LEDs 12 volts * 2 Amper power from the external power source and controlling the inputs of the MOSFET with the Microcontroller PWM pins to control the N-type junction. 
                     The lights flash when music is heard by the mic sensor.
 */



#define REDPIN 3  
#define GREENPIN 4
#define BLUEPIN 5
 
int redNow;
int blueNow;
int greenNow;
int redNew;
int blueNew;
int greenNew;
int pir = 2;
int sound = A0;
 
void setup()
{
  pinMode(pir, INPUT); // Passive infrad sensor for 12v sourse, on/off
  pinMode(sound,INPUT); // SIG of the Parallax Sound Impact Sensor connected to Digital Pin 3
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  redNow = random(255);
  blueNow = random(255);
  greenNow = random(255);
  redNew = redNow;
  blueNew = blueNow;
  greenNew = greenNow;
}
#define fade(x,y) if (x>y) x--; else if (x<y) x++;


 
void loop()
{
  // If the pir sensor is on then the program will do the next part
  if(digitalRead(pir) == HIGH)
  {

  // It reads the soundSensor from digital pin 3
  boolean soundstate = digitalRead(sound);
  
  // If the soundsensor is on, the program will do next part 
  if (soundstate == 1)
 {
    analogWrite(BLUEPIN, blueNow);
    analogWrite(REDPIN, redNow);
    analogWrite(GREENPIN, greenNow);
    redNew = random(255);
    blueNew = random(255);
    greenNew = random(255);

    // fade to new colors
    while ((redNow != redNew) || (blueNow != blueNew) || (greenNow != greenNew))
    {
      fade(redNow,redNew)
      fade(blueNow,blueNew)
      fade(greenNow,greenNew)
      
      analogWrite(BLUEPIN, blueNow);
      analogWrite(REDPIN, redNow);
      analogWrite(GREENPIN, greenNow);
      delay(1);
    }
  }
  
  else{
    digitalWrite(REDPIN,0);     // Turn off red led
    digitalWrite(GREENPIN,0);  // Turn off green led
    digitalWrite(BLUEPIN,0);  // Tuen off blue led
  }
  
}
 if(digitalRead(pir) == LOW){  // If the sensor is off
                              // then 
 digitalWrite(sound, LOW);   // Turn off the soundSensor 
 }
  
}
