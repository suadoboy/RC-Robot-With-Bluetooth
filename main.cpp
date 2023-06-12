// RC ROBOT WITH BLUETOOTH
// LIBRARIES
#include <SoftwareSerial.h>
#include <Servo.h>
//BLUETOOTH PINS
const int bluetoothTx = 10;
const int bluetoothRx = 11;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
// SERVO PINS
const int servo1Pin = 9;
const int servo2Pin = 8;
Servo servo1;
Servo servo2;
// SETUP
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
}
// LOOP
void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    switch (command) {
      case '1':
        servo1.write(servo1.read() + 30);
        servo2.write(servo2.read() - 30);
        break;

      case '2':
        servo1.write(servo1.read() - 30);
        servo2.write(servo2.read() + 30);
        break;

      case '3':
        servo1.write(servo1.read() + 20);
        break;

      case '4':
        servo2.write(servo2.read() - 20);
        break;
    }
  }
  delay(10);
}
// @suadob0y
