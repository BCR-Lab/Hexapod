#ifndef CLAWCLASS_h
#define CLAWCLASS_h

#include "Arduino.h"


class ClawClass {
  const int left_Claw=29; 
  const int right_Claw=28;  
 
  const int l_fullyOpen=1450;
  const int r_fullyOpen=1500;

  const int l_fullyClose=1210;
  const int r_fullyClose=1740;

  //const int diff_btw_open_close=270;
  
  public:
  int left_curr=1450;
  int right_curr=1500;
  void fully_open(int speed);
  void fully_close(int speed);
  void close(int left_dest, int right_dest, int speed);  
  void move(char instruction,int left_dest, int right_dest, int speed);
  void writeToServo(int servo, int position, int time);

  
};
#endif
