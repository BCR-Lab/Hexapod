// @author Ting Ting Huang

#include "LegsController.h"

void LegsController::stand(){
  /**the position for vertical hip servo(the middle servo of the leg)
   *is different than the position of horizontal hip and knee servo (P1500)
   *for up standing, the position for is LVH P2000, for RVH is P1000.  
   */
  for(int i=0; i<6; i++) {    
    HHSP[i]=1500;
    KSP[i]=1500;

    if(i%2==0) {
      VHSP[i]=2000;
    }
    else{
      VHSP[i]=1000;
    }
    
  }

}

void LegsController::sit() {
  for(int i=0; i<6; i++) {    
    HHSP[i]=1500;
    if(i%2==0) {
      VHSP[i]=1000;
      KSP[i]= 800;
    }

    else{
      VHSP[i]=2000;
      KSP[i]= 2200;
    }
  }

}

void LegsController::setLegsToNeutral(){
  for(int i=0; i<6; i++) {    
    HHSP[i]=1500;
    if(i%2==0) {
      VHSP[i]=1700;
      KSP[i]= 1200;
    }

    else{
      VHSP[i]=1300;
      KSP[i]= 1800;
    }
   
  }

}
//left front leg controller
void LegsController::liftLF(int p){
   VHSP[0]=VHSP[0]-p;
}
void LegsController::lowerLF(int p){
   VHSP[0]=VHSP[0]+p;
}
void LegsController::moveLFKneeOutward(int p){
   KSP[0]=KSP[0]+p;
}
void LegsController::moveLFKneeInward(int p){
   KSP[0]=KSP[0]-p;
}

void LegsController::moveLFForward(int p){
  HHSP[0]=HHSP[0] - p;
}
void LegsController::moveLFBackward(int p){
  HHSP[0]=HHSP[0] + p;
}

//left middile leg controller
void LegsController::liftLM(int p){
   VHSP[2]=VHSP[2]-p;
}
void LegsController::lowerLM(int p){
   VHSP[2]=VHSP[2]+p;
}
void LegsController::moveLMKneeOutward(int p){
   KSP[2]=KSP[2]+p;
}
void LegsController::moveLMKneeInward(int p){
   KSP[2]=KSP[2]-p;
}

void LegsController::moveLMForward(int p){
  HHSP[2]=HHSP[2] - p;
}
void LegsController::moveLMBackward(int p){
  HHSP[2]=HHSP[2] + p;
}

//left rear leg controller
void LegsController::liftLR(int p){
   VHSP[4]=VHSP[4]-p;
}
void LegsController::lowerLR(int p){
   VHSP[4]=VHSP[4]+p;
}
void LegsController::moveLRKneeOutward(int p){
   KSP[4]=KSP[4]+p;
}
void LegsController::moveLRKneeInward(int p){
   KSP[4]=KSP[4]-p;
}

void LegsController::moveLRForward(int p){
  HHSP[4]=HHSP[4] - p;
}
void LegsController::moveLRBackward(int p){
  HHSP[4]=HHSP[4] + p;
}

//right front leg controller
void LegsController::liftRF(int p){
   VHSP[1]=VHSP[1]+p;
}
void LegsController::lowerRF(int p){
   VHSP[1]=VHSP[1]-p;
}
void LegsController::moveRFKneeOutward(int p){
   KSP[1]=KSP[1]-p;
}
void LegsController::moveRFKneeInward(int p){
   KSP[1]=KSP[1]+p;
}

void LegsController::moveRFForward(int p){
  HHSP[1]=HHSP[1] + p;
}
void LegsController::moveRFBackward(int p){
  HHSP[1]=HHSP[1] - p;
}


//right middler leg controller
void LegsController::liftRM(int p){
   VHSP[3]=VHSP[3]+p;
}
void LegsController::lowerRM(int p){
   VHSP[3]=VHSP[3]-p;
}
void LegsController::moveRMKneeOutward(int p){
   KSP[3]=KSP[3]-p;
}
void LegsController::moveRMKneeInward(int p){
   KSP[3]=KSP[3]+p;
}

void LegsController::moveRMForward(int p){
  HHSP[3]=HHSP[3] + p;
}
void LegsController::moveRMBackward(int p){
  HHSP[3]=HHSP[3] - p;
}

//right rear leg controller
void LegsController::liftRR(int p){
   VHSP[5]=VHSP[5]+p;
}
void LegsController::lowerRR(int p){
   VHSP[5]=VHSP[5]-p;
}
void LegsController::moveRRKneeOutward(int p){
   KSP[5]=KSP[5]-p;
}
void LegsController::moveRRKneeInward(int p){
   KSP[5]=KSP[5]+p;
}

void LegsController::moveRRForward(int p){
  HHSP[5]=HHSP[5] + p;
}
void LegsController::moveRRBackward(int p){
  HHSP[5]=HHSP[5] - p;
}

void LegsController::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
  
   
}

// pair each servos with its desired postion
// used writeToServo funtion to print these data to the serial port
void LegsController::writeToLegServos() {
  for(int i=0; i<6; i++) {
    writeToServo(HHS[i], HHSP[i]);
    writeToServo(VHS[i], VHSP[i]);
    writeToServo(KS[i], KSP[i]);
    
  }
}
