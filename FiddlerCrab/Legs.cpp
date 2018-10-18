#include "Legs.h"

Legs::Legs(){
  
}

void Legs::stand(){
  Serial.println("#24 P1500 #20 P1500 #16 P1500 #08 P1500 #04 P1500 #00 P1500 T2000");
  delay(2000);
  Serial.println("#25 P2000 #21 P2000 #17 P2000 #09 P1000 #05 P1000 #01 P1000 T2000");
  delay(2000);
  Serial.println("#26 P1500 #22 P1500 #18 P1500 #10 P1500 #06 P1500 #02 P1500 T2000");
  delay(2000);
}

void Legs::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   
}
