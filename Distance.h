#ifndef DISTANCE_H
#define DISTANCE_H
/* Distance Sensor
  Header file for the Distance sensor with metric Values only
   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   http://www.arduino.cc/en/Tutorial/Ping

   created 3 Jan 2014
   by Ian Curtis
 */


/* Sets up the pins for the Ultrasonic Sensor */
void distanceSetup(unsigned int trigPin, unsigned int echoPin);

/*Detects the object and measures the Time for a return */
long measureDistance();

/* Coverts Return Time to Distance in centimeters */
long microsecondsToCentimeters(long microseconds);

/*Gets the Distance of an object from the sensor*/
long takeDistance();

#endif //DISTANCE_H
