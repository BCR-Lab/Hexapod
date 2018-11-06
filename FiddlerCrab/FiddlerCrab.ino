#include "Arduino.h"
#include "FiddlerCrab.h"

FiddlerCrab crab;

void setup() {
  Serial.begin(115200);
  crab.claw.setToNeutral();
 
}

void loop() {
 crab.legs.neutral();
 Serial.println("T200");
 delay(200);
}
