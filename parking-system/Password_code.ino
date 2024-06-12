#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>
//#include <Adafruit_NeoPixel.h>
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(4,4,NEO_GRB+NEO_KHZ800);
#include <Servo.h>
Adafruit_LiquidCrystal lcd_1(0);
Servo servo1;
Servo servo2;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char* password = "ABCD";
byte index = 0;
char pass[10];  

void setup() {
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  //strip.begin();
  //strip.show();
  Serial.begin(9600);
  lcd_1.setBacklight(1);
  lcd_1.begin(16, 2);
  servo1.attach(5);
  servo2.attach(4);
  servo1.write(92);
  servo2.write(92);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  //setColor(strip.Color(255, 0, 0));//RED COLOR
  lcd_1.print("Enter Your");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Password....");
   
  
}

void loop() {
  char key = keypad.getKey();
  float Ambient = (analogRead(A0) ) ;
  analogWrite(3,Ambient);
  Serial.println(Ambient);
  
  
  if (key) {
    if (index==0){
    lcd_1.clear();
    }
    if (key == '#') {
      pass[index] = '\0';
      if (strcmp(password, pass) == 0) {
        lcd_1.clear();
        //setColor(strip.Color(0, 255, 0));//GREEN COLOR
        servo1.write(0);
        servo2.write(0);
          
        lcd_1.print("Acess Granted"); 
        delay(5000);
        lcd_1.clear();
        lcd_1.print("Enter Your");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Password....");
         
        
        servo1.write(92);
        servo2.write(92);
        //setColor(strip.Color(255, 0, 0));//RED COLOR
             
      } else {
        lcd_1.clear();
        //setColor(strip.Color(255, 0, 0));//RED COLOR
        servo1.write(92);
        servo2.write(92);
        
        
        lcd_1.print("Please Retry");
        delay(1000);
        lcd_1.clear();
        lcd_1.print("Enter Your");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Password....");
             
      }
      index = 0;
      delay(100);  
    } else {
      //lcd_1.clear();
      if (index < 7) {
        lcd_1.setCursor(index, 0);
        //setColor(strip.Color(255, 0, 0));//RED COLOR
        lcd_1.print("*");
        pass[index] = key;
        index++;
      } else {
        lcd_1.clear();
         
        lcd_1.print("Password too");
        lcd_1.setCursor(0, 1);\
        lcd_1.print("Long....");
        delay(2000);
        lcd_1.clear();
        lcd_1.print("Please Retry");
        delay(1000);
        lcd_1.clear();
        lcd_1.print("Enter Your");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Password....");
        
      }
    }
  }
}
/*void setColor(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}*/
