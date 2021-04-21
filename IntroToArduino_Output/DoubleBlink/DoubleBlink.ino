const int LED1_OUTPUT_PIN = 3; // The LED ran by voltage source
const int LED2_OUTPUT_PIN = 4; // The LED ran by voltage sink
const int DELAY_MS = 1000; // time delay between blinks

void setup() {
  // set pins to output
  pinMode(LED1_OUTPUT_PIN, OUTPUT);
  pinMode(LED2_OUTPUT_PIN, OUTPUT);
}

void loop() {
  // Turn LED1 on and LED2 off then inverse, due to the pin
  // being a sink for LED2
  digitalWrite(LED1_OUTPUT_PIN, HIGH);
  digitalWrite(LED2_OUTPUT_PIN, HIGH);
  delay(DELAY_MS);

  digitalWrite(LED1_OUTPUT_PIN, LOW);
  digitalWrite(LED2_OUTPUT_PIN, LOW);
  delay(DELAY_MS);
}
