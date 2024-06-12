#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
 

 
int index = 0;
bool occupancy1 = false;
bool occupancy11 = false;
const int led_p1=3;
const int led_p11=7;
int slots_left = 10;
int slots_right = 10;
bool detection = false;
int entry_pin = 2;
int exit_pin = 13;
int parkus1 = 4;
int parkus11 = 8;
int Distancearray[2] = {0, 0};
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 0, NEO_GRB + NEO_KHZ800);
Servo entry_servo1;
Servo entry_servo2;
Servo exit_servo1;
Servo exit_servo2;
Adafruit_LiquidCrystal lcd_2(0);

float Distance(int x) {
  pinMode(x, OUTPUT);
  digitalWrite(x, LOW);
  delayMicroseconds(2);
  digitalWrite(x, HIGH);
  delayMicroseconds(10);
  digitalWrite(x, LOW);
  pinMode(x, INPUT);
  float duration = pulseIn(x, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

bool isConstantDistance(int pin, float& constantDistance) {
  float total = 0;
  for (int i = 0; i < 5; i++) {
    float reading = Distance(pin);
    total += reading;
    delay(50);   
  }
  constantDistance = total / 5;
  return true;
}

int going_leaving(int pin) {
  float constantDistance;
  if (isConstantDistance(pin, constantDistance)) {
    Distancearray[index] = constantDistance;
    index = (index + 1) % 2;

    if (index == 0) {
      float diff = Distancearray[1] - Distancearray[0];
      if (diff > 5) {
        return 1; // Leaving
      } else if (diff < -5) {
        return 0; // Going
      }
    }
  }
  return -1;  
}

void setup() {
  pinMode(led_p1,OUTPUT);
  pinMode(led_p11,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(entry_pin, OUTPUT);
  pinMode(exit_pin, OUTPUT);
  pinMode(parkus1, OUTPUT);
  Serial.begin(9600);
  entry_servo1.attach(6);
  entry_servo2.attach(5);
  exit_servo1.attach(11);
  exit_servo2.attach(10);
  lcd_2.setBacklight(1);
  lcd_2.begin(16, 2);
  entry_servo1.write(92);
  entry_servo2.write(92);
  exit_servo2.write(92);
  exit_servo2.write(92);
  //strip.begin();
  //strip.show();
  lcd_2.print("System Ready");
  lcd_2.setCursor(0, 1);
  lcd_2.print("Capacity : 20");
}

/*void setColor(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}*/

int detect(int x, int u) {
  int y = Distance(x);
  if (u == 1) {
    if (y < 300) {
      return 1;
    } else {
      return 0;
    }
  } else if (u == 2) {
    if (y < 100) {
      return 1;
    } else {
      return 0;
    }
  }
  return 0;
}

int slot_left = 10;
int slot_right = 10;

void loop() {
  int g = analogRead(A0);
  Serial.println(g);
  int y = detect(entry_pin, 1);
  int p = detect(parkus1, 1); // 1 for incoming
  int q = detect(parkus1, 2); // 2 for leaving

  // Handle entry detection
  if (y == 1 && !detection) {
    lcd_2.clear();
    lcd_2.print("Stop Here!!!");
    lcd_2.setCursor(11,0);
    lcd_2.print("L");
    lcd_2.print("  ");
    lcd_2.print("R");
    
    lcd_2.setCursor(0, 1);
    lcd_2.print("Slots Left:");
    lcd_2.print(slot_left);
    lcd_2.print(" ");
    lcd_2.print(slot_right);
    detection = true;
    delay(1000);
    if (slot_left > slot_right) {
      lcd_2.clear();
      lcd_2.print("Move Left <--");
      entry_servo1.write(0);
      delay(2000);
      entry_servo1.write(92);
    }
    else{
      lcd_2.clear();
      lcd_2.print("Move Right -->");
      entry_servo2.write(0);
      delay(2000);
      entry_servo2.write(92);
    }
  } else if (y == 0 && detection) {
    int x ; 
    lcd_2.clear();
    detection = false;
  }
    while (y==0 && !detection){
      int z = detect(parkus1,1);
      int d = detect(parkus11,1);
      int m = detect(entry_pin,1);
      int k = detect(exit_pin,1);
      if((z==1 && !occupancy1) ){
        digitalWrite(led_p1,HIGH);
        slot_left--;
        occupancy1=true;
        lcd_2.clear();
        lcd_2.print("P1 Occupied");
        delay(1000);
        lcd_2.clear();
        lcd_2.print("Welcome");
         
        lcd_2.setCursor(0,1);
        lcd_2.print("Slots Left:");
        lcd_2.print(slot_left);
        lcd_2.print(" ");
        lcd_2.print(slot_right);
        lcd_2.setCursor(11,0);
        lcd_2.print("L");
        lcd_2.print("  ");
        lcd_2.print("R");
        delay(2000);
        
      }
      if((d==1 && !occupancy11) ){
        digitalWrite(led_p11,HIGH);
        slot_right--;
        occupancy11=true;
        lcd_2.clear();
        lcd_2.print("P11 Occupied");
        delay(1000);
        lcd_2.clear();
        lcd_2.print("Welcome");
        lcd_2.setCursor(0,1);
        lcd_2.print("Slots Left:");
        lcd_2.print(slot_left);
        lcd_2.print(" ");
        lcd_2.print(slot_right);
        lcd_2.setCursor(11,0);
        lcd_2.print("L");
        lcd_2.print("  ");
        lcd_2.print("R");
        delay(2000);
        
      }
      if(m==1){
        break;

      }
      if(z==0 && occupancy1){
        lcd_2.clear();
        lcd_2.print("P1 Vacated");
        delay(5000);
        digitalWrite(led_p1,LOW);
        
        while(z==0){
          int h = detect(exit_pin,1);
          int p = detect(entry_pin,1); 
          if(h==1){
            lcd_2.clear();
            slot_left++;
            lcd_2.print("Thanks 4 Coming");
            exit_servo1.write(0);
            exit_servo2.write(0);
            delay(2000);
            exit_servo1.write(92);
            exit_servo2.write(92);
            delay(1000);
            lcd_2.clear();
            
            lcd_2.setCursor(0,1);
            lcd_2.print("Slots Left:");
            lcd_2.print(slot_left);
            lcd_2.print(" ");
            lcd_2.print(slot_right);
            lcd_2.setCursor(11,0);
            lcd_2.print("L");
    		lcd_2.print("  ");
    		lcd_2.print("R");
            delay(2000);
            occupancy1=false;
            break;
          }
          else if(p==1){
            break;
          }
          
        }
        
        
        
      }
      if(d==0 && occupancy11){
        lcd_2.clear();
        lcd_2.print("P11 Vacated");
        delay(5000);
        digitalWrite(led_p1,LOW);
        
        while(d==0){
          int h = detect(exit_pin,1);
          int p = detect(entry_pin,1); 
          if(h==1){
            lcd_2.clear();
            slot_right++;
            lcd_2.print("Thanks For Coming");
            exit_servo1.write(0);
            exit_servo2.write(0);
            delay(2000);
            exit_servo1.write(92);
            exit_servo2.write(92);
            lcd_2.clear();
            
            
            
            lcd_2.setCursor(0,1);
            lcd_2.print("Slots Left:");
        	lcd_2.print(slot_left);
        	lcd_2.print(" ");
        	lcd_2.print(slot_right);
            lcd_2.setCursor(11,0);
    		lcd_2.print("L");
    		lcd_2.print("  ");
    		lcd_2.print("R");
            delay(2000);
            occupancy11=false;
            break;
          }
          else if(p==1){
            break;
          }
          
        }
        
        
        
      }
      
      
    
  }

   
}
