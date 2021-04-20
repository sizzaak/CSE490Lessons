void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTimestampMs = millis();

  Serial.print("Time since Arduino started: ");
  Serial.print(currentTimestampMs);
  Serial.println(" ms");
  delay(500);
}
