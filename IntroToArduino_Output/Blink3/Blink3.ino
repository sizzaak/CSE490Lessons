const int LED_OUTPUT_PIN = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_OUTPUT_PIN, HIGH);
  Serial.println("The LED is on");
  delay(1000);
  
  digitalWrite(LED_OUTPUT_PIN, LOW);
  Serial.println("The LED is off");
  delay(1000);
}
