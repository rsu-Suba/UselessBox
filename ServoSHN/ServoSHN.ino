#include <Servo.h>

Servo servo1;
Servo servo2;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  servo2.attach(10);   //スイッチ用
}
void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(180);
  servo2.write(0);
  delay(500);
  servo1.write(0);
  servo2.write(180);
  delay(500);
}
