#include "coin.h"
#include "iris_gate.h"
#include <PCM.h>

/**********************************************************************
    Connect vibration sensor to pin 10

    Connect transistor for light to pin 8
    Connect transistor for speaker to pin 11
**********************************************************************/

const int light = 8;
const int vibration = 10;
const long delayValue = 5000;

void toggleLight();

void setup() {
  pinMode(vibration, INPUT);
  pinMode(light, OUTPUT);
}

void loop() {
  int val;
  val = digitalRead(vibration);
  
  if (val == 1) {
    toggleLight();
  }
}

void toggleLight() {
  if (digitalRead(light) == HIGH) {
    digitalWrite(light, LOW);
    startPlayback(iris_gate, NUM_ELEMENTS_IRIS_GATE);
    delay(797);
    stopPlayback();
    delay(delayValue);
  } else if (digitalRead(light) == LOW) {
    digitalWrite(light, HIGH);
    startPlayback(coin, NUM_ELEMENTS_COIN);
    delay(419);
    stopPlayback();
    delay(delayValue);
  }
}