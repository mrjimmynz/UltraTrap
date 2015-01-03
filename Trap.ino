/*Trap
  Distance activated Servo for trap.

   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   by Ian Curtis
 */

#include <Servo.h>
#include "Distance.h"

//Pin Numbers for the sensor's output.
#define ECHOPIN 7
#define TRIGPIN 8
//Servo Defines
#define SERVOPIN 9
#define MAXPOSITION 180
#define MINPOSITION 0

Servo doorServo;  // create servo object to control a servo

bool tripped;    // variable to read the value from the analog pin

void setup()
{
  // attaches the servo on pin 9 to the servo object
  doorServo.attach(SERVOPIN);
  //Setup the Distance Sensor
  distanceSetup(unsigned int trigPin, unsigned int echoPin);
  //Sets the Trap to untripped 
  tripped = false;
}

void loop() 
{ 
  doorServo.write(180);                  // sets the servo position o the scaled value 
                           
} 
