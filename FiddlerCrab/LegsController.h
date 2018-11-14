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
 

  
  void lift_left_frontleg(int p);
  void lower_left_frontleg(int p);
  void left_frontknee_out(int p);
  void left_frontknee_in(int p);
  void left_frontleg_forward(int p);
  void left_frontleg_backward(int p);
   
  void lift_left_middleleg(int p);
  void lower_left_middleleg(int p);
  void left_middleknee_out(int p);
  void left_middleknee_in(int p);
  void left_middleleg_forward(int p);
  void left_middleleg_backward(int p);

  void lift_left_rearleg(int p);
  void lower_left_rearleg(int p);
  void left_rearknee_out(int p);
  void left_rearknee_in(int p);
  void left_rearleg_forward(int p);
  void left_rearleg_backward(int p);

  void lift_right_frontleg(int p);
  void lower_right_frontleg(int p);
  void right_frontknee_out(int p);
  void right_frontknee_in(int p);
  void right_frontleg_forward(int p);
  void right_frontleg_backward(int p);

  void lift_right_middleleg(int p);
  void lower_right_middleleg(int p);
  void right_middleknee_out(int p);
  void right_middleknee_in(int p);
  void right_middleleg_forward(int p);
  void right_middleleg_backward(int p);

  void lift_right_rearleg(int p);
  void lower_right_rearleg(int p);
  void right_rearknee_out(int p);
  void right_rearknee_in(int p);
  void right_rearleg_forward(int p);
  void right_rearleg_backward(int p);
  
  void writeToServo(int servo, int position);
  void writeToLegServos();
 



	
};
#endif
