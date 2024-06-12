// 1st Seven Segment Display
int a = 10;
int b = 11;
int c = 12;
int d = 13;
int e = 0;
int f = 9;
int g = 8;
// 2nd Seven Segment Display
int a2 = 5;
int b2 = 4;
int c2 = 1;
int d2 = 2;
int e2 = 3;
int f2 = 6;
int g2 = 7;

int digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, 
  {0, 1, 1, 0, 0, 0, 0},  
  {1, 1, 0, 1, 1, 0, 1},  
  {1, 1, 1, 1, 0, 0, 1},  
  {0, 1, 1, 0, 0, 1, 1},  
  {1, 0, 1, 1, 0, 1, 1},  
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},  
  {1, 1, 1, 1, 1, 1, 1},  
  {1, 1, 1, 1, 0, 1, 1}   
};

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(f2, OUTPUT);
  pinMode(g2, OUTPUT);
}

void loop() {
  for (int i = 9; i >= 0; i--) {
    displayDigit2(digits[i]);
     
    for (int j = 9; j >= 0; j--) {
      displayDigit(digits[j]);
      delay(1000);
    }
  }
}

void displayDigit(int segments[]) {
  digitalWrite(a, segments[0]);
  digitalWrite(b, segments[1]);
  digitalWrite(c, segments[2]);
  digitalWrite(d, segments[3]);
  digitalWrite(e, segments[4]);
  digitalWrite(f, segments[5]);
  digitalWrite(g, segments[6]);
}

void displayDigit2(int segments[]) {
  digitalWrite(a2, segments[0]);
  digitalWrite(b2, segments[1]);
  digitalWrite(c2, segments[2]);
  digitalWrite(d2, segments[3]);
  digitalWrite(e2, segments[4]);
  digitalWrite(f2, segments[5]);
  digitalWrite(g2, segments[6]);
}
