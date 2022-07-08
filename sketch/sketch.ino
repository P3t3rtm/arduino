// constants won't change
const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to the LIGHT

// IRsendRaw mySender;

// variables will change:
int ledState;  // the current state of LED low == NC switch == lights off
int ledState2;
int ledState3;
int lastButtonState;     // the previous state of button
int currentButtonState;  // the current state of button

unsigned long lasttime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // set arduino pin to input pull-up mode
  pinMode(LIGHT_PIN, OUTPUT);         // set arduino pin to output mode
  digitalWrite(LIGHT_PIN, HIGH);      //defaults to lights OFF
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
  if ((millis() - lasttime) > 5000) {

    if (lastButtonState == HIGH && currentButtonState == LOW) {
      lasttime = millis();  // starts timer after switch toggled

      // toggle state of LED
      ledState = !ledState;
      ledState2 = ledState;
      // control LED arccoding to the toggled state
      digitalWrite(LIGHT_PIN, ledState);
    }
  }

  lastButtonState = currentButtonState;
}