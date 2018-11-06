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
    

    /**
     * default constructor for class ClawClass
     */
    ClawClass();

    /**
     * Parametrized Constructor
     * four parameters: the restraint opening position for left dactyl and right dactyl 
     * and restraint closing position for left dactyl and right dactyl
     */
    ClawClass(int l_open, int r_open, int l_close, int r_close);

    /**
     * method setToNeutral
     * sets the servos of the claw and arm to neutral position
     */
    void setToNeutral();

    /**
     * method fully_open will open the claw to the "fully open position"
     */
    void fully_open();

    /**
     * method fully_close will close the claw to the "fully close position"
     */
    void fully_close();
    

    /**
     * method close will close the claw to the the positions you pass in by argument
     * it takes two argument: the position for the left and right dactyl
     */
    void close(int left_dest, int right_dest);
    

    /**
     * Method horizontalMovement controls the claw side to side movement
     * It takes one argument: the destination position
     * P1500 is the neutral position; L<->R  P2000 <-> P1000
     */
    void horizontalMovement(int dest);

    /**
     * Method horizontalMovement controls the claw up and down movement
     * It takes one argument: the destination position
     * P1500 is the neutral position; up<--- 1500++++>down
     */
    void verticalMovement(int dest);
    
    
   

  private:
     void writeToServo(int servo, int position, int time);
     void writeToServo(int servo, int position);


};
#endif
