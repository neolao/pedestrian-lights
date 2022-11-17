#define RED_LED_PIN_1 12
#define RED_LED_PIN_2 11
#define RED_LED_PIN_3 10
#define GREEN_LED_PIN_1 7
#define GREEN_LED_PIN_2 8
#define GREEN_LED_PIN_3 9
#define RED_BUTTON_PIN 13
#define GREEN_BUTTON_PIN 6

enum Mode { MODE_GREEN, MODE_RED };
enum Mode mode;
unsigned long timer;
int changeDelay = 15000;

void setup() {
  pinMode(RED_LED_PIN_1, OUTPUT);
  pinMode(RED_LED_PIN_2, OUTPUT);
  pinMode(RED_LED_PIN_3, OUTPUT);
  pinMode(GREEN_LED_PIN_1, OUTPUT);
  pinMode(GREEN_LED_PIN_2, OUTPUT);
  pinMode(GREEN_LED_PIN_3, OUTPUT);
  pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
  pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);

  timer = millis();
  mode = MODE_RED;
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

void changeMode(enum Mode newMode) {
  mode = newMode;
  
  if (mode == MODE_RED) {
    switchToRed();
  } else {
    switchToGreen();
  }
  timer = millis();
}

void loop() {
  bool redButtonPressed = (digitalRead(RED_BUTTON_PIN) == LOW);
  bool greenButtonPressed = (digitalRead(GREEN_BUTTON_PIN) == LOW);

  if (redButtonPressed && greenButtonPressed) {
    
  } else if (redButtonPressed) {
    changeMode(MODE_RED);
  } else if (greenButtonPressed) {
    changeMode(MODE_GREEN);
  }
  
  if (millis() - timer < changeDelay) {
    if (mode == MODE_RED) {
      changeMode(MODE_GREEN);
    } else {
      changeMode(MODE_RED);
    }
    
    timer = millis();
  }
}
