// constants won't change
const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to the LIGHT

// IRsendRaw mySender;

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
  delay(200);                                    //anti switch bumping
  lastButtonState = currentButtonState;          // save the last state
  currentButtonState = digitalRead(BUTTON_PIN);  // read new state

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    // mySender.send(rawData20C,RAW_DATA_LEN,38);  //Pass the buffer,length, optionally frequency

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LIGHT_PIN, ledState);
  }
}

