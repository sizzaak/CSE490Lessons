#include <PushButton.h>

const int VIBROMOTOR_OUTPUT_PIN = 3;
const int BUTTON_INPUT_PIN = 2;

const int MAX_ANALOG_OUT = 255;
const int MAX_ANALOG_INPUT = 1023;

long _timeLastPress = 0;
PushButton _button(BUTTON_INPUT_PIN);

void setup() {
  pinMode(VIBROMOTOR_OUTPUT_PIN, OUTPUT);
  pinMode(BUTTON_INPUT_PIN, INPUT);
}

void loop() {
  if (_button.isActive()) {
    _timeLastPress = millis();
  }
  if ((millis() - _timeLastPress > 2000) && ((millis() - _timeLastPress) % 500 < 250)) {
    digitalWrite(VIBROMOTOR_OUTPUT_PIN, HIGH);
  } else {
    digitalWrite(VIBROMOTOR_OUTPUT_PIN, LOW);
  }
}
