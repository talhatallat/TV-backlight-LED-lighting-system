/*
  Program: The aim of the project is to program Arduino Nano 
  to read Microphone sensor values varrying from 0-255 to 
  control 12v LED output load arccrounding to the input read 
  Programmer: Talha Tallat
  Date: 01/05/2016
*/

int soundSensor = 2;  // Ideally read it from analogue inputs (0 - 1023) rater than digital
int LED = 3; // MOSFET is used to supply 12v because arduino only produces 5v out 

void setup() {
  // put your setup code here, to run once:
  pinMode (soundSensor, INPUT);
  pinMode (LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusSensor = digitalRead (soundSensor); //reads the sound sensor 
  if (statusSensor == 1) //if port 2 is high
  {
    digitalWrite(LED, HIGH); //then turn is on
  }
  else
  {
    digitalWrite(LED, LOW); //else turn it off
  }

}
