
/*Trap
  Distance activated Servo for trap.

   The circuit:
	* +V connection of the Ping attached to +5V
	* GND connection of the PING attached to ground
	* SIG connection of the PING attached to digital pin 8
        * Echo connection of the Ping attached to digital pin 7
        * White of Servo Connected to Pin 9
        * Red of Servo Connected to 5v
        * Black of Servo Connected to Ground
        

   by Ian Curtis
 */

#include <Servo.h>
#include "Distance.h"
#include "Sleep.h"

//Pin Numbers for the sensor's output.
#define ECHOPIN 7
#define TRIGPIN 8
#define DETECTIONDISTANCE 10
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
  doorServo.write(MINPOSITION);
  //Setup the Distance Sensor
  distanceSetup(TRIGPIN, ECHOPIN);
  //Sets the Trap to untripped 
  tripped = false;
}

void loop() 
{ 
  long distance = 1000;
  tripCheck(tripped);
  //Measure Distance
  distance = measureDistance(TRIGPIN, ECHOPIN);
  detection(distance);
                           
}

/*Checks to see if Trap has been tripped if so enters infinite loop*/
void tripCheck(bool tripped)
{
  if (tripped)
  {
    sleepNow();
    while(1);
  }
}

/*Checks Distances and Trips if something detected*/
void detection(long distance)
{
  if (distance < DETECTIONDISTANCE)
  {
    doorServo.write(MAXPOSITION);
    tripped = true;
  }
  else
  {
    delay(100);
  }
}
