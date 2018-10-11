#ifndef CLAWCLASS_h
#define CLAWCLASS_h

#include "Arduino.h"


class ClawClass {
    const int LEFT_CLAW = 29;   
    const int RIGHT_CLAW = 28;
    const int UP_DOWN = 14;       // up<--- 1500++++>down
    const int LEFT_RIGHT = 12;   //L->R 2000->1000
    const int TORSION = 13;

    const int L_FULLY_OPEN = 1450;
    const int R_FULLY_OPEN = 1500;

    const int L_FULLY_CLOSE = 1210;
    const int R_FULLY_CLOSE = 1740;


  public:

    int left_curr;
    int right_curr;
    int carpus_curr;

    ClawClass();
    ClawClass(int l_claw_pos, int r_claw_pos, int l_r_pos, int up_down_pos, int torsion_pos);
    void fully_open(int speed);
    void fully_close(int speed);
    void close(int left_dest, int right_dest, int speed);
    void horizontalMovement(int dest, int speed);
    void verticalMovement(int dest, int speed);
    void writeToServo(int servo, int position, int time);

  private:

    void move(char instruction, int left_dest, int right_dest, int speed);


};
#endif
