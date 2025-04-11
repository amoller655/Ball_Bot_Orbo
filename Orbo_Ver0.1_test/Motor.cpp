#include "Arduino.h"
#include "Motor.h"
#include "Drive.h"

Motor::Motor(int speedPin, int dirPinA, int dirPinB) {
  pinMode(speedPin, OUTPUT);
  pinMode(dirPinA, OUTPUT);
  pinMode(dirPinB, OUTPUT);
  _speedPin = speedPin;
  _dirPinA = dirPinA;
  _dirPinB = dirPinB;

  _power = 0.0;
  _pwmSpeed = 0;
  _dir = 0;
}

void Motor::setDirection(int dir) {
  if(dir >= 0){
    digitalWrite(_dirPinA, HIGH);
    digitalWrite(_dirPinB, LOW);
  } else {
    digitalWrite(_dirPinA, LOW);
    digitalWrite(_dirPinB, HIGH);
  }
}

void Motor::setSpeed(float speed) {
  speed = abs(speed);
  if(speed > 1.0) {
    speed = 1.0;
  }
  _pwmSpeed = map(speed, 0.0, 1.0, 0, 255);
  analogWrite(_speedPin, _pwmSpeed);
}

void Motor::setPower(float power) {
  if(power > 1.0) {
    power = 1.0;
  } else if(power < -1.0) {
    power = -1.0;
  }
  
  if(power >= 0) {
    setDirection(1);
  } else {
    setDirection(-1);
  }
  setSpeed(power);
}

int Motor::getPWM() {
  return _pwmSpeed;
}






