unsigned long _lastToggledTimestampMs = 0xFFFFFFFA; // change this to experiment with overflow

void setup() {
  Serial.begin(9600);
  delay(2000);
}

void loop() {

  unsigned long currentTimestampMs = 1;
  unsigned long diff = currentTimestampMs - _lastToggledTimestampMs;

  Serial.println("The subtraction between: currentTimestampMs - lastToggledTimestampMs is: ");
  Serial.print(currentTimestampMs);
  Serial.print(" - ");
  Serial.print(_lastToggledTimestampMs);
  Serial.print(" = ");
  Serial.println(diff);
  delay(1000);

  _lastToggledTimestampMs++;
}
