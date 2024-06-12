#include <Servo.h>

 
Servo myservo;
const int trigPin = 3;
const int echoPin = 2;
const int mo1_for = 8;
//const int mo1_rev = 12;
const int mo2_for = 6;
//const int mo2_rev = 10;
const int ldr = 10;
const int servo = 9;
const int ir = 7;

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
  int ldr_output = digitalRead(ldr);
  int ir_output = digitalRead(ir);
  for (int pos = 0; pos <= 180; pos += 1) { // Rotate servo from 0 to 180 degrees
    myservo.write(pos); // Set servo position
    delay(15); // Delay for smooth rotation
    int distance = getDistance();
    int y = ldr_output;
    if(y==1){
      Serial.println("Light not enough shutting down all systems");
      break;
    } 
    int z = ir_output;
    if(z==0){
      stop();
      delay(2000);
      left();
      delay(200);
    }// Check distance during rotation
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
    int y = ldr_output;
    if(y==1){
      Serial.println("Light not enough shutting down all systems");
      break;
    }
    int z = ir_output;
    if(z==0){
      stop();
      delay(2000);
      left();
      delay(500);
    }
    
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


void setup() {
  pinMode(mo1_for, OUTPUT);
  //pinMode(mo1_rev, OUTPUT);
  pinMode(mo2_for, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //pinMode(mo2_rev, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(ir,INPUT);
  myservo.attach(servo);
  
  Serial.begin(9600);
}

void right() {
  //digitalWrite(mo1_rev, HIGH);
  digitalWrite(mo2_for, HIGH);
  digitalWrite(mo1_for, LOW);
  //digitalWrite(mo2_rev, LOW);
}

void left() {
  digitalWrite(mo1_for, HIGH);
  //digitalWrite(mo2_rev, HIGH);
  //digitalWrite(mo1_rev, LOW);
  digitalWrite(mo2_for, LOW);
}

void st() {
  digitalWrite(mo1_for, HIGH);
  digitalWrite(mo2_for, HIGH);
  //digitalWrite(mo1_rev, LOW);
  //digitalWrite(mo2_rev, LOW);
}

void stop() {
  digitalWrite(mo1_for, LOW);
  digitalWrite(mo2_for, LOW);
  //digitalWrite(mo1_rev, LOW);
  //digitalWrite(mo2_rev, LOW);
}

void rev() {
  digitalWrite(mo1_for, LOW);
  digitalWrite(mo2_for, LOW);
  //digitalWrite(mo1_rev, HIGH);
  //digitalWrite(mo2_rev, HIGH);
}

void loop() {
  int duration, cm, ldr_output , ir_output;
  ir_output = digitalRead(ir);
   
 
  ldr_output = digitalRead(ldr);
  // Following Lines is with respect to magnetometer module i.e. at certain co-ordinates it will pick up and servoPickedup will become true 
  /*if (!servoPickedUp) {
    pick_up();  
    servoPickedUp = true;  
  }

  

  delay(100); 
}*/
  
  if (ldr_output == 1) {
     
    stop();
    Serial.println("It's Getting Darker, Shutting Down All SYstems");
     
  }
  else{
    st();
    
    int z = ir_output;
    if(z==0){
      stop();
      delay(2000);
      left();
      delay(800);
    }
    else{
    int distance = getDistance();

    if (distance < 20) {
      stop();
      delay(1000);
     
      myservo.write(75);
      Serial.println("Waiting For Instructions");
      Serial.println("Good to go");
      //delay(3000);
    
      
  } 
    else {
    rotateServo();
    
  }
}

}
}
  
   


 
 