#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {


  float pos = map(analogRead(0), 0, 1023, 0, 180);
  
  myservo.write(pos);
  Serial.print(pos);
  Serial.print(" = light: ");
  Serial.println(analogRead(0));
  delay(250);


}
