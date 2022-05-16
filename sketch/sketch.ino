// constants won't change
const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to LED's pin

// variables will change:
int ledState = HIGH;     // the current state of LED
int lastButtonState;     // the previous state of button
int currentButtonState;  // the current state of button

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // set arduino pin to input pull-up mode
  pinMode(LIGHT_PIN, OUTPUT);         // set arduino pin to output mode
  digitalWrite(LIGHT_PIN, ledState); //defaults to lights ON
}

void loop() {
  delay(100);                                    //anti switch bumping
  lastButtonState = currentButtonState;          // save the last state
  currentButtonState = digitalRead(BUTTON_PIN);  // read new state

  if (lastButtonState == HIGH && currentButtonState == LOW) {

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LIGHT_PIN, ledState);
  }
}
