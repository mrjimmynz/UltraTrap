/*Trap
  Distance activated Servo for trap.

   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   by Ian Curtis
 */

#include <Servo.h>
#include "Trap.h"

//Pin Numbers for the sensor's output.
#define ECHOPIN 7
#define TRIGPIN 8


Servo doorServo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin

void setup()
{
  doorServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  doorServo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 
