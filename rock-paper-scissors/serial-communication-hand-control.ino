#include <Servo.h>
Servo servo1;
Servo servo2;

bool hand_retract = false;
bool hand_pull = false;
bool two_fingers = false;

void setup() {
  servo1.attach(9);
  servo2.attach(6);
  servo1.write(0);
  servo2.write(0);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'n') {
      servo1.write(0);
      servo2.write(0);
      hand_retract = false;
      hand_pull = false;
      two_fingers = false;
    } else if (command == 'p') {
      hand_retract = true;
      hand_pull = false;
      two_fingers = true;
    } else if (command == 's') {
      hand_retract = false;
      hand_pull = true;
      two_fingers = false;
    } else if (command == 'r') {
      hand_retract = false;
      hand_pull = false;
      two_fingers = false;
    }
  }

  if (hand_retract && !hand_pull && two_fingers) {
    
    servo1.write(0);
    servo2.write(180);
  } else if (!hand_retract && hand_pull && !two_fingers) {
     
    servo1.write(180);
    servo2.write(180);
  } else if (!hand_retract && !hand_pull && !two_fingers) {
     
    servo1.write(0);
    servo2.write(0);
  }
}
