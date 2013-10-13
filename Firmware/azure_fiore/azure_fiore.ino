/*
azure fiore

Board:  Sparkfun Fio v3 with custom Shield

This project is to have a wearable necklace that will read in some sensors and send feedback to the user.  
The project is designed for a Sparkfun Fio v3 board with a custom PCB that plugs into the Fio.  This shield
will contain an RGB LED, several additional LEDs, and several sensors

*/

/*  Notes
A11 is the analog in for the battery level which uses a voltage divider setup for 5V
Serial1 is used for printing to the Bluetooth module
A13 is tied to the LED marked ON

*/

//Includes
#include <Wire.h>  //For the I2C library

//Defines
#define TRUE 1
#define FALSE 0

//Setup routine, initializes hardware
void setup() {
  //Configure LED pin
  pinMode(13, OUTPUT); 
  
  //Setup our serial communications
  //Debug port
  Serial.begin(19200);
  //Bluetooth port
  Serial1.begin(115200);
  
  digitalWrite(13,LOW);  //Turns off the LED
  Serial.println("Configuration complete");
}

//Main routine, loops forever...

void loop() {
  
  byte _status;
   
  digitalWrite(13,HIGH);  //Turns off the LED
  read_battery();
  delay(1000);
  Serial1.println("I'm alive");
  digitalWrite(13,LOW);  //Turns off the LED
}

float read_battery(void) {
  
   // read the input on analog pin A11 and calculate the voltage
  float sensorValue = analogRead(A11)*(3.3/1024)*2;
  // print out the value on the debug port
  Serial.println(sensorValue);
  Serial1.println(sensorValue);
  delay(10);     // delay in between reads for stability
  
  return sensorValue;
}

int read_light(void) {
  
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(10);
  
}

