#ifndef CLAWCONTROLLER_h
#define CLAWCONTROLLER_h

#include "Arduino.h"

class ClawController {
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

    int left_claw_p;
    int right_claw_p;
    int up_down_p;
    int left_right_p;
    int torsion_p;
    

    ClawController();

    /**
     * Parametrized Constructor
     * four parameters: the restraint opening position for left dactyl and right dactyl 
     * and restraint closing position for left dactyl and right dactyl
     */
    ClawController(int l_open, int r_open, int l_close, int r_close);
    

    /**
     * method setToNeutral
     * sets the servos of the claw and arm to neutral position
     */
    void setClawToNeutral();
    
    void fully_open();
    void fully_close();
    void close(int left_dest, int right_dest);
    void close(int pos);
    void turnClawToLeft(int pos);
    void turnClawToRight(int pos);
    void liftClaw(int pos);
    void LowerClaw(int pos);
    void rotateClawToLeft(int pos);
    void rotateClawToRight(int pos);
    void writeToClawServos(); 
    void writeToServo(int servo, int position, int time);
    void writeToServo(int servo, int position);


};
#endif
