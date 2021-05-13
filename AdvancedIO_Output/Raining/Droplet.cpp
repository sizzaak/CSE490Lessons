#include "Droplet.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Droplet::Droplet(int screenWidth=0, int screenHeight=0, Adafruit_SSD1306 *display=NULL) :
    kScreenWidth(screenWidth), kScreenHeight(screenHeight), kDisplay(display){
  Serial.println("newobj0");
  _x = random(kScreenWidth);
  _y = random(-500, -50);
  _z = random(0, 20);
  _len = map(_z, 0, 20, 10, 20);
  _yspeed = map(_z, 0, 20, 1, 20);
  Serial.println("newobj1");
}

void Droplet::update(int windSpeed) {
  _y = _y + _yspeed;
  int grav = map(_z, 0, 20, 0, 0.2);
  _yspeed = _yspeed + grav;

  int xlen = map(windSpeed, 0, 100, 0, _len); // up to diagonal slant
  int xspeed = map(windSpeed, 0, 100, 0, _yspeed); // speed and length proportions equal for smooth movement
  _x += xspeed;

  if (_y > kScreenHeight) {
    _y = (rand() % 100) - 200;
    _x = random(kScreenWidth) - (-_y * windSpeed / 100);
    _yspeed = map(_z, 0, 20, 4, 10);
  }

  kDisplay->drawLine(_x, _y, _x + xlen, _y + _len, SSD1306_WHITE);
}
