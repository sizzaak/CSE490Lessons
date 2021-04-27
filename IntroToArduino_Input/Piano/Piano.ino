#include "PianoKey.h"

// Frequencies (in Hz) of our piano keys
// From: https://en.wikipedia.org/wiki/Piano_key_frequencies
#define KEY_C 262  // 261.6256 Hz (middle C)
#define KEY_D 294  // 293.6648 Hz
#define KEY_E 330  // 329.6276 Hz
#define KEY_F 350  // 349.2282 Hz
#define KEY_G 392  // 391.9954 Hz

// I lay out my buttons like piano keys. So, lower frequencies on left
// and increasingly higher frequencies to the right
// Change this depending on how you've laid out your keys
const int INPUT_BUTTON_C_PIN = 2;
const int INPUT_BUTTON_D_PIN = 5;
const int INPUT_BUTTON_E_PIN = 4;
const int INPUT_BUTTON_F_PIN = 7;
const int INPUT_BUTTON_G_PIN = 8;

const int OUTPUT_LED_C_PIN = 3;
const int OUTPUT_LED_D_PIN = 6;
const int OUTPUT_LED_E_PIN = 9;
const int OUTPUT_LED_F_PIN = 10;
const int OUTPUT_LED_G_PIN = 11;

PianoKey _CKey(OUTPUT_LED_C_PIN, INPUT_BUTTON_C_PIN);
PianoKey _DKey(OUTPUT_LED_D_PIN, INPUT_BUTTON_D_PIN);
PianoKey _EKey(OUTPUT_LED_E_PIN, INPUT_BUTTON_E_PIN);
PianoKey _FKey(OUTPUT_LED_F_PIN, INPUT_BUTTON_F_PIN);
PianoKey _GKey(OUTPUT_LED_G_PIN, INPUT_BUTTON_G_PIN);

const int OUTPUT_PIEZO_PIN = 13;

void setup() {
  pinMode(OUTPUT_PIEZO_PIN, OUTPUT);
}

void loop() {

  // tone() generates a square wave of the specified frequency (and 50% duty cycle) on a pin. 
  // A duration can be specified, otherwise the wave continues until a call to noTone().
  // See: https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
  // 
  // Check each button to see if they're pressed. If so, play the corresponding note
  // We can only play one tone at a time, hence the massive if/else block
  bool CPressed = _CKey.update();
  bool DPressed = _DKey.update();
  bool EPressed = _EKey.update();
  bool FPressed = _FKey.update();
  bool GPressed = _GKey.update();
  if(CPressed){
    tone(OUTPUT_PIEZO_PIN, KEY_C);
  }else if(DPressed){
    tone(OUTPUT_PIEZO_PIN, KEY_D);
  }else if(EPressed){
    tone(OUTPUT_PIEZO_PIN, KEY_E);
  }else if(FPressed){
    tone(OUTPUT_PIEZO_PIN, KEY_F);
  }else if(GPressed){
    tone(OUTPUT_PIEZO_PIN, KEY_G);
  }else{
    noTone(OUTPUT_PIEZO_PIN); // turn off the waveform
  }
  delay(10);
}
