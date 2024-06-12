void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
   

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
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0){
    char command = Serial.read();
    if (command == 'w'){
      move_straight();
    }
    else if (command == 'd'){
      turn_left();
    }
    else if (command == 'a'){
      turn_right();
    }
    else if (command == 'm'){
      stop();
    }
    else if (command == 's'){
      reverse();

    }
    
  }
   

}
