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
     * it takes one argument: time needed to finish the moving process
     * the larger the value of time, the slower the servo moves 
     */
    void fully_open(int time);

    /**
     * method fully_close will close the claw to the "fully close position"
     * it takes one argument: time needed to finish the moving process
     * the larger the value of time, the slower the servo moves 
     */
    void fully_close(int time);

    /**
     * method close will close the claw to the the positions you pass in by argument
     * it takes three argument: the position for the left and right dactyl, and the time limit
     */
    void close(int left_dest, int right_dest, int time);

    /**
     * Method horizontalMovement controls the claw side to side movement
     * It takes two argument: the destination position, and the time to process moving
     * P1500 is the neutral position; L<->R  P2000 <-> P1000
     */
    void horizontalMovement(int dest, int time);

    /**
     * Method horizontalMovement controls the claw up and down movement
     * It takes two argument: the destination position, and the time to process moving
     * P1500 is the neutral position; up<--- 1500++++>down
     */
    void verticalMovement(int dest, int time);
    
    void writeToServo(int servo, int position, int time);
    void writeToServo(int servo, int position);
   

  private:
     void moveClaw(int left_dest, int right_dest, int time);
     void move(char instruction, int left_dest, int right_dest, int speed);


};
#endif
