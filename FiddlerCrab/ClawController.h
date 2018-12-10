// @author Ting Ting Huang
 
 
#ifndef CLAWCONTROLLER_h
#define CLAWCONTROLLER_h

#include "Arduino.h"

//////////////////////////////////////////////////////////////////////////////
// class ClawController is used to control the movement of the robot's claws//
//////////////////////////////////////////////////////////////////////////////


class ClawController {
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //LEFT_CLAW: used to hold the servo ID of the robot that controls the left part of the claw        //
    //RIGHT_CLAW: used to hold the servo ID of the robot that controls the right part of the claw      //
    //UP_DOWN: used to hold the servo ID of the robot that controls the claw's up-and-down motion      //
    //LEFT_RIGHT: used to hold the servo ID of the robot that controls the claw's left-and-right motion//
    //TORSION: used to hold the servo ID of the robot that controls the claw's rotational motion       //
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
    const int LEFT_CLAW = 29;  
    const int RIGHT_CLAW = 28;
    const int UP_DOWN = 14;       
    const int LEFT_RIGHT = 12;   
    const int ROTATION = 13;


  public:
  
    ////////////////////////////////////////////////////////////////////////////////////////////
    //lFullyOpenP: set the limitaion of how far the left part of the claw can move outward.   //
    //rFullyOpenP: set the limitaion of how far the right part of the claw can move outward.  //
    //lFullyCloseP: set the limitaion of how close the left part of the claw can move inward. //
    //rFullyCloseP: set the limitaion of how close the right part of the claw can move inward.//
    ////////////////////////////////////////////////////////////////////////////////////////////

    int lFullyOpenP;
    int rFullyOpenP;

    int lFullyCloseP;
    int rFullyCloseP;

     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //left_claw_p: used to hold the current angular position of the servo ID controls the left part of the claw             //
    //right_claw_p: used to hold the current angular position of the servo ID controls right part of the claw               //
    //up_down_p: used to hold the current angular position of the servo ID that controls the claw's up-and-down motion      //
    //left_right_p: used to hold the current angular position of the servo ID that controls the claw's left-and-right motion// 
    //rotation_p: used to hold the current angular position of the servo ID that controls the claw's rotational motion      //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int leftClawP;
    int rightClawP;
    int upDownP;
    int leftRightP;
    int rotationP;
    

    ClawController();

    ClawController(int lOpen, int rOpen, int lClose, int rClose);
    

    /**
     * method setToNeutral
     * sets the servos of the claw and arm to neutral position
     */
    void setClawToNeutral();
    
    void fullyOpenClaw();
    void fullyCloseClaw();
    void closeClaw(int pos);
    void openClaw(int pos);
    void turnClawToLeft(int pos);
    void turnClawToRight(int pos);
    void liftClaw(int pos);
    void lowerClaw(int pos);
    void rotateClawToLeft(int pos);
    void rotateClawToRight(int pos);
    void writeToClawServos(); 
    void writeToClawServos(int time); 
    void writeToServo(int servo, int position, int time);
    void writeToServo(int servo, int position);
    //void close(int left_dest, int right_dest);


};
#endif
