#include <Arduino.h>

class Blinker {
  private:
    const int _pin;                 // output pin
    const unsigned long _interval;  // blink interval in ms

    int _state;                     // current state (HIGH or LOW)
    unsigned long _lastToggledTimestamp;  // last state toggle in ms

  public:
    // Constructor
    Blinker(int pin, unsigned long blinkInterval);

    // Calculates whether to toggle output state based on the set interval.
    // Call this function once per loop().
    void update();
};
