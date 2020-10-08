//include and initialize servo
#include <Servo.h>
Servo myservo;

void setup() {
  //using pin 9 for servo
  myservo.attach(9);
}

void loop() {
  //map the photocell's input from 0-1023 range to servo's 0-180 range
  float pos = map(analogRead(0), 0, 1023, 0, 180);

  //update servo position
  myservo.write(pos);

}
