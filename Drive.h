#ifndef DRIVE_H
#define DRIVE_H

#include "Motor.h"

class Drive {
  private:
    Motor motor1;
    Motor motor2;
    Motor motor3;

  public:
    // Constructor takes parameters for each motor (speed and direction pins)
    Drive(int speed1, int dirA1, int dirB1, 
          int speed2, int dirA2, int dirB2, 
          int speed3, int dirA3, int dirB3);

    Drive(int speedA1, int speedB1,
          int speedA2, int speedB2,
          int speed3, int dirA3, int dirB3);

    // Method to initialize all motors
    void begin();

    // Method to set speeds for all motors
    void setSpeeds(int speed1, int speed2, int speed3);

    // Method to set directions for all motors
    void setDirections(bool dirA1, bool dirB1, bool dirA2, bool dirB2, bool dirA3, bool dirB3);

    double getMotor1Power();
    double getMotor2Power();
    double getMotor3Power();

    int getMotor1Speed();

    void setMotors(double x, double y);

    void setMotors2(double X, double Y, double R);

    void setMotorsFull();

    void forwards();

    void backwards();

    void left();

    void right();
};

#endif
