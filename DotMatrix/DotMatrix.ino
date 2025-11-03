#include <MD_Parola.h>
#include <MD_MAX72xx.h>

//ドットマトリクス
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW //デバイス種別
#define MAX_DEVICES 2     //8x8のマトリクス表示のユニット数
#define DATA_PIN  11      //DATA
#define CS_PIN    10      //CS
#define CLK_PIN   13      //CLK
MD_Parola dot = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

bool animend = false;
int mode = 1;
 
void setup() {
    dot.displayReset();
    dot.begin();
    animend = false;
    mode = 1;
}

void showtext(){
    if (mode == 1){
      dot.displayText("o_o", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      if(dot.getZoneStatus(1)){
        delay(1000);
        mode += 1;
      }
    }
    else if (mode == 2){
      dot.displayText("-- ;", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      if(dot.getZoneStatus(1)){
        delay(1000);
        mode += 1;
      }
    }
    else if (mode == 3){
      dot.displayText("0x0", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      if(dot.getZoneStatus(1)){
        delay(1000);
        mode = 1;
      }
    }
}
 
void loop() {
  dot.displayAnimate();
  delay(10);
  if(dot.getZoneStatus(0)){
    showtext();
  }
}
