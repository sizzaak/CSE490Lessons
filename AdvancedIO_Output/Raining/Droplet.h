#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Droplet {
  public:
    // Constructor
    Droplet(int screenWidth, int screenHeight, Adafruit_SSD1306 *display);

    // Default constructor
    Droplet();

    // Run every step to animate
    void update(int windSpeed);

  private:
    const int kScreenWidth;
    const int kScreenHeight;
    const Adafruit_SSD1306 *kDisplay;

    int _x;
    int _y;
    int _yspeed;
    int _z;
    int _len;
};
