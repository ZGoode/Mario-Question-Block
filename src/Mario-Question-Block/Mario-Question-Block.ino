#include "ADXL335.h"
#include "coin.h"
#include "iris_gate.h"
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

  if ((ax > 2.5) || (ay > 2.5) || (az > 2.5)) {
    toggleLight();
  }
}

void toggleLight() {
  if (digitalRead(light) == HIGH) {
    digitalWrite(light, LOW);
    
  } else if (digitalRead(light) == LOW) {
    digitalWrite(light, HIGH);
    startPlayback(data, NUM_ELEMENTS);
    delay(/*length of soundbite in ms*/);
    stopPlayback();
    delay(/*choose time before trigger of light again*/
  }
}
