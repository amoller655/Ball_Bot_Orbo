#include "Arduino.h"
#include "Motor.h"
#include "Drive.h"


Drive::Drive(int speed1, int dirA1, int dirB1, 
             int speed2, int dirA2, int dirB2, 
             int speed3, int dirA3, int dirB3)
  : motor1(speed1, dirA1, dirB1), 
    motor2(speed2, dirA2, dirB2), 
    motor3(speed3, dirA3, dirB3) {
}

// Drive::Drive(int speed1, int dirA1, int dirB1, int speed2, int dirA2, int dirB2, int speed3, int dirA3, int dirB3, int cycleTime) {
//   _motor1 = new Motor(speed1, dirA1, dirB1);
//   motor2 = new Motor(speed2, dirA2, dirB2);
//   motor3 = new Motor(speed3, dirA3, dirB3);
  
// }

void Drive::setMotorPowers(float pow1, float pow2, float pow3) {
  motor1.setPower(pow1);
  motor2.setPower(pow2);
  motor3.setPower(pow3);
}

