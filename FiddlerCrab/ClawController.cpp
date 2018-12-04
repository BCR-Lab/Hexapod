// @author Ting Ting Huang

#include "ClawController.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// default constructor                                                                                      //
// it sets the minimum angular posion and maximum angular position that the claw can move with default value//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

ClawController::ClawController(){
  
  l_fully_open=1450;
  r_fully_open=1500;
  l_fully_close=1210;
  r_fully_close=1740;
  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Parametrized Constructor                                                                                                  //
// it takes the value of the arguments to set the minimum angular posion and maximum angular position that the claw can move//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ClawController::ClawController(int l_open, int r_open, int l_close, int r_close ) {
  l_fully_open=l_open;
  r_fully_open=r_open;
  l_fully_close=l_close;
  r_fully_close=r_close;
}


////////////////////////////////////////////////////////////////
// it set the angualr position of all the servos to 90 degree//
////////////////////////////////////////////////////////////////

void ClawController::setClawToNeutral() {
  left_claw_p = 1450;
  right_claw_p = 1500;
  up_down_p = 1500;
  left_right_p = 1500;
  rotation_p = 1600;

}

//////////////////////////////////////////////////////////////////////////////////////////////////                                                                                       //
// The method assigns the varibales that are used to hold the postion of the crab's two fingers //
// with the value that would make the claw to be fully close                                    //  
//////////////////////////////////////////////////////////////////////////////////////////////////

void ClawController::fullyCloseClaw() { 
  
  left_claw_p = l_fully_close;
  right_claw_p = r_fully_close;
  
}

/**
void ClawController::close(int left_dest, int right_dest){
  
  left_claw_p = left_dest;
  right_claw_p = right_dest;

}
*/



//////////////////////////////////////////////////////////////////////////////////////////////////                                                                                       //
// The method assigns the varibales that are used to hold the postion of the crab's two fingers //
// with the value that would make the claw to be fully opened                                   //  
//////////////////////////////////////////////////////////////////////////////////////////////////

void ClawController::fullyOpenClaw() {

  left_claw_p = l_fully_open;
  right_claw_p = r_fully_open;
 
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//The methods: closeClaw(int),openClaw(int), turnClawToLeft(int), turnClawToRight(int),liftClaw(int),         //
//lowerClaw(int),rotateClawToLeft(int), and rotateClawToRight(int) all perform simular function.              //
// They all take in the value of position you want the motor of the command Servo to move to,                 //
// convert it into a angular position                                                                         //
// and assign the value to the varible that are in charge for hold position of that servo ID                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClawController::closeClaw(int pos){
  
  left_claw_p = left_claw_p - pos;
  right_claw_p =  right_claw_p + pos;

}

void ClawController::openClaw(int pos){
  
  left_claw_p = left_claw_p + pos;
  right_claw_p =  right_claw_p - pos;

}

void ClawController::turnClawToLeft(int pos) {
  left_right_p=left_right_p - pos;
}

void ClawController::turnClawToRight(int pos) {
  
  left_right_p=left_right_p + pos;
}

void ClawController::liftClaw(int pos){
  up_down_p = up_down_p - pos;
}

void ClawController::lowerClaw(int pos){
  up_down_p = up_down_p + pos;
}


void ClawController::rotateClawToLeft(int pos) {
  rotation_p = rotation_p + pos;
}

void ClawController::rotateClawToRight(int pos) {
  
  rotation_p = rotation_p - pos;
}

void ClawController::writeToServo(int servo, int position, int time) {	

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   Serial.print(" T");
   Serial.println(time);
   delay(time); 
}

//////////////////////////////////////////////////////////////////
//print the servo ID with its command postion to the serial port//
//////////////////////////////////////////////////////////////////
void ClawController::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   
}


/////////////////////////////////////////////////////////////////////
// pair each servos with its desired postion                       //     
// used writeToServo funtion to print these data to the serial port//
/////////////////////////////////////////////////////////////////////

void ClawController::writeToClawServos(){

  writeToServo(LEFT_CLAW, left_claw_p);
  writeToServo(RIGHT_CLAW, right_claw_p);
  writeToServo(UP_DOWN, up_down_p);
  writeToServo(LEFT_RIGHT, left_right_p);
  writeToServo(ROTATION, rotation_p);
  
}
