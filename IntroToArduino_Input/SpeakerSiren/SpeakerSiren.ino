const int LED_OUTPUT_PIN = LED_BUILTIN;
const int SPEAKER_OUTPUT_PIN = 9;

void setup() {
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  pinMode(SPEAKER_OUTPUT_PIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_OUTPUT_PIN, HIGH);
  tone(SPEAKER_OUTPUT_PIN, 50);
  delay(500);
  digitalWrite(LED_OUTPUT_PIN, LOW);
  tone(SPEAKER_OUTPUT_PIN, 200);
  delay(500);
}
