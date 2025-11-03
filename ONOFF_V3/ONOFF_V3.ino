#include <VarSpeedServo.h>

VarSpeedServo sh;
VarSpeedServo ss;
int all;
int ho;
int so;
bool sw;

void setup() {
  // put your setup code here, to run once:
  sh.attach(10);
  ss.attach(11);
  ho = 110;
  so = 90;
  all = 0;
  sh.write(180,255,true);
  ss.write(0,255,true);
}

void loop() {
  // put your main code here, to run repeatedly:
  sw = digitalRead(7);
  if (sw == 0){
    sh.write(ho,255,true);
    delay(300);
    ss.write(so,255,true);
  }
  else if (sw == 1){
    ss.write(0,255,true);
    delay(300);
    sh.write(180,255,true);
  }
}
