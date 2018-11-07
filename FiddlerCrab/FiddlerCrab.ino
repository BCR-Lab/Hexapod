#include "Arduino.h"
#include "FiddlerCrab.h"

FiddlerCrab crab;

void setup() {
  Serial.begin(115200);
  crab.claw.setToNeutral();

  delay(2000);
  

   
}

void loop() {
  int t;
  t=50;
  for(int i=0; i<5; i++) {
   crab.legs.stand();
   crab.claw.fully_close();
    
    Serial.print(" T");
    Serial.println(t);
    delay(2*t);
    
    crab.legs.sit();
    crab.claw.fully_open();

    Serial.print(" T");
    Serial.println(t);
    delay(2*t);

    
  
  }

  delay(2000);
  


}
