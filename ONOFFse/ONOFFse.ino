#include <Servo.h>

Servo servos;
int all;
int mode;
int es;
int ss;
bool ok = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servos.attach(9);
  pinMode(12,OUTPUT);
  pinMode(7,INPUT);
  all = 0;
  mode = 1;
  es = 129;
  ss = 0;
  servos.write(ss);
  digitalWrite(12,LOW);
}

void loop() {
  Serial.println(digitalRead(7));
  // put your main code here, to run repeatedly:
  if (digitalRead(7) == 0){
    if (ok == true){
      ok = false;
      if (all >= 140){
        all = 0;
      }
      Serial.println(all);
    }
    if (all >= 0 && all <= 19){
      v1();
    }
    else if (all >= 20 && all <= 60){
      v2();
    }
    else if (all >= 61 && all <= 140){
      v3();
    }
  }
  else if (digitalRead(7) == 1){
    ok = true;
    servos.write(ss);
  }
}

void v1(){
  digitalWrite(12,HIGH);
  servos.write(es);
  delay(750);
  if (digitalRead(7) == 1){
    servos.write(ss);
    delay(300);
    if (digitalRead(7) == 0){
      all++;
      v1();
    }
    else if (digitalRead(7) == 1){
      servos.write(ss);
    }
  }
  else if (digitalRead(7) == 0){
    all++;
    v1();
  }
  delay(50);
  digitalWrite(12,LOW);
}

void v2(){
  if (mode == 1){
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(500);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode = 2){
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(150);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 3){
    digitalWrite(12,HIGH);
    servos.write(70);
    delay(150);
    servos.write(es);
    delay(150);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 4){
    digitalWrite(12,HIGH);
    servos.write(80);
    delay(500);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(65);
    delay(300);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(200);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 5){
    digitalWrite(12,LOW);
    servos.write(es);
    delay(250);
    servos.write(ss);
    digitalWrite(12,LOW);
    delay(1000);
    digitalWrite(12,LOW);
    servos.write(es);
    delay(2000);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 6){
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(2000);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 7){
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(250);
    servos.write(65);
    digitalWrite(12,LOW);
    delay(500);
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(1500);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 8){
    digitalWrite(12,HIGH);
    servos.write(65);
    digitalWrite(12,LOW);
    delay(250);
    digitalWrite(12,HIGH);
    servos.write(85);
    digitalWrite(12,LOW);
    delay(250);
    digitalWrite(12,HIGH);
    servos.write(25);
    digitalWrite(12,LOW);
    delay(250);
    digitalWrite(12,HIGH);
    servos.write(es);
    delay(250);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 9){
    digitalWrite(12,HIGH);
    servos.write(100);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(90);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(100);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(70);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(90);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(100);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(95);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(es);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode++;
    all++;
  }
  else if (mode == 10){
    digitalWrite(12,HIGH);
    servos.write(75);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(90);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(100);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(70);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(es);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(95);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(95);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(es);
    digitalWrite(12,LOW);
    delay(150);
    digitalWrite(12,HIGH);
    servos.write(ss);
    digitalWrite(12,LOW);
    mode = 1;
    all++;
  }
  if (digitalRead(7) == 0){
    all++;
    v2();
  }
  if (all == 61){
    servos.write(80);
    digitalWrite(12,HIGH);
  }
}

void v3(){
  servos.write(es);
  if (digitalRead(7) == 1){
    delay(75);
    servos.write(80);
  }
  all++;
}
