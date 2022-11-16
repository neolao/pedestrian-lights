#define RED_LED_PIN_1 12
#define RED_LED_PIN_2 11
#define RED_LED_PIN_3 10
#define GREEN_LED_PIN_1 7
#define GREEN_LED_PIN_2 8
#define GREEN_LED_PIN_3 9

void setup() {
  pinMode(RED_LED_PIN_1, OUTPUT);
  pinMode(RED_LED_PIN_2, OUTPUT);
  pinMode(RED_LED_PIN_3, OUTPUT);
  pinMode(GREEN_LED_PIN_1, OUTPUT);
  pinMode(GREEN_LED_PIN_2, OUTPUT);
  pinMode(GREEN_LED_PIN_3, OUTPUT);
}

void changeRedLeds(int state) {
  digitalWrite(RED_LED_PIN_1, state);
  digitalWrite(RED_LED_PIN_2, state);
  digitalWrite(RED_LED_PIN_3, state);
}

void changeGreenLeds(int state) {
  digitalWrite(GREEN_LED_PIN_1, state);
  digitalWrite(GREEN_LED_PIN_2, state);
  digitalWrite(GREEN_LED_PIN_3, state);
}

void switchToGreen() {
  changeRedLeds(LOW);
  changeGreenLeds(HIGH);
}

void switchToRed() {
  changeRedLeds(HIGH);
  changeGreenLeds(LOW);
}

void loop() {
  switchToRed();
  delay(30000);
  switchToGreen();
  delay(30000);
}
