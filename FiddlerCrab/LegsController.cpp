// @author Ting Ting Huang

#include "LegsController.h"

/**
 * liftBody()
 * Assign the specific angular value to the HHSP, KSP,VHSP 
 * which allows robot to present a uplifted standing posture
 */
void LegsController::liftBody(){
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

/**
 * sit()
 * Assign the specific angular value to the HHSP, KSP,VHSP 
 * which allows robot to present a sitting posture
 */
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


/**
 * setLegsToNeutral()
 * Assign the specific angular value to the HHSP, KSP,VHSP 
 * which allows robot to present a neutral standing posture.
 * This is good height for walking mode 
 */
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


/**
 * liftLF(int p), lowerLF(int p, moveLFKneeOutward(int p), 
 * moveLFKneeInward(int p), moveLFForward(int p),moveLFBackward(int p).
 * 
 * These functions do what their name say to the left front leg. 
 * they only accept one argument, p. 
 * they use p to calculate the destination position for specific leg servo 
 * and assign the value to the variable that's in charge of holding position for that servo
 */

 
/***********left front leg controller****************/

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



/**
 * liftLM(int p), lowerLM(int p, moveLMKneeOutward(int p), 
 * moveLMKneeInward(int p), moveLMForward(int p),moveLMBackward(int p).
 * 
 * these methods function like the methods for left font leg (LF), except it's for left middle leg
 */
/***********left middile leg controller****************/

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


/**
 * liftLR(int p), lowerLR(int p, moveLRKneeOutward(int p), 
 * moveLRKneeInward(int p), moveLRForward(int p),moveLRBackward(int p).
 * 
 * these methods function like the methods for left front leg (LF), except it's for left rear leg
 */
 
/*****************left rear leg controller********************/
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



/**
 * liftRF(int p), lowerRF(int p, moveRFKneeOutward(int p), 
 * moveRFKneeInward(int p), moveRFForward(int p),moveRFBackward(int p).
 * 
 * these methods function like the methods for left font leg (LF), except it's for right front leg
 */

 
/************right front leg controller***********************/
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

/**
 * liftRM(int p), lowerRM(int p, moveRMKneeOutward(int p), 
 * moveRMKneeInward(int p), moveRMForward(int p),moveRMBackward(int p).
 * 
 * these methods function like the methods for left font leg (LF), except it's for right front leg
 */

/*************right middler leg controller*******************/
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


/**
 * liftRR(int p), lowerRR(int p, moveRRKneeOutward(int p), 
 * moveRRKneeInward(int p), moveRRForward(int p),moveRRBackward(int p).
 * 
 * these methods function like the methods for left font leg (LF), except it's for right front leg
 */
 
/**************right rear leg controller*******************/
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


/**
 * writeToServo(int servo, int position) 
 * print the servo ID with its corresponding angular position to the Serial port
 */
void LegsController::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
    
   
}

/**
 * writeToLegServos()
 * pair each servos with its desired postion
 * used writeToServo funtion to print these data to the serial port
 */

void LegsController::writeToLegServos() {
  for(int i=0; i<6; i++) {
    writeToServo(HHS[i], HHSP[i]);
    writeToServo(VHS[i], VHSP[i]);
    writeToServo(KS[i], KSP[i]);
    
  }
}


/**
 * writeToLegServos(int time) 
 * call writeToLegServos() 
 * and then print the execution time and carriage return to the serial port
 */
void LegsController::writeToLegServos(int time) {
  writeToLegServos();
  Serial.print("T");
  Serial.println(time);
  delay(time);
  
}
