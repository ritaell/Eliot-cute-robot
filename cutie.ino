#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
RoboEyes<Adafruit_SSD1306> roboEyes(display);

const int touchPin = 2;
bool lastTouch = HIGH;
bool inAnimation = false;
unsigned long animStartTime = 0;

// Default idle eye style
const byte DEF_WIDTH = 32;
const byte DEF_HEIGHT = 24;
const byte DEF_RADIUS = 6;

const unsigned long ANIM_DURATION = 2000;

// Forward declarations (to avoid "not declared" errors)
void triggerRandomEmotion();
void curiousScan();
void returnToIdle();

void setup() {
  pinMode(touchPin, INPUT_PULLUP);
  randomSeed(analogRead(0));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while (1);

  roboEyes.begin(128, 64, 60);
  roboEyes.setWidth(DEF_WIDTH, DEF_WIDTH);
  roboEyes.setHeight(DEF_HEIGHT, DEF_HEIGHT);
  roboEyes.setBorderradius(DEF_RADIUS, DEF_RADIUS);
  roboEyes.open();
  roboEyes.setIdleMode(ON, 3, 2);
  roboEyes.setAutoblinker(ON, 4, 3);
}

void loop() {
  bool isTouched = (digitalRead(touchPin) == LOW);

  if (isTouched && !lastTouch && !inAnimation) {
    triggerRandomEmotion();
  }
  lastTouch = isTouched;

  if (inAnimation && millis() - animStartTime > ANIM_DURATION) {
    returnToIdle();
  }

  roboEyes.update();
}

void triggerRandomEmotion() {
  inAnimation = true;
  animStartTime = millis();
  roboEyes.setIdleMode(OFF);
  roboEyes.setAutoblinker(OFF);

  int emotion = random(0, 4);

  switch (emotion) {
    case 0: // Happy
      roboEyes.setMood(HAPPY);
      roboEyes.anim_laugh();
      break;
    case 1: // Angry
      roboEyes.setMood(ANGRY);
      roboEyes.anim_confused();
      break;
    case 2: // Confused
      roboEyes.setMood(DEFAULT);
      roboEyes.anim_confused();
      break;
    case 3: // Curious Scan
      curiousScan();
      break;
  }
}

void curiousScan() {
  // Left eye big
  roboEyes.setWidth(40, 24);
  roboEyes.setHeight(40, 24);
  roboEyes.setBorderradius(20, 6);
  roboEyes.drawEyes();
  display.display();
  delay(300);

  // Right eye big
  roboEyes.setWidth(24, 40);
  roboEyes.setHeight(24, 40);
  roboEyes.setBorderradius(6, 20);
  roboEyes.drawEyes();
  display.display();
  delay(300);

  // Back to normal
  roboEyes.setWidth(DEF_WIDTH, DEF_WIDTH);
  roboEyes.setHeight(DEF_HEIGHT, DEF_HEIGHT);
  roboEyes.setBorderradius(DEF_RADIUS, DEF_RADIUS);
}

void returnToIdle() {
  roboEyes.setWidth(DEF_WIDTH, DEF_WIDTH);
  roboEyes.setHeight(DEF_HEIGHT, DEF_HEIGHT);
  roboEyes.setBorderradius(DEF_RADIUS, DEF_RADIUS);
  roboEyes.setMood(DEFAULT);
  roboEyes.open();
  roboEyes.blink();
  roboEyes.setIdleMode(ON, 3, 2);
  roboEyes.setAutoblinker(ON, 4, 3);
  inAnimation = false;
}