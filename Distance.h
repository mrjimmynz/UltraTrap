#ifndef DISTANCE_H
#define DISTANCE_H
/* Ping Sensor

   This sketch reads a ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.

   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   http://www.arduino.cc/en/Tutorial/Ping

   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe
   modified 3 Jan 2014
   by Ian Curtis
 */


/* Sets up the pins for the Ultrasonic Sensor */
void pingSetup(unsigned int trigPin, unsigned int echoPin);

/*Detects the object and measures the Time for a return */
long measureDistance();

/* Coverts Return Time to Distance in centimeters */
long microsecondsToCentimeters(long microseconds);

#endif //DISTANCE_H
