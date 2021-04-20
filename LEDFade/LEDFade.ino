const int LED_OUTPUT_PIN = 3;
const int MAX_ANALOG_OUT = 255;
const int DELAY_MS = 5;

int _fadeAmount = 5;
int _curBrightness = 0;

void setup() {
  // set Pin 3 to output
  pinMode(LED_OUTPUT_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_OUTPUT_PIN, _curBrightness);
  _curBrightness = _curBrightness + _fadeAmount;
  if (_curBrightness <= 0 || _curBrightness >= MAX_ANALOG_OUT) {
    _fadeAmount = -_fadeAmount;
  }
  delay(DELAY_MS);
}
