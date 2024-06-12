const int trigPin = 4;
const int echoPin = 2;
bool plain_road=false;
int debounce_counter=0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(3,INPUT);
  
  // put your setup code here, to run once:

}
void turn_right(){
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(8,LOW);
}
void turn_left(){
  digitalWrite(12,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(7,LOW);
}
void move_straight(){
  digitalWrite(13,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(12,LOW);
}
void stop(){
  digitalWrite(13,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(12,LOW);

}
void reverse(){
  digitalWrite(13,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(12,HIGH);

}

void loop() {
  int duration,inches,cm;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  if(cm>1 && cm<10){
    turn_right();
    delay(500);
    move_straight();
    delay(500);
    stop();
    delay(20000);
  }
   
   
  
  int sensor_value=digitalRead(3);
  for(int i=0;i<10;i++){
    if(digitalRead(3)==sensor_value){
      debounce_counter++;
    }
    delay(5);
  }

  if(debounce_counter>=8){
    if(sensor_value==LOW){
      plain_road=true;

    }
    else{
      plain_road=false;
    }
  }
  if(plain_road){
    move_straight();
  }
   
  
   

  



  // put your main code here, to run repeatedly:

}
long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}

