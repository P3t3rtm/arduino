// constants won't change
const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to the LIGHT

// IRsendRaw mySender;

// variables will change:
int ledState = LOW;      // the current state of LED low == NC switch == lights off
int lastButtonState;     // the previous state of button
int currentButtonState;  // the current state of button

long lasttime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // set arduino pin to input pull-up mode
  pinMode(LIGHT_PIN, OUTPUT);         // set arduino pin to output mode
  //digitalWrite(LIGHT_PIN, ledState); //defaults to lights ON
}

void loop() {
  //add a delay to prevent switch bumping

  // save the last state
  currentButtonState = digitalRead(BUTTON_PIN);  // read new state


  //button state high = switch not pressed
  if (lastButtonState == HIGH && currentButtonState == LOW && ((millis() - lasttime) > 2000)) {
    lasttime = millis();

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LIGHT_PIN, ledState);
  }
  lastButtonState = currentButtonState;
}