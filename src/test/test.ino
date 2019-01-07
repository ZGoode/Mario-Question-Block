#include "coin.h"
#include "iris_gate.h"
#include "power_up.h"
#include "power_up_appears.h"
#include <PCM.h>

void setup() {
}

void loop() {
  startPlayback(coin, NUM_ELEMENTS_COIN);
  delay(420);
  stopPlayback();
  delay(5000);
  startPlayback(power_up, NUM_ELEMENTS_POWER_UP);
  delay(847);
  stopPlayback();
  delay(5000);
  startPlayback(power_up_appears, NUM_ELEMENTS_POWER_UP_APPEARS);
  delay(468);
  stopPlayback();
  delay(5000);
  startPlayback(iris_gate, NUM_ELEMENTS_IRIS_GATE);
  delay(798);
  stopPlayback();
  delay(5000);
}
