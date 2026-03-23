// 3-22-2026
#include <Arduino.h>

const int PIN_LID = 3;   // Servo lid
const int PIN_ARM = 7;   // Servo arm
const int PIN_SW  = 8;   // Toggle switch
const int PIN_R = 5, PIN_G = 2, PIN_B = 9; // RGB

// Matrix
const int M_DIN = 10;
const int M_CS  = A0;
const int M_CLK = A1;

int all = 0;
int mode = 1;
bool ok = true;
int sh = 0, eh = 70;   // Angle lid
int ss = 0, es = 110;  // Angle arm
int targetLid = 0, targetArm = 0;

// LED & Matrix status
unsigned long lastLedUpdate = 0;
int ledStep = 0;

// Face
byte eye_normal[8] = {0x00, 0x00, 0x3C, 0x00, 0x00, 0x3C, 0x00, 0x00};
byte eye_surprise[8] = {0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00};

void drawFace(byte data[]) {
  for (int i = 0; i < 8; i++) {
    sendMax7219Dual(i + 1, data[i], data[i]);
  }
}

void sendMax7219Dual(byte reg, byte data1, byte data2) {
  digitalWrite(M_CS, LOW);
  shiftOut(M_DIN, M_CLK, MSBFIRST, reg);   // Register 2
  shiftOut(M_DIN, M_CLK, MSBFIRST, data2); // Data 2
  shiftOut(M_DIN, M_CLK, MSBFIRST, reg);   // Register 1
  shiftOut(M_DIN, M_CLK, MSBFIRST, data1); // Data 1
  digitalWrite(M_CS, HIGH);
}

void sendMax7219All(byte reg, byte data) {
  sendMax7219Dual(reg, data, data);
}

void initMatrix() {
  pinMode(M_DIN, OUTPUT);
  pinMode(M_CS, OUTPUT);
  pinMode(M_CLK, OUTPUT);
  
  sendMax7219All(0x0F, 0x00); // Test mode off
  sendMax7219All(0x09, 0x00); // No decode
  sendMax7219All(0x0B, 0x07); // Scan
  sendMax7219All(0x0A, 0x03); // Brightness (0x00-0x0F)
  sendMax7219All(0x0C, 0x01);
  
  clearMatrix();
}

void clearMatrix() {
  for(int i=1; i<=8; i++) sendMax7219All(i, 0x00);
}

void s(int red, int green, int blue) {
  digitalWrite(PIN_R, red > 0 ? HIGH : LOW);
  digitalWrite(PIN_G, green > 0 ? HIGH : LOW);
  digitalWrite(PIN_B, blue > 0 ? HIGH : LOW);
}

void updateRGB() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastLedUpdate >= 500) {
    lastLedUpdate = currentMillis;
    ledStep = (ledStep + 1) % 5;
    switch (ledStep) {
      case 0: s(255, 0, 0); break;
      case 1: s(0, 255, 0); break;
      case 2: s(0, 0, 255); break;
      case 3: s(255, 255, 255); break;
      case 4: s(0, 0, 0); break;
    }
  }
}

void waitMs(int ms) {
  unsigned long start = millis();
  while (millis() - start < (unsigned long)ms) {
    updateRGB();
    int pulseLid = map(targetLid, 0, 180, 500, 2500);
    int pulseArm = map(targetArm, 0, 180, 500, 2500);
    digitalWrite(PIN_LID, HIGH); delayMicroseconds(pulseLid); digitalWrite(PIN_LID, LOW);
    digitalWrite(PIN_ARM, HIGH); delayMicroseconds(pulseArm); digitalWrite(PIN_ARM, LOW);
    int remaining = 20000 - pulseLid - pulseArm;
    if (remaining > 0) delayMicroseconds(remaining);
  }
}

void moveLid(int angle) { targetLid = angle; }
void moveArm(int angle) { targetArm = angle; }

void v1() {
  s(0, 255, 0);
  moveLid(eh);
  waitMs(300);
  moveArm(es);
  waitMs(300);
}

