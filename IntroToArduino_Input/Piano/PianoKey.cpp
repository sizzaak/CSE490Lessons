#include <PushButton.h>

#include "PianoKey.h"

PianoKey::PianoKey(int ledPin, int butPin) : 
    _ledPin(ledPin), _butPin(butPin), _button(PushButton(butPin)) {
  _brightness = 0;
  pinMode(_ledPin, OUTPUT);
  pinMode(_butPin, INPUT_PULLUP);
  //_button = PushButton(butPin);
}

void PianoKey::turnOn() {
  _brightness = 255;
  analogWrite(_ledPin, _brightness);
}

void PianoKey::fadeOut() {
  if (_brightness <= FADE_RATE) {
    _brightness = 0;
  } else {
    _brightness -= FADE_RATE;
  }
  analogWrite(_ledPin, _brightness);
}

bool PianoKey::isPressed() {
  // XOR to flip read output if buttons are active on LOW
  _button.update();
  Serial.print(_button.isActive());
  return _button.isActive() ^ BUTTONS_ACTIVE_LOW;
}

bool PianoKey::update() {
  bool pressed = isPressed();
  if (pressed) {
    turnOn();
  } else {
    fadeOut();
  }
  return pressed;
}
