#include "Arduino.h"
#include "ClawClass.h"

ClawClass fiddler;
void setup() {
  Serial.begin(115200);
  fiddler.writeToServo(13, 1550, 2000); // no claw torsion.
  fiddler.fully_open(10); //straighten the claws

}

void loop() {
  // 14:up down
  // 12: left right
  
    
    fiddler.writeToServo(12, 1500,2000); //set in the mid
    fiddler.fully_open(5); //open claws;
    fiddler.writeToServo(14,2000, 4000); //lower down the claw;
        
   
    fiddler.close(1285, 1665, 5);  //grip the item
    delay(2000);

    fiddler.writeToServo(14,1500, 2000); //straighten the neck.
    
    fiddler.writeToServo(12, 2100,4000);
    fiddler.writeToServo(12, 1200,4000);
    fiddler.writeToServo(12, 1500,4000);
    delay(2000);
    
    fiddler.writeToServo(14,2000, 4000); //lower down the claw;
    fiddler.fully_open(5);
    
    
}
