#include <Servo.h>

Servo myservo;
int pos = 0;
bool servoPickedUp = false; // Flag variable to track servo position

void setup() {
  myservo.attach(6);
}

void loop() {
  if (!servoPickedUp) {
    pick_up();  
    servoPickedUp = true;  
  }

  

  delay(100); 
}

void pick_up() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
}
