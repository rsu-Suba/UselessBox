#include <VarSpeedServo.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>

//ドットマトリクス
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW //デバイス種別
#define MAX_DEVICES 2     //8x8のマトリクス表示のユニット数
#define DATA_PIN  11      //DATA
#define CS_PIN    10      //CS
#define CLK_PIN   13      //CLK
MD_Parola dot = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);


VarSpeedServo servos;
VarSpeedServo servoh;
int all;
int mode;
int r;
int g;
int b;
int rgb;
int ss;
int sh;
int es;
int eh;
int mode = 1;
bool ok = true;

void setup(){
  Serial.begin(9600);
  s(255,255,255);
  servos.attach(11);
  servoh.attach(10);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,INPUT);
  all = 0;
  mode = 1;
  eh = 105;
  es = 100;
  sh = 175;
  ss = 0;
  servos.write(ss,255,true);
  servoh.write(sh,255,true);
  s(255,0,0);
  delay(300);
  s(0,255,0);
  delay(300);
  s(0,0 ,255);
  delay(300);
  s(255,255,255);
  delay(300);
  s(0,0,0);
  dot.displayReset();
  dot.begin();
  mode = 1;
}

void loop(){
  Serial.print(digitalRead(7));
  Serial.println(all);
  Serial.println(mode);
  if (all >= 20 && all <= 70){
    rgbR();
  }
   if (digitalRead(7) == 0){
    if (ok == true){
      ok = false;
      if (all >= 0 && all <= 19){
        s(0,255,0);
        m1();
      }
      else if (all >= 20 && all <= 60){
        s(255,255,255);
        m2();
      }
      else if (all >= 61 && all <= 140){
        s(255,0,0);
        servoh.write(eh,255,true);
        servos.write(75,255,true);
        m3();
      }
    }
  }
  else if (digitalRead(7) == 1){
    ok = true;
    if (all <= 70){
      servoh.write(sh,255,true);
      servos.write(ss,255,true);
    }
    else if (all >= 71){
      servoh.write(eh,255,true);
      servos.write(75,255,true);
    }
    if (all >= 0 && all <= 19){
      s(0,0,0);
    }
    ok = true;
  }
}
void m1(){
   dot.displayText("o_o", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
   dot.displayAnimate();
   servoh.write(eh,125,true);
   delay(500);
   servos.write(es,125,true);
   delay(250);
   if (digitalRead(7) == 1){
      servos.write(ss,125,true);
      delay(300);
      if (digitalRead(7) == 0){
        all++;
        m1();
      }
      else if( digitalRead(7) == 1){
        servos.write(ss,125,true);
        if (digitalRead(7) == 0){
          all++;
          m1();
        }
        delay(200);
        servoh.write(sh,125,true);
        if (digitalRead(7) == 0){
          all++;
          m1();
        }
        s(0,0,0);
      }
      all++;
   }
   dot.displayText("", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
   dot.displayAnimate();
   mode += 1;
}

void m2(){
  dot.displayText("#`_´", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  dot.displayAnimate();
  if (mode == 1){
    servoh.write(eh,255,true);
    servos.write(es,255,true);
    delay(100);
    servos.write(ss,255,true);
    servoh.write(eh,255,true);
    mode++;
    all++;
  }
  else if (mode == 2){
    servoh.write(eh,240,true);
    servos.write(es,240,true);
    delay(2000);
    servos.write(ss,20,true);
    delay(1000);
    servoh.write(sh,255,true);
    mode++;
    all++;
  }
  else if (mode == 3){
    servoh.write(eh,75,true);
    servos.write(es,75,true);
    servos.write(ss,75,true);
    servoh.write(sh,75,true);
    mode++;
    all++;
  }
  else if (mode == 4){
    servoh.write(eh,75,true);
    delay(1000);
    servos.write(es,240,true);
    delay(100);
    servos.write(ss,255,false);
    servoh.write(sh,255,true);
    mode++;
    all++;
  }
  else if (mode == 5){
    servoh.write(eh,150,true);
    servos.write(es,150,true);
    servos.write(ss,150,true);
    delay(2000);
    servos.write(es,255,true);
    delay(2000);
    servos.write(ss,255,true);
    servoh.write(sh,255,true);
    mode++;
    all++;
  }
  else if (mode == 6){
    servoh.write(eh,200,true);
    delay(2000);
    servos.write(es,200,true);
    delay(2000);
    servos.write(ss,200,true);
    delay(2000);
    servoh.write(eh,200,true);
    mode++;
    all++;
  }
  else if (mode == 7){
    servoh.write(eh,240,true);
    servos.write(es,240,true);
    servos.write(65,240,true);
    delay(750);
    servos.write(es,240,true);
    delay(400);
    servos.write(ss,240,true);
    servoh.write(sh,240,true);
    mode++;
    all++;
  }
  else if (mode == 8){
    servoh.write(145,255,true);
    servoh.write(110,255,true);
    servoh.write(157,255,true);
    servoh.write(145,255,true);
    servoh.write(168,255,true);
    servoh.write(134,255,true);
    servoh.write(eh,255,true);
    servos.write(es,255,true);
    delay(100);
    servos.write(ss,255,true);
    servoh.write(sh,255,true);
    mode++;
    all++;
  }
  else if (mode == 9){
    servoh.write(eh,255,true);
    servos.write(73,255,true);
    servos.write(23,255,true);
    servos.write(89,255,true);
    servos.write(12,255,true);
    servos.write(21,255,true);
    servos.write(42,255,true);
    servos.write(es,255,true);
    delay(100);
    servos.write(ss,255,true);
    servoh.write(sh,255,true);
    mode++;
    all++;
  }
  else if (mode == 10){
    servoh.write(145,255,true);
    servos.write(73,255,true);
    servoh.write(110,255,true);
    servos.write(23,255,true);
    servoh.write(157,255,true);
    servos.write(89,255,true);
    servoh.write(145,255,true);
    servos.write(12,255,true);
    servoh.write(168,255,true);
    servos.write(21,255,true);
    servoh.write(134,255,true);
    servos.write(42,255,true);
    servoh.write(eh,255,true);
    servos.write(es,255,true);
    delay(100);
    servos.write(ss,255,true);
    servoh.write(sh,255,true);
    mode = 1;
    all++;
  }
  if (digitalRead(7) == 0){
    all++;
    m2();
  }
  dot.displayText("", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  dot.displayAnimate();
}

void m3(){
  dot.displayText("(ﾟ∀ﾟ)", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  dot.displayAnimate();
  servos.write(es);
  if (digitalRead(7) == 1){
    servos.write(75,255,true);
    if (digitalRead(7) == 0){
      servos.write(es);
    }
  }
  dot.displayText("", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  dot.displayAnimate();
}

void s(int red, int green, int blue){
  analogWrite(3,red);
  analogWrite(5,green);
  analogWrite(6,blue);
}

void sr(){
  analogWrite(3,r);
  analogWrite(5,g);
  analogWrite(6,b);
}

void rgbR(){
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
