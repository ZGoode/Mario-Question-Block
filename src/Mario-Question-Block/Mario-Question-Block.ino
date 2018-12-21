#include "ADXL335.h"
#include "coin.h"
#include <PCM.h>

/**********************************************************************
    Connect X_OUT to A0
    Connect Y_OUT to A1
    Connect Z_OUT to A2

    Connect transistor for light to pin 8
    Connect transistor for speaker to pin 11
**********************************************************************/

ADXL335 accelerometer;
const int light = 8;

void toggleLight();

void setup() {
  accelerometer.begin();
  pinMode(light, OUTPUT);
}

void loop() {
  float ax;
  float ay;
  float az;

  accelerometer.getAcceleration(&ax, &ay, &az);

  if ((ax > /*acceleration threshold*/) || (ay > /*acceleration threshold*/) || (az > /*acceleration threshold*/)) {
    toggleLight();
    startPlayback(data, NUM_ELEMENTS);
    delay(/*length of soundbite in ms*/);
    stopPlayback();
    delay(/*choose time before trigger of light again*/);
  }
}

void toggleLight() {
  if (digitalRead(light) == HIGH) {
    digitalWrite(light, LOW);
  } else if (digitalRead(8) == LOW) {
    digitalWrite(light, HIGH);
  }
}
