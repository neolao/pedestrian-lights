#define RED_LED_PIN_1 12
#define RED_LED_PIN_2 11
#define RED_LED_PIN_3 10
#define GREEN_LED_PIN_1 7
#define GREEN_LED_PIN_2 8
#define GREEN_LED_PIN_3 9
#define RED_BUTTON_PIN 13
#define GREEN_BUTTON_PIN 6

bool autoMode = true;

void setup() {
  pinMode(RED_LED_PIN_1, OUTPUT);
  pinMode(RED_LED_PIN_2, OUTPUT);
  pinMode(RED_LED_PIN_3, OUTPUT);
  pinMode(GREEN_LED_PIN_1, OUTPUT);
  pinMode(GREEN_LED_PIN_2, OUTPUT);
  pinMode(GREEN_LED_PIN_3, OUTPUT);
  pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
  pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);
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

void checkButtons() {
  bool redButtonPressed = (digitalRead(RED_BUTTON_PIN) == LOW);
  bool greenButtonPressed = (digitalRead(GREEN_BUTTON_PIN) == LOW);

  if (redButtonPressed && greenButtonPressed) {
    autoMode = true;
  } else if (redButtonPressed) {
    autoMode = false;
    switchToRed();
  } else if (greenButtonPressed) {
    autoMode = false;
    switchToGreen();
  }
}

void wait() {
  unsigned long timer = millis();
  while(millis() - timer < 30000) {
    delay(200);
    checkButtons();
  }
}

void loop() {
  if (autoMode) {
    switchToRed();
  }
  wait();
  if (autoMode) {
    switchToGreen();
  }
  wait();
}
