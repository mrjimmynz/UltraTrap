   
/*Trap
  Distance activated Servo for trap.

   The circuit:
	* +V connection of the Ping attached to +5V
	* GND connection of the PING attached to ground
	* SIG (trig) connection of the PING attached to digital pin 9
        * Echo connection of the Ping attached to digital pin 8
        * White of Servo Connected to Pin 10
        * Red of Servo Connected to 5v
        * Black of Servo Connected to Ground
   by Ian Curtis
 */

#include <Servo.h>
#include "Distance.h"
#include "Sleep.h"

//Pin Numbers for the sensor's output.
#define ECHOPIN 8
#define TRIGPIN 9
#define DETECTIONDISTANCE 10
//Servo Defines
#define SERVOPIN 10
#define MAXPOSITION 179
#define MINPOSITION 1

Servo doorServo;  // create servo object to control a servo

bool tripped;    // variable to read the value from the analog pin

void setup()
{
  /******************
  debugging
  *******************/
  Serial.begin(9600);
  Serial.print(doorServo.read());
   /******************/
  // attaches the servo on pin 9 to the servo object
  doorServo.attach(SERVOPIN);
  doorServo.write(MINPOSITION);
  //Serial.print(doorServo.read());
  //Setup the Distance Sensor
  distanceSetup(TRIGPIN, ECHOPIN);
  //Sets the Trap to untripped 
  tripped = false;
}

void loop() 
{ 
  long distance = 1000;
  
  //Measure Distance
  distance = takeDistance(TRIGPIN, ECHOPIN);
  /******************
  Debugging
  *******************/
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  /*******************/
  detection(distance);
  tripCheck(tripped);
                           
}

/*Checks to see if Trap has been tripped if so enters infinite loop*/
void tripCheck(bool tripped)
{
  if (tripped)
  {
    delay(10000);
    sleepNow();
    while(1);
  }
}

/*Checks Distances and Trips if something detected*/
void detection(long distance)
{
  if (distance < DETECTIONDISTANCE && distance > 0)
  {
    doorServo.write(MAXPOSITION);
    tripped = true;
  }
  else
  {
    delay(100);
  }
}
