#include <Arduino.h>
#include "Drive.h"
#include "PsxControllerHwSpi.h"

// Define the motor pins

#define SPEED_PIN_A1 5
#define SPEED_PIN_B1 6
// #define SPEED_PIN_1 6
// #define DIR_PIN_A1 0
// #define DIR_PIN_B1 1

#define SPEED_PIN_A2 9
#define SPEED_PIN_B2 10
// #define SPEED_PIN_2 5
// #define DIR_PIN_A2 2
// #define DIR_PIN_B2 4

#define SPEED_PIN_3 3
#define DIR_PIN_A3 2
#define DIR_PIN_B3 4

const byte PIN_PS2_ATT = 8;
PsxControllerHwSpi<PIN_PS2_ATT> psx;

boolean haveController = false;

// void dumpAnalog (const char *str, const byte x, const byte y) {
// 	Serial.print (str);
// 	Serial.print (F(" analog: x = "));
// 	Serial.print (x);
// 	Serial.print (F(", y = "));
// 	Serial.println (y);
// }

Drive drive(SPEED_PIN_A1, SPEED_PIN_B1,
            SPEED_PIN_A2, SPEED_PIN_B2,
            SPEED_PIN_3, DIR_PIN_A3, DIR_PIN_B3);
// Drive drive(SPEED_PIN_1, DIR_PIN_A1, DIR_PIN_B1,
//             SPEED_PIN_2, DIR_PIN_A2, DIR_PIN_B2,
//             SPEED_PIN_3, DIR_PIN_A3, DIR_PIN_B3);




void setup() {
  Serial.begin(115200);
  Serial.println("Hello");
  drive.begin();  // Initialize the motors
  Serial.println("Setup done");
}

void loop() {

  
  if (!haveController) {
    
    if(psx.begin()){
      Serial.println("Controller found");
      delay(300);
      psx.enterConfigMode();
      psx.enableAnalogSticks();
      psx.exitConfigMode();
      Serial.println("Controller ready");
      haveController = true;
    } 
  } else {
    Serial.println("reading controller");
    if (!psx.read()) {
      Serial.println("Controller lost");
      haveController = false;
    } else {
      byte lx, ly, rx, ry;
      double xUnit, yUnit, R;
      double mag;
      psx.getLeftAnalog(lx, ly);
      psx.getRightAnalog(rx, ry);

      int x = (int) lx;
      int y = (int) ly;

      int r = (int) rx;


      x = x - 127;
      if ((x < 40) && (x > -40)) {
        x = 0;
      }
      x = -x;

      y = y - 127;
      if ((y < 40) && (y > -40)) {
        y = 0;
      }
      y = -y;

      r = r - 127;
      if ((r < 5) && (r > -5)) {
        r = 0;
      }
      r = -r;

      R = r/128;

      mag = sqrt(pow(x,2)+ pow(y,2));
      xUnit = x/mag;
      yUnit = y/mag;
      
      
      // if(xUnit != 0.0 && yUnit != 0.0) {
      //   if(abs(yUnit) >= 1.5*abs(xUnit)) {
      //     // if(yUnit > 0) {
      //     //   drive.forwards();
      //     // } else {
      //     //   drive.backwards();
      //     // }
      //     drive.setMotors2(0.0, yUnit, 0.0);
      //   }
      //   else {
      //     // if(xUnit > 0) {
      //     //   drive.right();
      //     // } else {
      //     //   drive.left();
      //     // }
      //     drive.setMotors2(0.0, 0.0, -xUnit);
      //   }
      // }
      
      
      // drive.setMotors(xUnit, yUnit);
      
      // drive.setMotorsFull();

      // drive.setMotors2(0, yUnit, -xUnit);

      drive.setMotors2(xUnit, yUnit, R);

      // Serial.println(R);

      // Serial.print("x: ");
      // Serial.print(xUnit);
      // Serial.print(", y: ");
      // Serial.print(yUnit);
      // Serial.print(", Angle: ");
      // Serial.println(atan2(yUnit, xUnit));
      Serial.print("Motor 1: ");
      Serial.print(drive.getMotor1Power());
      Serial.print(", Motor 2: ");
      Serial.print(drive.getMotor2Power());
      Serial.print(", Motor 3: ");
      Serial.print(drive.getMotor3Power());
      Serial.print(", Motor 1 Speed: ");
      Serial.println(drive.getMotor1Speed());

      // Serial.print(x);
      // Serial.print(", ");
      // Serial.print(y);
      // Serial.print(", ");
      // Serial.print(xUnit);
      // Serial.print(", ");
      // Serial.print(yUnit);
      // Serial.print(", ");
      // Serial.println(mag);
      // Serial.println(cos(60*3.14/180));
      // drive.setSpeeds(lx, 0, 0);
    }
  }
  delay(1000/60);

  // // Example: Set speeds and directions for all motors
  // drive.setSpeeds(192, 0, 0);  // Set motor speeds (0-255)
  // drive.setDirections(true, false, true, false, false, true);  // Set directions
  
  // Serial.println(drive.getMotor1Speed());

  // delay(2000); // Wait for 2 seconds

  // // Reverse directions and set speeds again
  // //drive.setDirections(false, true, false, true, true, false);
  // drive.setSpeeds(92,0,0);

  // Serial.println(drive.getMotor1Speed());

  // delay(2000); // Wait for 2 seconds
}
