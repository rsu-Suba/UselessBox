#include <Servo.h>

Servo servo2;
void setup() {
  // put your setup code here, to run once:
  servo2.attach(11);   //スイッチ用
    servo2.write(180);
  delay(500);
}
void loop() {
  // put your main code here, to run repeatedly:
  servo2.write(0);
  delay(500);
  servo2.write(180);
  delay(500);
}
