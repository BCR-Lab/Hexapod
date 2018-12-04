// @author Ting Ting Huang

#include "ClawController.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// default constructor                                                                                      //
// it sets the minimum angular posion and maximum angular position that the claw can move with default value//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

ClawController::ClawController(){
  
  lFullyOpenP=1450;
  rFullyOpenP=1500;
  lFullyCloseP=1210;
  rFullyCloseP=1740;
  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Parametrized Constructor                                                                                                  //
// it takes the value of the arguments to set the minimum angular posion and maximum angular position that the claw can move//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ClawController::ClawController(int lOpen, int rOpen, int lClose, int rClose ) {
  lFullyOpenP=lOpen;
  rFullyOpenP=rOpen;
  lFullyCloseP=lClose;
  rFullyCloseP=rClose;
}


////////////////////////////////////////////////////////////////
// it set the angualr position of all the servos to 90 degree//
////////////////////////////////////////////////////////////////

void ClawController::setClawToNeutral() {
  leftClawP = 1450;
  rightClawP = 1500;
  upDownP = 1500;
  leftRightP = 1500;
  rotationP = 1600;

}

//////////////////////////////////////////////////////////////////////////////////////////////////                                                                                       //
// The method assigns the varibales that are used to hold the postion of the crab's two fingers //
// with the value that would make the claw to be fully close                                    //  
//////////////////////////////////////////////////////////////////////////////////////////////////

void ClawController::fullyCloseClaw() { 
  
  leftClawP = lFullyCloseP;
  rightClawP = rFullyCloseP;
  
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

  leftClawP = lFullyOpenP;
  rightClawP = rFullyOpenP;
 
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//The methods: closeClaw(int),openClaw(int), turnClawToLeft(int), turnClawToRight(int),liftClaw(int),         //
//lowerClaw(int),rotateClawToLeft(int), and rotateClawToRight(int) all perform simular function.              //
// They all take in the value of position you want the motor of the command Servo to move to,                 //
// convert it into a angular position                                                                         //
// and assign the value to the varible that are in charge for hold position of that servo ID                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClawController::closeClaw(int pos){
  
  leftClawP = leftClawP - pos;
  rightClawP =  rightClawP + pos;

}

void ClawController::openClaw(int pos){
  
  leftClawP = leftClawP + pos;
  rightClawP =  rightClawP - pos;

}

void ClawController::turnClawToLeft(int pos) {
  leftRightP = leftRightP - pos;
}

void ClawController::turnClawToRight(int pos) {
  
  leftRightP = leftRightP + pos;
}

void ClawController::liftClaw(int pos){
  upDownP = upDownP - pos;
}

void ClawController::lowerClaw(int pos){
  upDownP = upDownP + pos;
}


void ClawController::rotateClawToLeft(int pos) {
  rotationP = rotationP + pos;
}

void ClawController::rotateClawToRight(int pos) {
  
  rotationP = rotationP - pos;
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

  writeToServo(LEFT_CLAW, leftClawP);
  writeToServo(RIGHT_CLAW, rightClawP);
  writeToServo(UP_DOWN, upDownP);
  writeToServo(LEFT_RIGHT, leftRightP);
  writeToServo(ROTATION, rotationP);
  
}
