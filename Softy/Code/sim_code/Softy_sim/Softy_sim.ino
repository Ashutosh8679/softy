#include <Servo.h>

Servo leftServo;
Servo rightServo;

const int leftServoPin  = 5;
const int rightServoPin = 6;

const int button1Pin = 2; // go to 0°
const int button2Pin = 3; // go to 90°

int currentPos = 0;

void setup() {
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  // initial position
  leftServo.write(0);
  rightServo.write(180); // mirrored
}

void loop() {

  // Button 1 → go to 0°
  if (digitalRead(button1Pin) == LOW) {
    moveServos(0);
    delay(200); // debounce
  }

  // Button 2 → go to 90°
  if (digitalRead(button2Pin) == LOW) {
    moveServos(90);
    delay(200);
  }
}

// 🔁 Smooth mirrored movement
void moveServos(int target) {

  if (target > currentPos) {
    for (int pos = currentPos; pos <= target; pos++) {
      leftServo.write(pos);
      rightServo.write(180 - pos);
      delay(15);
    }
  } else {
    for (int pos = currentPos; pos >= target; pos--) {
      leftServo.write(pos);
      rightServo.write(180 - pos);
      delay(15);
    }
  }

  currentPos = target;
}