// Manages a piano key light and the button associated with it.  Actual playing
// of the sounds is left to the client.

#include <Arduino.h>

const int FADE_RATE = 5;
// By default, we assume buttons are in pull-up configurations
// Switch the following to false and change INPUT_PULLUP belows
// to INPUT
const bool BUTTONS_ACTIVE_LOW = true;

class PianoKey {
  public:
    // Constructor
    PianoKey(int ledPin, int butPin);

    // Activate the LED
    void turnOn();
    
    // Decrement brightness if the LED is lit and the button is not pressed
    void fadeOut();

    // Return true if the button is being pressed down and false otherwise
    bool isPressed();

    // Returns the result of isPressed and updates LED accordingly
    bool update();
    
  private:
    const int _ledPin;
    const int _butPin;

    int _brightness;
};
