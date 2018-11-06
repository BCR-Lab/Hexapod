#include "Legs.h"

Legs::Legs(){
 
}

void Legs::center(){
  /**the position for vertical hip servo(the middle servo of the leg)
   *is different than the position of horizontal hip and knee servo (P1500)
   *for up standing, the position for is LVH P2000, for RVH is P1000.  
   */
  for(int i=0; i<6; i++) {    
    HHSP[i]=1500;
    KSP[i]=1500; 
  }

  VHSP[0]=2000;
  VHSP[2]=1000;
  VHSP[4]=2000;
  
  VHSP[1]=1000;
  VHSP[3]=2000;
  VHSP[5]=1000;
  
  writeToServo();
  /*
  Serial.print(" T");
  Serial.println(time);
  delay(2*time);
  */
}

void Legs::rest() {
   for(int i=0; i<6; i++) {    
    HHSP[i]=1500;
    //KSP[i]=1500; 
  }

  VHSP[0]=1000;
  VHSP[2]=2000;
  VHSP[4]=1000;
  
  VHSP[1]=2000;
  VHSP[3]=1000;
  VHSP[5]=2000;

  KSP[0]= 800;
  KSP[3]= 800;
  KSP[4]= 800;

  KSP[1]= 2200;
  KSP[2]= 2200;
  KSP[5]= 2200;
  
  writeToServo();

  /*
  Serial.print(" T");
  Serial.println(time);
  delay(2*time);

  */
}

void Legs::down() {
  
}
void Legs::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
  
   
}

void Legs::writeToServo() {
  for(int i=0; i<6; i++) {
    writeToServo(HHS[i], HHSP[i]);
    writeToServo(VHS[i], VHSP[i]);
    writeToServo(KS[i], KSP[i]);
    
  }
  
}

void Legs::test() {
  for(int i=0; i<6; i=i+2) {    
    KSP[i]=1000; 
  }

  writeToServo();
  Serial.println(" T400");
  delay(800);
}
