#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void loop() {
  int duration, cm, ldr_output;
  digitalWrite(4, LOW);
  delayMicroseconds(2);
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  duration = pulseIn(2, HIGH);
  
  cm = microsecondsToCentimeters(duration);
  Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Distance (cm): ");
  Serial.println(cm);

  for (pos = 0; pos <= 190; pos += 1) {
    myservo.write(pos);
    delay(70);
  }
  for (pos = 190; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(70);
  }

  Serial.println(cm); // Make sure this line is not commented out if you want cm to be printed continuously
  
   // Adjust delay as needed
}
