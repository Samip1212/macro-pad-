#include "USB.h"
#include "USBHIDKeyboard.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SDA_PIN 45
#define SCL_PIN 46
const int NUM_KEYS = 6;
const int keyPins[NUM_KEYS] = {18, 35, 21, 38, 37, 36};
#define SCREEN_W 128
#define SCREEN_H 64
Adafruit_SSD1306 display(SCREEN_W, SCREEN_H, &Wire, -1);
USBHIDKeyboard Keyboard;
bool lastState[NUM_KEYS];
bool lastConnected = false;
bool firstDraw = true;
void showStatus(bool connected) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 24);
  display.print(connected ? "Connected" : "Disconnected");
  display.display();
}
void cmdKey(char key) {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(key);
  delay(50);
  Keyboard.releaseAll();
}
void openApp(const char* name) {
  cmdKey(' ');                   
  delay(400);
  Keyboard.print(name);
  delay(300);
  Keyboard.write(KEY_RETURN);
}
//edit your key here 
void runMacro(int i) {
  switch (i) {
    case 0: cmdKey('c'); break;   
    case 1: cmdKey('v'); break;   
    case 2: cmdKey('x'); break;   
    case 3:                       
      openApp("Safari");
      delay(1200);
      cmdKey('l');                
      delay(200);
      Keyboard.print("youtube.com");
      delay(100);
      Keyboard.write(KEY_RETURN);
      break;
    case 4: openApp("Safari"); break;  
    case 5: cmdKey('w'); break;        
  }
}
void setup() {
  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);  
    lastState[i] = HIGH;
  }
  Wire.begin(SDA_PIN, SCL_PIN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  Keyboard.begin();
  USB.begin();
}
void loop() {
  bool connected = tud_mounted();
  if (firstDraw || connected != lastConnected) {
    showStatus(connected);
    lastConnected = connected;
    firstDraw = false;
  }
  for (int i = 0; i < NUM_KEYS; i++) {
    bool state = digitalRead(keyPins[i]);
    if (lastState[i] == HIGH && state == LOW && connected) {
      runMacro(i);
    }
    lastState[i] = state;
  }
  delay(20);
}
