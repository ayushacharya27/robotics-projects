/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep

*/

#include <Servo.h>
int trigPin=4;
int echoPin=2;
bool object;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
  long microsecondsToCentimeters(long microseconds) {
      // The speed of sound is 340 m/s or 29 microseconds per centimeter.
      // The ping travels out and back, so to find the distance of the object we
      // take half of the distance travelled.
      return microseconds / 29 / 2;
    }   // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
int ultra_sonic(){
  int duration,inches,cm;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
   
  cm = microsecondsToCentimeters(duration);
  return cm;
}

void loop() {
  int y = ultra_sonic();

  if(y<19){
    object = true;
  }
  else{
    object = false;
  }
  if(!object){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    int x = ultra_sonic();
    if(x<19){
      break;
    }

                         // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    int x = ultra_sonic();
    if(x<19){
      break;
    }                     // waits 15 ms for the servo to reach the position
  }
  }
  else{
    delay(1000);
    myservo.write(75);

  }
}
