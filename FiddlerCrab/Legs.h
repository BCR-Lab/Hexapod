#ifndef LEGS_H
#define LEGS_H

#include "Arduino.h"

class Legs{
  
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
  //                 LF,RF,RM,LM,LR,RR  
  const int HHS[6] = {24,8,4,20,16,0}; //used here to set servo sequence
  const int VHS[6] = {25,9,5,21,17,1}; 
  const int KS[6] =  {26,10,6,22,18,2};
  
public:

  //position for HHS, VHS, and KS'
  int HHSP[6];
  int VHSP[6];
  int KSP[6];

	Legs();  
  void center();
  void up();
  void down();
  void rest();
  void writeToServo(int servo, int position);
  void writeToServo();
  void walk();
  void test();


	
};
#endif
