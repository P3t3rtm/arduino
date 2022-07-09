const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to the LIGHT

bool ledState;  // the current state of LED low == NC switch == lights off
bool ledState2;
bool ledState3;
bool lastButtonState;     // the previous state of button
bool currentButtonState;  // the current state of button

unsigned long lasttime = 0;
unsigned long lastbuttontime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // set arduino pin to input pull-up mode
  pinMode(LIGHT_PIN, OUTPUT);         // set arduino pin to output mode
  digitalWrite(LIGHT_PIN, true);      //defaults to lights OFF
  ledState = true;                    // the current state of LED low == NC switch == lights off
  ledState2 = true;
  ledState3 = true;
}

void loop() {
  if ((ledState != ledState2) || (ledState != ledState3) || (ledState2 != ledState3)) {
    Serial.println("Not equal!");
    //set light_pin to the the ledstate with the most same values
    if (ledState == ledState2) {
      digitalWrite(LIGHT_PIN, ledState);
      ledState3 = ledState;
    } else if (ledState == ledState3) {
      digitalWrite(LIGHT_PIN, ledState);
      ledState2 = ledState;
    } else if (ledState2 == ledState3) {
      digitalWrite(LIGHT_PIN, ledState2);
      ledState = ledState2;
    }
  }


  currentButtonState = digitalRead(BUTTON_PIN);
  if (!currentButtonState && (millis() - lastbuttontime) >= 10 && lastButtonState) {
    if ((millis() - lasttime) >= 1000) {
      Serial.println("Switch Toggle Function");
      // toggle state of LED
      ledState = !ledState;
      ledState2 = !ledState2;
      ledState3 = !ledState3;
      // control LED arccoding to the toggled state
      if (ledState == ledState2) {
        ledState3 = ledState;
        digitalWrite(LIGHT_PIN, ledState);
        lastButtonState = false;
        lastbuttontime = millis();
      } else if (ledState == ledState3) {
        ledState2 = ledState;
        digitalWrite(LIGHT_PIN, ledState);
        lastButtonState = false;
        lastbuttontime = millis();
      } else if (ledState2 == ledState3) {
        ledState = ledState2;
        digitalWrite(LIGHT_PIN, ledState2);
        lastButtonState = false;
        lastbuttontime = millis();
      }
      lasttime = millis();
    }
  }
  if (currentButtonState) { //if button is up position
    lastbuttontime = millis();
    lastButtonState = true;
  }
}