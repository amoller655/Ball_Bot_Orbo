#include "Motor.h"
#include "Drive.h"
#include "Arduino.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// Drive drive;
int speed1 = 3;
int dirA1 = 1;
int dirB1 = 0;

int speed2 = 5;
int dirA2 = 4;
int dirB2 = 2;

int speed3 = 9;
int dirA3 = 8;
int dirB3 = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  matrix.begin();
  Motor motor1 = Motor(speed1, dirA1, dirB1);
  // drive = Drive(speed1, dirA1, dirB1, speed2, dirA2, dirB2, speed3, dirA3, dirB3, 10);
}

void loop() {
  // put your main code here, to run repeatedly:

  // drive.setMotorPowers(1.0, 0.5, 0.1);

  // Serial.println(drive.motor1.getPWM());
  // Serial.println(drive.motor2.getPWM());
  // Serial.println(drive.motor3.getPWM());
  // Serial.println("");
  
  // uint32_t pwms[] = {
  //   (byte) drive.motor1.getPWM(),
  //   (byte) drive.motor2.getPWM(),
  //   (byte) drive.motor3.getPWM()
  // }

  // matrix.loadFrame(pwms);
  delay(500);
}
