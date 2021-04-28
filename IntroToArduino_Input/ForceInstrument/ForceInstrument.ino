const int KEY_C = 262;  // 261.6256 Hz (middle C)
const int KEY_D = 294;  // 293.6648 Hz
const int KEY_E = 330;  // 329.6276 Hz
const int KEY_F = 350;  // 349.2282 Hz
const int KEY_G = 392;  // 391.9954 Hz
const int KEY_A = 440;  // 440.00   Hz
const int KEY_B = 494;  // 493.88   Hz

const int FSR_INPUT_PIN = A0;
const int DELAY_MS = 5;
const int SPEAKER_OUTPUT_PIN = 3;
const int KEYS[] = {KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_A, KEY_B};

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER_OUTPUT_PIN, OUTPUT);
}

void loop() {
  int fsrVal = analogRead(FSR_INPUT_PIN);
  float fsrVoltage = fsrVal * (5.0 / 1023.0);

  int speakerVal;
  if (fsrVal < 3) {
    speakerVal = 0;
    noTone(SPEAKER_OUTPUT_PIN);
  } else {
    speakerVal = KEYS[map(fsrVal, 0, 1023, 0, 7)];
    tone(SPEAKER_OUTPUT_PIN, speakerVal);
  }

  Serial.print("fsrVal: ");
  Serial.print(fsrVal);
  Serial.print(" Speaker level: ");
  Serial.print(speakerVal);
  Serial.print(" Input voltage: ");
  Serial.print(fsrVoltage);
  Serial.println("V");


  delay(DELAY_MS);
}
