// The following OLED setup taken from the ssd1306_128x64_i2c library example
// --------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Droplet.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// --------------------------------------------------------------------------

const int DROP_COUNT = 30;
const int MAX_ANALOG_INPUT = 1023;
const int ANALOG_INPUT_PIN = A0;

Droplet* _drops[DROP_COUNT];

void setup() {
  // The following OLED setup taken from the ssd1306_128x64_i2c library example
  // --------------------------------------------------------------------------
  Serial.begin(9600);
  while (!Serial);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // --------------------------------------------------------------------------
  for (int i=0; i<DROP_COUNT; i++) {
    Serial.println(i);
    _drops[i] = new Droplet(SCREEN_WIDTH, SCREEN_HEIGHT, &display);
  }
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  int analogInput = analogRead(ANALOG_INPUT_PIN);
  int windSpeed = map(analogInput, 0, MAX_ANALOG_INPUT, 0, 100);
  for (int i=0; i<DROP_COUNT; i++) {
    _drops[i]->update(windSpeed);
  }
  display.display();
}
