#ifndef Drive_h
#define Drive_h
#include "Arduino.h"
#include "Motor.h"

class Drive : public Motor{
  public:
    // Drive(int cycleTime) : _motor1(int speed1, int dirA1, int dirB1), _motor2(int speed2, int dirA2, int dirB2), _motor3(int speed3, int dirA3, int dirB3);
        Drive(int speed1, int dirA1, int dirB1, 
          int speed2, int dirA2, int dirB2, 
          int speed3, int dirA3, int dirB3);
          
    void setMotorPowers(float pow1, float pow2, float pow3);
    
  private:
    Motor motor1;
    Motor motor2;
    Motor motor3;
    int _cycleTime;
    int M;
};
#endif