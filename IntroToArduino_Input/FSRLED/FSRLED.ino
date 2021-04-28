const int FSR_INPUT_PIN = A0;
const int DELAY_MS = 50;
const int LED_OUTPUT_PIN = LED_BUILTIN;

void setup() {
  Serial.begin(9600);
  pinMode(LED_OUTPUT_PIN, OUTPUT);
}

void loop() {
  int fsrVal = analogRead(FSR_INPUT_PIN);
  float fsrVoltage = fsrVal * (5.0 / 1023.0);

  Serial.print("fsrVal: ");
  Serial.print(fsrVal);
  Serial.print(" Input voltage: ");
  Serial.print(fsrVoltage);
  Serial.println("V");
  
  int ledVal = map(fsrVal, 0, 1023, 0, 255);
  analogWrite(LED_OUTPUT_PIN, ledVal);

  delay(DELAY_MS);
}
