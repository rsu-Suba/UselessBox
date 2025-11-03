#include <VarSpeedServo.h>

VarSpeedServo servos;
VarSpeedServo servoh;
int mode;
int ss;
int sh;
int es;
int eh;
int ee;
int r;
int g;
int b;
bool ok = true;

void setup(){
  Serial.begin(9600);
  servos.attach(11);
  servoh.attach(10);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,INPUT);
  mode = 1;
  eh = 105;
  es = 104;
  ee = 105;
  sh = 175;
  ss = 0;
  servos.write(ss,255,true);
  servoh.write(sh,255,true);
}

void loop(){
  Serial.print(digitalRead(7));
  Serial.println(mode);
  if (digitalRead(7) == 0){
    s(255,0,0);
    m1();
  }
}
void m1(){
   if (mode == 1){
    servoh.write(eh,255,false);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(ee,255,true);
    servos.write(60,255,true);
    servos.write(es,240,true);
    if (digitalRead(7) == 1){
      mode += 1;
      servos.write(ss,255,false);
      servoh.write(sh,255,false);
    }
   }
   else if (mode == 2){
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,false);
    servos.write(es,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    if (digitalRead(7) == 1){
      mode += 1;
      servos.write(ss,255,false);
      servoh.write(sh,255,false);
    }
   }
   else if (mode == 3){
    servoh.write(eh,255,true);
    delay(400);
    servoh.write(sh,255,true);
    delay(400);
    servoh.write(eh,255,true);
    delay(400);
    servoh.write(sh,255,true);
    delay(400);
    servoh.write(eh,255,true);
    delay(400);
    servoh.write(sh,255,true);
    delay(400);
    servoh.write(eh,255,true);
    delay(400);
    servoh.write(sh,255,true);
    delay(400);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servoh.write(sh,255,true);
    servoh.write(eh,255,true);
    servos.write(es,255,true);
    delay(400);
    servos.write(ss,255,true);
    delay(400);
    servos.write(es,255,true);
    delay(400);
    servos.write(ss,255,true);
    delay(400);
    servos.write(es,255,true);
    delay(400);
    servos.write(ss,255,true);
    delay(400);
    servos.write(es,255,true);
    delay(400);
    servos.write(ss,255,true);
    delay(400);
    servoh.write(sh,255,true);
    if (digitalRead(7) == 1){
      mode = 1;
    }
   }
   s(0,0,0);
}

void s(int red, int green, int blue){
  analogWrite(3,red);
  analogWrite(5,green);
  analogWrite(6,blue);
}
