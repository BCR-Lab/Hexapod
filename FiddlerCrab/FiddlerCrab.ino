#include "Arduino.h"
#include "FiddlerCrab.h"

FiddlerCrab crab;

void setup() {
  Serial.begin(115200);
  crab.claw.setToNeutral();
  crab.legs.rest(1000);

  delay(2000);
  

   
}

void loop() {
 

  crab.legs.center(1000);
  delay(2000);
  crab.legs.rest(1000);

  delay(2000);


}
