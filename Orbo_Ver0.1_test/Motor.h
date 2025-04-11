#ifndef Motor_h
#define Motor_h
#include "Arduino.h"
class Motor {
  public:
    Motor(int speedPin, int dirPinA, int dirPinB);
    void setDirection(int dir);
    void setSpeed(float speed);
    void setPower(float power);
    int getPWM();
    float getPower();
  private:
    int _speedPin;
    int _dirPinA;
    int _dirPinB;
    float _power;
    int _pwmSpeed;
    int _dir;
};
#endif