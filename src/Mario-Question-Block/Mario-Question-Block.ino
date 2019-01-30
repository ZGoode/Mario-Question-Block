#include "ADXL335.h"
#include "coin.h"
#include "iris_gate.h"
#include "power_up.h"
#include "power_up_appears.h"
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
const float thresholdValue = 2.00;
const long delayValue = 5000;

void toggleLight();

void setup() {
  accelerometer.begin();
  Serial.begin(9600);
  Serial.println("Begin");
  pinMode(light, OUTPUT);
}

void loop() {
  float ax;
  float ay;
  float az;

  accelerometer.getAcceleration(&ax, &ay, &az);

  if ((ax > thresholdValue) || (ay > thresholdValue) || (az > thresholdValue)) {
    toggleLight();
  }
}

void toggleLight() {
  Serial.println("triggered");
  if (digitalRead(light) == HIGH) {
    digitalWrite(light, LOW);
    startPlayback(iris_gate, NUM_ELEMENTS_IRIS_GATE);
    delay(797);
    stopPlayback();
    delay(delayValue);
  } else if (digitalRead(light) == LOW) {
    digitalWrite(light, HIGH);
    int rng = random(3);

    if (rng == 0) {
      startPlayback(coin, NUM_ELEMENTS_COIN);
      delay(419);
      stopPlayback();
    } else if (rng == 1) {
      startPlayback(power_up, NUM_ELEMENTS_POWER_UP);
      delay(846);
      stopPlayback();
    } else if (rng == 2) {
      startPlayback(power_up_appears, NUM_ELEMENTS_POWER_UP_APPEARS);
      delay(467);
      stopPlayback();
    }
    delay(delayValue);
  }
}
