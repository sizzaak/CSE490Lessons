const int PULLDOWN_RES_INPUT_PIN = 12;
const int PULLDOWN_RES_OUTPUT_PIN = 11;
const int PULLUP_RES_INPUT_PIN = 7;
const int PULLUP_RES_OUTPUT_PIN = 6;
const int INT_PULLUP_RES_INPUT_PIN = 3;
const int INT_PULLUP_RES_OUTPUT_PIN = 2;

void setup() {
  pinMode(PULLDOWN_RES_INPUT_PIN, INPUT);
  pinMode(PULLUP_RES_INPUT_PIN, INPUT);
  pinMode(INT_PULLUP_RES_INPUT_PIN, INPUT_PULLUP);
  pinMode(PULLDOWN_RES_OUTPUT_PIN, OUTPUT);
  pinMode(PULLUP_RES_OUTPUT_PIN, OUTPUT);
  pinMode(INT_PULLUP_RES_OUTPUT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // pulldown resistor
  int pulldownButtonState = digitalRead(PULLDOWN_RES_INPUT_PIN);
  digitalWrite(PULLDOWN_RES_OUTPUT_PIN, pulldownButtonState);
  Serial.print("Pulldown: ");
  Serial.print(pulldownButtonState);

  // pullup resistor
  int pullupButtonState = digitalRead(PULLUP_RES_INPUT_PIN);
  digitalWrite(PULLUP_RES_OUTPUT_PIN, 1 - pullupButtonState); // inverted since pullup is HIGH when unpressed
  Serial.print(" Pullup: ");
  Serial.print(pullupButtonState);

  // internal pullup resistor
  int intPullupButtonState = digitalRead(INT_PULLUP_RES_INPUT_PIN);
  digitalWrite(INT_PULLUP_RES_OUTPUT_PIN, 1 - intPullupButtonState); // inverted since pullup is HIGH when unpressed
  Serial.print(" Internal pullup: ");
  Serial.println(intPullupButtonState);
  
  
  delay(30);
}
