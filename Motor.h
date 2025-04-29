#ifndef MOTOR_H
#define MOTOR_H

class Motor {
  private:
    int speedPinA;  // Pin controlling speed
    int speedPinB; // Pin controlling LPWM
    int dirPinA;   // Pin controlling direction A
    int dirPinB;   // Pin controlling direction B
    int speed;
    double power;
  public:
    // Constructor that takes 3 parameters: speed pin and two direction pins
    Motor(int speedPin, int dirPinA, int dirPinB);
    Motor(int speedPinA, int speedPinB);

    // Method to initialize the motor pins
    void begin();

    // Method to set motor speed
    void setSpeed(int speed);

    // Method to control motor direction (for simplicity, just ON/OFF in this example)
    void setDirection(bool dirA, bool dirB);

    void setPower(double power);

    int getSpeed();

    double getPower();
};

#endif
