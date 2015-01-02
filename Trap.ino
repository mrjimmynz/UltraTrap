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

//Pin Numbers for the sensor's output.
#define ECHOPIN 7
#define TRIGPIN 8

void pingSetup(unsigned int trigPin, unsigned int echoPin) {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

long measureDistance()
{
  // establish variables for duration of the ping,
  // and the distance result in centimeters:
  long duration, cm;
  delay(100);
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  
  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