void v2() {
  if (mode == 1) {
    moveLid(eh); waitMs(500); moveArm(es); waitMs(500); moveLid(sh); waitMs(500); moveArm(ss);
  } else if (mode == 2) {
    moveLid(eh); waitMs(250); moveArm(es); waitMs(150); moveArm(ss); waitMs(250); moveLid(sh);
  } else if (mode == 3) {
    moveLid(eh); waitMs(1000); moveLid(sh); waitMs(1000); moveLid(eh); waitMs(150); moveArm(es); waitMs(150); moveArm(ss); waitMs(150); moveLid(sh);
  } else if (mode == 4) {
    moveLid(eh); waitMs(350); moveArm(80); waitMs(500); moveArm(65); waitMs(300); moveArm(es); waitMs(200); moveArm(ss); waitMs(300); moveLid(sh);
  } else if (mode == 5) {
    waitMs(5000); moveLid(eh); waitMs(250); moveArm(es); waitMs(250); moveArm(ss); waitMs(250); moveLid(sh);
  } else if (mode == 6) {
    moveLid(eh); waitMs(2000); moveArm(es); waitMs(2000); moveArm(ss); waitMs(2000); moveLid(sh);
  } else if (mode == 7) {
    moveLid(eh); waitMs(300); moveArm(es); waitMs(250); moveArm(65); waitMs(500); moveArm(es); waitMs(1500); moveArm(ss); waitMs(250); moveLid(sh);
  } else if (mode == 8) {
    for(int i=0; i<3; i++) { moveLid(50); waitMs(150); moveLid(10); waitMs(150); }
    moveLid(eh); waitMs(200); moveArm(es); waitMs(250); moveArm(ss); waitMs(200); moveLid(sh);
  } else if (mode == 9) {
    moveLid(eh); waitMs(350); for(int i=0; i<3; i++) { moveArm(100); waitMs(150); moveArm(70); waitMs(150); }
    moveArm(es); waitMs(150); moveArm(ss); waitMs(200); moveLid(sh);
  } else if (mode == 10) {
    moveLid(eh); waitMs(250); moveArm(75); moveLid(80); waitMs(150); moveLid(eh); waitMs(100); moveArm(90); waitMs(150);
    moveLid(60); waitMs(100); moveArm(100); waitMs(150); moveArm(es); waitMs(150); moveArm(ss); waitMs(350); moveLid(sh);
  }
  mode = (mode >= 10) ? 1 : mode + 1;
}

void v3() {
  s(0, 0, 255);
  moveArm(es);
  waitMs(100);
}

void setup() {
  pinMode(PIN_LID, OUTPUT);
  pinMode(PIN_ARM, OUTPUT);
  pinMode(PIN_SW,  INPUT_PULLUP);
  pinMode(PIN_R,   OUTPUT);
  pinMode(PIN_G,   OUTPUT);
  pinMode(PIN_B,   OUTPUT);
  
  initMatrix();
  clearMatrix();

  targetLid = sh;
  targetArm = ss;
  s(255, 255, 255);
  waitMs(500);
  s(0, 0, 0);

  for(int i=1; i<=8; i++) {
    sendMax7219All(i, 0xFF);
  }
}

void loop() {
  updateRGB();

  if (digitalRead(PIN_SW) == HIGH) {
    ok = true;
    drawFace(eye_normal);
    moveLid(sh);
    moveArm(ss);
    
    int pulseLid = map(targetLid, 0, 180, 500, 2500);
    int pulseArm = map(targetArm, 0, 180, 500, 2500);
    
    digitalWrite(PIN_LID, HIGH);
    delayMicroseconds(pulseLid);
    digitalWrite(PIN_LID, LOW);
    digitalWrite(PIN_ARM, HIGH);
    delayMicroseconds(pulseArm);
    digitalWrite(PIN_ARM, LOW);
    delayMicroseconds(15000); 
  } else {
    if (ok) {
      ok = false;
      drawFace(eye_surprise);
      all = (all >= 180) ? 0 : all + 1;
    }
    if (all < 30) v1();
    else if (all < 80) v2();
    else v3();
  }
}