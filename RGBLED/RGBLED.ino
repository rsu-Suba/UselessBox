void setup() {
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  s(0,0,0);
  delay(500);
  s(255,0,0);
  delay(500);
  s(0,255,0);
  delay(500);
  s(0,0,255);
  delay(500);
  s(255,255,255);
  delay(500);
}

void s(int red,int green,int blue){
  analogWrite(6,red);
  analogWrite(5,green);
  analogWrite(3,blue);
}
