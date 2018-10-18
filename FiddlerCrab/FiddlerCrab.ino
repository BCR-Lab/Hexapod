#include "Arduino.h"
#include "FiddlerCrab.h"
//#include "ClawClass.h"
//#include "Legs.h"

//ClawClass claw;
//Legs legs;
FiddlerCrab crab;


void setup() {
  Serial.begin(115200);
  crab.claw.setToNeutral();
  crab.legs.stand();
   
}

void loop() {


for(int i=0; i<10; i++) {
  crab.claw.fully_open(10);
  crab.claw.fully_close(10);
}

delay(5000);

for(int i=0; i<10; i++) {
  crab.claw.fully_open(50);
  crab.claw.fully_close(50);
}

delay(5000);

for(int i=0; i<10; i++) {
  crab.claw.fully_open(100);
  crab.claw.fully_close(100);
}

delay(5000);

for(int i=0; i<10; i++) {
  crab.claw.fully_open(500);
  crab.claw.fully_close(500);
}

delay(5000);


for(int i=0; i<10; i++) {
  crab.claw.fully_open(1000);
  crab.claw.fully_close(1000);
}

delay(5000);

for(int i=0; i<10; i++) {
  crab.claw.fully_open(2000);
  crab.claw.fully_close(2000);
}

delay(5000);
   
/**   

for(int i=0; i<10; i++) {
  Serial.println("#28 P1500 #29 P1450 T100");
  delay(200);
  Serial.println("#28 P1740 #29 P1210 T100");
  delay(200);
 }
  

   delay(4000);
   

 for(int i=0; i<10; i++) {
  Serial.println("#28 P1500 #29 P1450 T1500");
  delay(3000);
  Serial.println("#28 P1740 #29 P1210 T1500");
  delay(3000);
 }
  

   delay(4000);
*/
  /**
  for(int i=0; i<5; i++) {
    claw.fully_open(1);
    claw.fully_close(1);
  }
    
  delay(200);

  for(int i=0; i<10; i++) {
    claw.fully_open(5);
    claw.fully_close(5);
  }

  delay(200);

  for(int i=0; i<20; i++) {
   claw.fully_open(10);
   claw.fully_close(10);
  }

  delay(200);

   for(int i=0; i<30; i++) {
    claw.fully_open(50);
    claw.fully_close(50);
  }

  delay(200);

  for(int i=0; i<30; i++) {
    claw.fully_open(100);
    claw.fully_close(100);
  }

  delay(200);*/
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
