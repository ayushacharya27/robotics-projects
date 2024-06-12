#include <Servo.h>

int trigPin = 1;
int echoPin = 0;
Servo myservo;
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int distance = getDistance();

  if (distance < 20) {
     // Adjust this threshold according to your needs
    myservo.write(75); delay(3000);// Position the servo at 90 degrees when object is detected
      // Wait for one second
  } else {
    rotateServo();
   // Rotate the servo continuously
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Convert duration to distance in centimeters
  return distance;
}

void rotateServo() {
  for (int pos = 0; pos <= 180; pos += 1) { // Rotate servo from 0 to 180 degrees
    myservo.write(pos); // Set servo position
    delay(15); // Delay for smooth rotation
    int distance = getDistance(); // Check distance during rotation
    if (distance < 20) {
      Serial.print("Object Detected at distance ");
    Serial.print(distance);
    Serial.print(" at an angle ");
    Serial.print(pos);
    Serial.print(" Degrees");
    if(pos<90){
      Serial.println(" to the left");
    }
    else{
      Serial.println(" to the right");
    } // If object detected, break the loop
      break;
    }
    for (int pos = 180; pos <= 0; pos -= 1) { // Rotate servo from 0 to 180 degrees
    myservo.write(pos); // Set servo position
    delay(15); // Delay for smooth rotation
    int distance = getDistance();
    
    // Check distance during rotation
    if (distance < 20) {
      Serial.print("Object Detected at distance ");
    Serial.print(distance);
    Serial.print(" at an angle ");
    Serial.print(pos);
    Serial.print(" Degrees");
    if(pos<90){
      Serial.println(" to the left");
    }
    else{
      Serial.println(" to the right");
    } // If object detected, break the loop
      break;
    }
  }
 
}
 
}
