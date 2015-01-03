/* Ping Sensor

   This sketch reads a ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.

   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 8
        * Echo connection of the Ping attached to digital pin 7

   http://www.arduino.cc/en/Tutorial/Ping

   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe
   modified 3 Jan 2014
   by Ian Curtis
 */
#include "Arduino.h"
 
/* Sets up the pins for the Ultrasonic Sensor */
void distanceSetup(unsigned int trigPin, unsigned int echoPin) {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

/*Detects the object and measures the Time for a return */
long measureDistance(unsigned int trigPin, unsigned int echoPin)
{
  // establish variables for duration of the ping,
  // and the distance result in centimeters:
  long duration, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //cm = microsecondsToCentimeters(duration);
  return duration;
}

/* Coverts Return Time to Distance in centimeters */
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

/*Gets the Distance of an object from the sensor*/
long takeDistance(unsigned int trigPin, unsigned int echoPin) 
{
  long time;
  time = measureDistance(trigPin, echoPin);
  return microsecondsToCentimeters(time);
}
