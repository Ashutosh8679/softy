#include <Servo.h>

Servo leftServo;
Servo rightServo;

const int leftServoPin  = 5;
const int rightServoPin = 6;

const int button1Pin = 2; // go to 0°
const int button2Pin = 3; // go to 90°

const int fsrPin = A0;
const int FORCE_THRESHOLD = 850;

int currentPos = 0;

void setup() {
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  Serial.begin(9600);

  leftServo.write(0);
  rightServo.write(180);
}

void loop() {

  if (digitalRead(button1Pin) == LOW) {
    moveServos(0);
    delay(200);
  }

  if (digitalRead(button2Pin) == LOW) {
    moveServos(90);
    delay(200);
  }
}

//  Movement with FORCE STOP
void moveServos(int target) {

  if (target > currentPos) {
    for (int pos = currentPos; pos <= target; pos++) {

      int fsrValue = analogRead(fsrPin);

      //  STOP CONDITION
      if (fsrValue >= FORCE_THRESHOLD) {
        Serial.println("Force limit reached! Stopping.");
        return;
      }

      leftServo.write(pos);
      rightServo.write(180 - pos);
      delay(15);
    }
  } else {
    for (int pos = currentPos; pos >= target; pos--) {

      int fsrValue = analogRead(fsrPin);

      // STOP CONDITION
      if (fsrValue >= FORCE_THRESHOLD) {
        Serial.println("Force limit reached! Stopping.");
        return;
      }

      leftServo.write(pos);
      rightServo.write(180 - pos);
      delay(15);
    }
  }

  currentPos = target;
}
