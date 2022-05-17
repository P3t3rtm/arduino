// #include <IRLibSendBase.h>    //We need the base code
// #include <IRLib_HashRaw.h>    //Only use raw sender

// constants won't change
const int BUTTON_PIN = 10;  // Arduino pin connected to button's pin
const int LIGHT_PIN = 11;   // Arduino pin connected to LED's pin

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

// #define RAW_DATA_LEN 100
// uint16_t rawData20C[RAW_DATA_LEN]={
// 	3334, 1886, 382, 1342, 382, 1314, 406, 426, 
// 	410, 426, 410, 422, 414, 1342, 382, 426, 
// 	410, 426, 410, 1314, 410, 1342, 382, 422, 
// 	414, 1342, 382, 426, 410, 422, 414, 1310, 
// 	414, 1342, 382, 422, 414, 1318, 406, 1314, 
// 	410, 422, 414, 422, 414, 1342, 382, 422, 
// 	410, 426, 410, 1346, 378, 426, 410, 426, 
// 	410, 426, 410, 426, 410, 426, 410, 426, 
// 	410, 426, 410, 426, 410, 426, 410, 422, 
// 	414, 422, 414, 422, 410, 426, 414, 422, 
// 	410, 426, 410, 426, 414, 422, 410, 1318, 
// 	410, 422, 414, 422, 410, 1346, 378, 426, 
// 	410, 426, 410, 1000};

// uint16_t rawData27C[RAW_DATA_LEN]={
// 	3338, 1886, 382, 1342, 382, 1338, 382, 426, 
// 	410, 426, 410, 426, 410, 1314, 410, 426, 
// 	410, 426, 410, 1318, 406, 1314, 410, 422, 
// 	414, 1342, 382, 422, 414, 422, 410, 1318, 
// 	406, 1314, 410, 426, 410, 1310, 414, 1314, 
// 	410, 422, 414, 422, 414, 1342, 378, 426, 
// 	410, 426, 410, 1318, 406, 426, 410, 426, 
// 	410, 422, 410, 426, 410, 426, 410, 426, 
// 	410, 426, 410, 426, 410, 426, 410, 422, 
// 	414, 422, 414, 422, 414, 422, 414, 422, 
// 	414, 422, 414, 422, 410, 426, 410, 1318, 
// 	406, 426, 410, 426, 410, 1314, 410, 422, 
// 	414, 422, 410, 1000};


void loop() {
  delay(100);                                    //anti switch bumping
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

