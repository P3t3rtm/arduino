// constants won't change
const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to the LIGHT

// IRsendRaw mySender;

// variables will change:
bool ledState;  // the current state of LED low == NC switch == lights off
bool ledState2;
bool ledState3;
bool lastButtonState;     // the previous state of button
bool currentButtonState;  // the current state of button

unsigned long lasttime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // set arduino pin to input pull-up mode
  pinMode(LIGHT_PIN, OUTPUT);         // set arduino pin to output mode
  digitalWrite(LIGHT_PIN, true);      //defaults to lights OFF
  ledState = true;                    // the current state of LED low == NC switch == lights off
  ledState2 = true;
  ledState3 = true;
}

void loop() {
  //add a delay to prevent switch bumping

  // save the last state
  currentButtonState = digitalRead(BUTTON_PIN);  // read new state


  //check if ledState == ledState2 == ledState3, if so, do nothing, if not, set light_pin to the most common state
  if (!(ledState == ledState2 == ledState3)) {
    //set light_pin to the the ledstate with the most same values
    if (ledState == ledState2) {
      digitalWrite(LIGHT_PIN, ledState);
    } else if (ledState == ledState3) {
      digitalWrite(LIGHT_PIN, ledState);
    } else if (ledState2 == ledState3) {
      digitalWrite(LIGHT_PIN, ledState2);
    }
  }

  //button state high = switch not pressed
  if ((millis() - lasttime) > 1000) {

    if (lastButtonState == HIGH && currentButtonState == LOW) {
      lasttime = millis();  // starts timer after switch toggled

      // toggle state of LED
      ledState = !ledState;
      ledState2 = !ledState2;
      ledState3 = !ledState3;
      // control LED arccoding to the toggled state
      if (ledState == ledState2) {
        digitalWrite(LIGHT_PIN, ledState);
      } else if (ledState == ledState3) {
        digitalWrite(LIGHT_PIN, ledState);
      } else if (ledState2 == ledState3) {
        digitalWrite(LIGHT_PIN, ledState2);
      }
    }
  }

  lastButtonState = currentButtonState;
}