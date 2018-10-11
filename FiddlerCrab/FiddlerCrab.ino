#include "Arduino.h"
#include "FiddlerCrab.h"

ClawClass fiddler;


void setup() {
  Serial.begin(115200 );
  Serial.println("#24 P1500 #20 P1500 #16 P1500 #08 P1500 #04 P1500 #00 P1500 T2000");
  delay(2000);
  Serial.println("#25 P2000 #21 P2000 #17 P2000 #09 P1000 #05 P1000 #01 P1000 T2000");
  delay(2000);
  Serial.println("#26 P1500 #22 P1500 #18 P1500 #10 P1500 #06 P1500 #02 P1500 T2000");
  delay(2000);
  
  fiddler.fully_open(5); //open claws; 
  fiddler.verticalMovement(2000,2000); //lower down the claw;

}

void loop() {
  // 14:up down
  // 12: left right
  
  
    fiddler.close(1285, 1665, 5);  //grip the item
    delay(2000);

    fiddler.verticalMovement(1500,1000);//straighten the carpus.

    //move from left-->right-->mid
    fiddler.horizontalMovement(2000,2000);
    fiddler.horizontalMovement(1000,2000);
    fiddler.horizontalMovement(1500,2000);
    delay(2000);
    
    fiddler.verticalMovement(2000,2000); //lower down the claw;
    fiddler.fully_open(5);
    delay(1000);
    
    
}

/**
void setup(){
  Serial.begin(115200);
}
void loop() {
  Serial.println("#24 P1500 #20 P1500 #16 P1500 #08 P1500 #04 P1500 #00 P1500 T2000");
  delay(2000);
  Serial.println("#25 P2000 #21 P2000 #17 P2000 #09 P1000 #05 P1000 #01 P1000 T2000");
  delay(2000);
  Serial.println("#26 P1500 #22 P1500 #18 P1500 #10 P1500 #06 P1500 #02 P1500 T2000");
  delay(2000);
  
}*/
