#ifndef CLAWCLASS_h
#define CLAWCLASS_h

#include "Arduino.h"

class ClawClass {
    const int LEFT_CLAW = 29;   
    const int RIGHT_CLAW = 28;
    const int UP_DOWN = 14;       // up<--- 1500++++>down
    const int LEFT_RIGHT = 12;   //L->R 2000->1000
    const int TORSION = 13;


  public:

    int l_fully_open;
    int r_fully_open;

    int l_fully_close;
    int r_fully_close;
    
    //int left_curr;
    //int right_curr;
    //int carpus_curr;

    ClawClass();
    ClawClass(int l_open, int r_open, int l_close, int r_close);
    void setToNeutral();
    void fully_open(int time);
    void fully_close(int time);
    void close(int left_dest, int right_dest, int time);
    void horizontalMovement(int dest, int speed);
    void verticalMovement(int dest, int speed);
    void writeToServo(int servo, int position, int time);
    void writeToServo(int servo, int position);

    
   
    

  private:
     void moveClaw(int left_dest, int right_dest, int time);
     void move(char instruction, int left_dest, int right_dest, int speed);


};
#endif
