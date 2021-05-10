// Draws a very gittery shape that randomly moves around on the screen and
// randomly changes between a circle, reactangle, and triangle

// The following OLED setup taken from the ssd1306_128x64_i2c library example
// --------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

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

const int RADIUS = 3;
int _xpos = SCREEN_WIDTH / 2;
int _ypos = SCREEN_HEIGHT / 2;
int _shape = 0;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();

  // Set up text to display black on white
  display.setTextSize(1);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();

  // Randomize position change
  _xpos += (rand() % 9) - 4;
  if (_xpos < 0) {
    _xpos += SCREEN_WIDTH;
  } else if (_xpos > SCREEN_WIDTH) {
    _xpos -= SCREEN_WIDTH;
  }
  _ypos += (rand() % 9) - 4;
  if (_ypos < 0) {
    _ypos += SCREEN_HEIGHT;
  } else if (_ypos > SCREEN_HEIGHT) {
    _ypos -= SCREEN_HEIGHT;
  }

  // Randomize possible shape change and write shape name to upper left
  if ((rand() % 10) == 0) { // 1 in 10 chance
    _shape = rand() % 3;
  }
  display.setCursor(0,0);
  if (_shape == 0) {
    display.drawCircle(_xpos, _ypos, RADIUS, SSD1306_WHITE);
    display.println("Shape: Circle");
  } else if (_shape == 1) {
    display.drawRect(_xpos - RADIUS, _ypos - RADIUS, RADIUS * 2, RADIUS * 2, SSD1306_WHITE);
    display.println("Shape: Rectangle");
  } else {
    display.drawTriangle(_xpos, _ypos-RADIUS, _xpos-RADIUS, _ypos+RADIUS, _xpos+RADIUS, _ypos+RADIUS, SSD1306_WHITE);
    display.println("Shape: Triangle");
  }
  
  display.display();
}
