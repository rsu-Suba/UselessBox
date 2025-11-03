#include <Servo.h>

Servo servos;
Servo servoh;
int all;
int mode;
int rgb;
int r;
int g;
int b;
int eh;
int es;
int sh;
int ss;
bool ok = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servos.attach(11);
  servoh.attach(10);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,INPUT);
  all = 0;
  mode = 1;
  eh = 70;
  es = 110;
  sh = 0;
  ss = 0;
  servos.write(ss);
  servoh.write(sh);
  s(255,255,255);
  delay(500);
  s(0,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (all >= 30&& all <= 79){
    rgbr();
  }
  else if (all == 80){
    s(0,0,255);
  }
  if (digitalRead(7) == 1){
    ok = true;
    servoh.write(sh);
    servos.write(ss);
    if (all >= 0 && all < 30){
      s(0,0,0);
    }
  }
  if (digitalRead(7) == 0){
    delay(50);
    if (ok == true){
      ok = false;
      if (all < 180){
        all++;
      }
      else if (all == 180){
        all = 0;
      }
      Serial.println(all);
    }
    if (all >= 0 && all < 30){
      v1();
    }
    else if (all >= 30 && all < 80){
      v2();
    }
    else if (all >= 80 && all <= 180){
      v3();
    }
  }
}

void v1(){
  s(0,200,0);
  servoh.write(eh);
  delay(300);
  servos.write(es);
  delay(300);
  if (digitalRead(7) == 1){
    servos.write(ss);
    delay(300);
    if (digitalRead(7) == 0){
      all++;
      v1();
    }
    else if (digitalRead(7) == 1){
      servoh.write(sh);
      s(0,0,0);
    }
  }
  delay(100);
}

void v2(){
  if (mode == 1){
    servoh.write(eh);
    delay(500);
    servos.write(es);
    delay(500);
    servoh.write(sh);
    delay(500);
    servos.write(ss);
    mode++;
  }
  else if (mode = 2){
    servoh.write(eh);
    delay(250);
    servos.write(es);
    delay(150);
    servos.write(ss);
    delay(250);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 3){
    servoh.write(eh);
    delay(1000);
    servoh.write(sh);
    delay(1000);
    servoh.write(eh);
    delay(150);
    servos.write(es);
    delay(150);
    servos.write(ss);
    delay(150);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 4){
    servoh.write(eh);
    delay(350);
    servos.write(80);
    delay(500);
    servos.write(65);
    delay(300);
    servos.write(es);
    delay(200);
    servos.write(ss);
    delay(300);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 5){
    delay(5000);
    servoh.write(eh);
    delay(250);
    servos.write(es);
    delay(250);
    servos.write(ss);
    delay(250);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 6){
    servoh.write(eh);
    delay(2000);
    servos.write(es);
    delay(2000);
    servos.write(ss);
    delay(2000);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 7){
    servoh.write(eh);
    delay(300);
    servos.write(es);
    delay(250);
    servos.write(65);
    delay(500);
    servos.write(es);
    delay(1500);
    servos.write(ss);
    delay(250);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 8){
    servoh.write(50);
    delay(150);
    servoh.write(10);
    delay(150);
    servoh.write(eh);
    delay(150);
    servoh.write(30);
    delay(150);
    servoh.write(55);
    delay(150);
    servoh.write(25);
    delay(150);
    servoh.write(eh);
    delay(200);
    servos.write(es);
    delay(250);
    servos.write(ss);
    delay(200);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 9){
    servoh.write(eh);
    delay(350);
    servos.write(100);
    delay(150);
    servos.write(90);
    delay(150);
    servos.write(100);
    delay(150);
    servos.write(70);
    delay(150);
    servos.write(90);
    delay(150);
    servos.write(100);
    delay(150);
    servos.write(95);
    delay(150);
    servos.write(es);
    delay(150);
    servos.write(ss);
    delay(200);
    servoh.write(sh);
    mode++;
  }
  else if (mode == 10){
    servoh.write(50);
    delay(150);
    servoh.write(10);
    delay(150);
    servoh.write(eh);
    delay(150);
    servoh.write(30);
    delay(150);
    servoh.write(55);
    delay(150);
    servoh.write(25);
    delay(150);
    servoh.write(eh);
    delay(250);
    servos.write(75);
    servoh.write(80);
    delay(150);
    servoh.write(eh);
    delay(100);
    servos.write(90);
    delay(150);
    servoh.write(60);
    delay(100);
    servos.write(100);
    delay(150);
    servos.write(70);
    servoh.write(70);
    delay(150);
    servos.write(es);
    delay(150);
    servos.write(95);
    delay(150);
    servos.write(95);
    delay(150);
    servos.write(es);
    delay(150);
    servos.write(ss);
    delay(350);
    servoh.write(sh);
    delay(150);
    servoh.write(40);
    delay(150);
    servoh.write(25);
    delay(150);
    servoh.write(35);
    delay(150);
    servoh.write(sh);
    mode = 1;
  }
  if (all == 79){
    servoh.write(eh);
    s(0,0,250);
    delay(200);
    servos.write(80);
  }
}

void v3(){
  s(0,0,250);
  servos.write(es);
  if (digitalRead(7) == 1){
    delay(75);
    servos.write(80);
  }
}

void s(int red, int green, int blue){
  analogWrite(6,red);
  analogWrite(5,green);
  analogWrite(3,blue);
}

void sr(){
  analogWrite(6,r);
  analogWrite(5,g);
  analogWrite(3,b);
}

void rgbr(){
  delay(40);
  r = 0;
  g = 0;
  b = 0;
  sr();
  delay(40);
  rgb = random(1,5);
  if (rgb == 1){
    r = 255;
  }
  else if (rgb == 2){
    g = 255;
  }
  else if (rgb == 3){
    b = 255;
  }
  else if (rgb == 4){
    r = 255;
    g = 255;
    b = 255;
  }
  sr();
}
