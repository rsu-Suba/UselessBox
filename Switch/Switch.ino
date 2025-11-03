void setup() {
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(7));
  if (digitalRead(7) == 0){
    delay(50);
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
  else if (digitalRead(7) == 1){
    s(0,0,0);
  }
}

void s(int red,int green,int blue){
  analogWrite(6,red);
  analogWrite(5,green);
  analogWrite(3,blue);
}
