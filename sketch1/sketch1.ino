void setup() {  
  // using pin 9 to control motor
  pinMode(9, OUTPUT);
  
  // using pin 12 to read button state 
  pinMode(12, INPUT_PULLUP);
}
// start sketch with motor off
bool motorOn = false;

void loop() {
  // pressing button toggles motor state
  if(digitalRead(12) == 0) {
    motorOn = !motorOn;
    // delay to debounce
    delay(500);
  }

  if (motorOn) {
      analogWrite(9, 255);
  } else {
      analogWrite(9, 0);
  }
}
