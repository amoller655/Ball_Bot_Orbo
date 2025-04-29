#include "Drive.h"
#include "Arduino.h"

// Constructor for Drive class, initializes 3 Motor instances with parameters
Drive::Drive(int speed1, int dirA1, int dirB1, 
             int speed2, int dirA2, int dirB2, 
             int speed3, int dirA3, int dirB3)
  : motor1(speed1, dirA1, dirB1), 
    motor2(speed2, dirA2, dirB2), 
    motor3(speed3, dirA3, dirB3) {
}

Drive::Drive(int speedA1, int speedB1,
          int speedA2, int speedB2,
          int speed3, int dirA3, int dirB3) 
  : motor1(speedA1, speedB1),
    motor2(speedA2, speedB2),
    motor3(speed3, dirA3, dirB3) {

}

// Initialize all motors
void Drive::begin() {
  motor1.begin();
  motor2.begin();
  motor3.begin();
  Serial.println("Drive started");
}

// Set speeds for all motors
void Drive::setSpeeds(int speed1, int speed2, int speed3) {
  motor1.setSpeed(speed1);
  motor2.setSpeed(speed2);
  motor3.setSpeed(speed3);
}

// Set directions for all motors
void Drive::setDirections(bool dirA1, bool dirB1, bool dirA2, bool dirB2, bool dirA3, bool dirB3) {
  motor1.setDirection(dirA1, dirB1);
  motor2.setDirection(dirA2, dirB2);
  motor3.setDirection(dirA3, dirB3);
}

double Drive::getMotor1Power() {
  return motor1.getPower();
}

double Drive::getMotor2Power() {
  return motor2.getPower();
}

double Drive::getMotor3Power() {
  return motor3.getPower();
}

void Drive::setMotors(double x, double y) {
  double cmdAngle = atan2(y,x);
  double m1Angle = 60*3.1415/180;
  double m2Angle = 180*3.1415/180;
  double m3Angle = 300*3.1415/180;

  double m1Diff = cmdAngle - m1Angle;
  double m2Diff = cmdAngle - m2Angle;
  double m3Diff = cmdAngle - m3Angle;

  double m1Pow = cos(m1Diff);
  double m2Pow = cos(m2Diff);
  double m3Pow = cos(m3Diff);
  
  motor1.setPower(m1Pow);
  motor2.setPower(m2Pow);
  motor3.setPower(m3Pow);
}

void Drive::setMotors2(double X, double Y, double R) {
  double W1 = -1/2 * X - sqrt(3)/2 * Y + R;
  double W2 = -1/2 * X + sqrt(3)/2 * Y + R;
  double W3 = X + R;
  double wheels[] = {abs(W1), abs(W2), abs(W3)};
  
  if(abs(W1) > 1.0) {
    W1 = W1/abs(W1);
    W2 = W2/abs(W1);
    W3 = W3/abs(W1);
  } else if(abs(W2) > 1.0) {
    W1 = W1/abs(W2);
    W2 = W2/abs(W2);
    W3 = W3/abs(W2);
  } else if(abs(W3) > 1.0) {
    W1 = W1/abs(W3);
    W2 = W2/abs(W3);
    W3 = W3/abs(W3);
  }

  motor1.setPower(W1);
  motor2.setPower(W2);
  motor3.setPower(W3);
}

void Drive::setMotorsFull() {
  motor1.setPower(0.5);
  motor2.setPower(0.5);
  motor3.setPower(0.5);
  // motor1.setDirection(true, false);
  // motor1.setSpeed(120);
  // motor2.setDirection(true, false);
  // motor2.setSpeed(120);
  // motor3.setDirection(true, false);
  // motor3.setSpeed(120);
}

void Drive::forwards() {
  motor1.setDirection(true, false);
  motor2.setDirection(false, true);
  motor3.setDirection(false, false);
}

void Drive::backwards() {
  motor1.setDirection(false, true);
  motor2.setDirection(true, false);
  motor3.setDirection(false, false);
}

void Drive::left() {
  motor1.setDirection(true, false);
  motor2.setDirection(true, false);
  motor3.setDirection(true, false);
}

void Drive::right() {
  motor1.setDirection(false, true);
  motor2.setDirection(false, true);
  motor3.setDirection(false, true);
}

int Drive::getMotor1Speed() {
  return motor1.getSpeed();
}
