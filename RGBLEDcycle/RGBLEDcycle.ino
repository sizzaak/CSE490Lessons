const bool IS_COMMON_CATHODE = true; // use to signify which sort of RGB LED is being used

const int DELAY_MS = 1000; // color change delay
const int RGB_RED_LED_PIN = 3; // indicated by brown wire
const int RGB_GREEN_LED_PIN = 5; // indicated by green wire
const int RGB_BLUE_LED_PIN = 6; // indicated by blue wire

void setup() {
  // Set all RGB LED pins to output
  pinMode(RGB_RED_LED_PIN, OUTPUT);
  pinMode(RGB_BLUE_LED_PIN, OUTPUT);
  pinMode(RGB_GREEN_LED_PIN, OUTPUT);
}

void loop() {
  // red
  setRgbLedColor(HIGH, LOW, LOW);
  delay(DELAY_MS);
  
  // green
  setRgbLedColor(LOW, HIGH, LOW);
  delay(DELAY_MS);
  
  // blue
  setRgbLedColor(LOW, LOW, HIGH);
  delay(DELAY_MS);
  
  // purple
  setRgbLedColor(HIGH, LOW, HIGH);
  delay(DELAY_MS);
  
  // turqoise
  setRgbLedColor(LOW, HIGH, HIGH);
  delay(DELAY_MS);

  // yellow
  setRgbLedColor(HIGH, HIGH, LOW);
  delay(DELAY_MS);
  
  // white
  setRgbLedColor(HIGH, HIGH, HIGH);
  delay(DELAY_MS);
}

// Function expects either HIGH or LOW for each parameter
void setRgbLedColor(int red, int green, int blue){
  if(!IS_COMMON_CATHODE){
    red = !red;
    green = !green;
    blue = !blue;
  }
  
  digitalWrite(RGB_RED_LED_PIN, red);
  digitalWrite(RGB_GREEN_LED_PIN, green);
  digitalWrite(RGB_BLUE_LED_PIN, blue);
}
