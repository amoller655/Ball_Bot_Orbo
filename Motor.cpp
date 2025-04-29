#include "Motor.h"
#include <Arduino.h>

// Constructor for Motor, takes 3 parameters
Motor::Motor(int speedPin, int dirPinA, int dirPinB) {
  this->speedPinA = speedPin;
  this->speedPinB = -1;
  this->dirPinA = dirPinA;
  this->dirPinB = dirPinB;
}

Motor::Motor(int speedPinA, int speedPinB) {
  this->speedPinA = speedPinA;
  this->speedPinB = speedPinB;
  this->dirPinA = -1;
  this->dirPinB = -1;
}

// Initialize the motor by setting pins as OUTPUT
void Motor::begin() {
  if(speedPinB == -1) {
    pinMode(speedPinA, OUTPUT);
    pinMode(dirPinA, OUTPUT);
    pinMode(dirPinB, OUTPUT);
  } else {
    Serial.println("Motor Started");
    pinMode(speedPinA, OUTPUT);
    pinMode(speedPinB, OUTPUT);
  }
  
}

// Set the motor speed (0 to 255)
void Motor::setSpeed(int speed) {
  
  if(speedPinB == -1) {
    this->speed = abs(speed);
    analogWrite(speedPinA, abs(speed));
  } else {
    this->speed = speed;
    if(speed >= 0) {
      analogWrite(speedPinA, abs(speed));
      analogWrite(speedPinB, 0);
    } else {
      analogWrite(speedPinB, abs(speed));
      analogWrite(speedPinA, 0);
    }
  }
  
}
int Motor::getSpeed() {
  return speed;
}
// Set the direction of the motor (control two direction pins)
void Motor::setDirection(bool dirA, bool dirB) {
  if(speedPinB == -1) {
    digitalWrite(dirPinA, dirA);
    digitalWrite(dirPinB, dirB);
  }
}

void Motor::setPower(double power) {

  if(power > 1.0) {
    power = 1.0;
  } else if (power < -1.0) {
    power = -1.0;
  }
  this->power = power;

  int pwmSpeed = power*255;

  if(speedPinB == -1) {
    if(pwmSpeed >= 0) {
      setDirection(true, false);
    } else {
      setDirection(false, true);
    }
    Motor::setSpeed(abs(pwmSpeed));
  } else {
    Motor::setSpeed(pwmSpeed);
  }
}

double Motor::getPower() {
  return power;
}
