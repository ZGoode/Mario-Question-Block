#include "ADXL335.h"

/***********************************************************************************************
   Connect X_OUT to A0
   Connect Y_OUT to A1
   Connect Z_OUT to A2
*/

ADXL335 accelerometer;

void setup() {
  Serial.begin(9600);
  accelerometer.begin();
}

void loop() {
  float ax;
  float ay;
  float az;

  accelerometer.getAcceleration(&ax, &ay, &az);
  Serial.println("accleration of X/Y/Z: ");
  Serial.print(ax);
  Serial.println(" g");
  Serial.print(ay);
  Serial.println(" g");
  Serial.print(az);
  Serial.println(" g");
  delay(500);
}
