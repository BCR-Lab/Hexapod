// @author Ting Ting Huang

#ifndef LEGSCONTROLLER_H
#define LEGSCONTROLLER_H

#include "Arduino.h"

class LegsController{
  
  /**
   * HHS = horizontal hip servo
   * VHS = vertical hip servo
   * KS = knee servo
   * 
   * 
   * LF = left front leg
   * RF = right front leg
   * RM = right middle leg
   * LM = left middle leg
   * LR = left rear leg
   * RR = right rear leg
   */
   //                0, 1, 2,  3, 4, 5
  //                 LF,RF,LM,RM,LR,RR  
  const int HHS[6] = {24,8,20,4,16,0}; //used here to set servo sequence
  const int VHS[6] = {25,9,21,5,17,1}; 
  const int KS[6] =  {26,10,22,6,18,2};
  
public:

  //position for HHS, VHS, and KS'
  int HHSP[6];
  int VHSP[6];
  int KSP[6];

	  
  void stand();
  void sit();
  void setLegsToNeutral(); 
 

  
  void liftLF(int p);
  void lowerLF(int p);
  void moveLFKneeOutward(int p);
  void moveLFKneeInward(int p);
  void moveLFForward(int p);
  void moveLFBackward(int p);
   
  
  void liftLM(int p);
  void lowerLM(int p);
  void moveLMKneeOutward(int p);
  void moveLMKneeInward(int p);
  void moveLMForward(int p);
  void moveLMBackward(int p);

  void liftLR(int p);
  void lowerLR(int p);
  void moveLRKneeOutward(int p);
  void moveLRKneeInward(int p);
  void moveLRForward(int p);
  void moveLRBackward(int p);

  void liftRF(int p);
  void lowerRF(int p);
  void moveRFKneeOutward(int p);
  void moveRFKneeInward(int p);
  void moveRFForward(int p);
  void moveRFBackward(int p);

  void liftRM(int p);
  void lowerRM(int p);
  void moveRMKneeOutward(int p);
  void moveRMKneeInward(int p);
  void moveRMForward(int p);
  void moveRMBackward(int p);

  void liftRR(int p);
  void lowerRR(int p);
  void moveRRKneeOutward(int p);
  void moveRRKneeInward(int p);
  void moveRRForward(int p);
  void moveRRBackward(int p);
  
  void writeToServo(int servo, int position);
  void writeToLegServos();
 



	
};
#endif
