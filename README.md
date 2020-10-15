# Weeks 5 + 6 | Motors, Servos, and Transistors
**[process.patrickjam.es/](https://process.patrickjam.es/2020/10/08/weeks-5-6-motors-servos-and-transistors/)**
## [Sketch 1](/sketch1): DC Motor + Push Button
![sketch1 breadboard](/documentationAssets/sketch1_bb.png)
![sketch1 gif](/documentationAssets/sketch1.gif)

The first sketch of this assignment explores a DC motor controlled by a push button. The circuit uses a transistor with its base pin connected to pin 9. The DC motor allows the current to flow from the Ardunio’s Vin pin to the transistor’s collector pin. The transistor uses pin 9’s output to control the flow to ground (emitter pin). With this circuit in place, the board can control the motor using analogWrite(9, ###). For example, the following will turn the motor on for one second, then off for another second.

```c++
analogWrite(9, 255);
delay(1000);
analogWrite(9, 0);
delay(1000);
```

To control the motor with a button, I connected a button from pin 12 to ground and used the INPUT_PULLUP mode track button presses. Pressing the button will change digitalRead(12) from 1 to 0. The loop function can now use an if statement to catch a button press and switch the motor’s state. I’ve added a 500 ms delay to debounce the button press and more accurately switch the motor.

```c++
if (digitalRead(12) == 0) {
    motorOn = !motorOn;
    delay(500);
}
```

This previous two code sections can be combined to create the final program by adding and if/else statement to motor control.

```c++
void setup() {
    pinMode(9, OUTPUT);
    pinMode(12, INPUT_PULLUP);
}

bool motorOn = false;

void loop () {
    if (digitalRead(12) == 0) {
        motorOn = !motorOn;
        delay(500);
    }

    if (motorOn) {
        analogWrite(9, 255);
    } else {
        analogWrite(9, 0);
    }

}
```

## [Sketch 2](/sketch2): Servo + Photocell
![sketch2 breadboard](/documentationAssets/sketch2_bb.png)
![sketch2 gif](/documentationAssets/sketch2.gif)

The second sketch of this assignment explores a servo controlled by a photocell. The photocell allows current to flow from the 5V pin to ground through a 10K resistor. The side going to ground is also connected to pin A0, so the Arduino program can use analogRead(0) to receive the light intensity. The servo also receives current from 5V and flows to ground, with pin 9 controlling its pulse pin.

```c++
myservo.attach(9);
```

```c++
myservo.write(analogRead(0));
```

Using the servo’s write function, the program can change the position of its arm; however, using the data directly from analogRead(0) causes the servo to jump around as pin A0 is supplying a value between 0 and 1023, but the servo only accepts a value between 0 and 180. To fix this, I added map() as follows.

```c++
float pos = map(analogRead(0), 0, 1023, 0, 180);
myservo.write(pos);
```
