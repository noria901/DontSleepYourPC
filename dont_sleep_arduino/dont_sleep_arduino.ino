#define __AVR_ATtiny85__
#include <DigiMouse.h>

bool dont_sleep = false;
const int buttonPin = 0;     // the number of the pushbutton pin
const int ledPin =  1;      // the number of the LED pin

void setup() {
  DigiMouse.begin(); //start or reenumerate USB - BREAKING CHANGE from old versions that didn't require this
  pinMode(ledPin, OUTPUT); //LED on Model A  or Pro
  pinMode(buttonPin, INPUT_PULLUP);
  dont_sleep = false;

  digitalWrite(ledPin, HIGH);
  DigiMouse.moveY(10); //down 10.
  DigiMouse.delay(500);
  DigiMouse.moveY(-10); //down 10
  DigiMouse.delay(50);
  digitalWrite(ledPin, LOW);
}

void loop() {
  update_state();
  if (dont_sleep) {
    DigiMouse.moveY(10); //down 10
    DigiMouse.delay(500);
    DigiMouse.moveX(10); //right 10
    DigiMouse.delay(500);
  }
  update_state();
  if (dont_sleep) {
    DigiMouse.moveY(-10); //down 10
    DigiMouse.delay(500);
    DigiMouse.moveX(-10); //right 10
    DigiMouse.delay(500);
  }
}

void update_state() {
  if (digitalRead(buttonPin) == LOW) {
    dont_sleep = !dont_sleep;
    digitalWrite(ledPin, dont_sleep);
    while (digitalRead(buttonPin) == LOW) {
      DigiMouse.moveY(10); //down 10.
      DigiMouse.delay(50);
      DigiMouse.moveY(-10); //down 10
      DigiMouse.delay(50);
      DigiMouse.moveY(10); //down 10.
      DigiMouse.delay(50);
      DigiMouse.moveY(-10); //down 10
      DigiMouse.delay(500);
    }
  }
}

