// @author Ting Ting Huang

#include "ClawController.h"

/**
 * ClawController()
 * default constructor                                                                                      
 * it sets the minimum angular posion and maximum angular position that the claw can move                   
 */

ClawController::ClawController(){
  
  lFullyOpenP=1450;
  rFullyOpenP=1500;
  lFullyCloseP=1210;
  rFullyCloseP=1740;
  
}

/**
 * ClawController(int lOpen, int rOpen, int lClose, int rClose )
 * Parametrized Constructor                                                                                                  
 * it takes the value of the arguments to set the minimum and maximum distance that the claw can open and close
 */

ClawController::ClawController(int lOpen, int rOpen, int lClose, int rClose ) {
  lFullyOpenP=lOpen;
  rFullyOpenP=rOpen;
  lFullyCloseP=lClose;
  rFullyCloseP=rClose;
}


/**
 * setClawToNeutral() 
 * it set the angular position of all the servos to 0 degree (stay on center of the servo)
 */

void ClawController::setClawToNeutral() {
  leftClawP = 1450;
  rightClawP = 1500;
  upDownP = 1500;
  leftRightP = 1500;
  rotationP = 1600;

}

/**                                                                                      
 * fullyCloseClaw()                                                                                      
 * The method assigns the varibales that are used to hold the postion of the crab's two fingers 
 * with the value that would make the claw to be fully close                                    
 */

void ClawController::fullyCloseClaw() { 
  
  leftClawP = lFullyCloseP;
  rightClawP = rFullyCloseP;
  
}



/**                                                                                      
 * fullyOpenClaw()                                                                                      
 * The method assigns the varibales that are used to hold the postion of the crab's two fingers 
 * with the value that would make the claw to be fully opened                                   
 */

void ClawController::fullyOpenClaw() {

  leftClawP = lFullyOpenP;
  rightClawP = rFullyOpenP;
 
}



/**
 * The methods: closeClaw(int),openClaw(int), turnClawToLeft(int), turnClawToRight(int),liftClaw(int),        
 * lowerClaw(int),rotateClawToLeft(int), and rotateClawToRight(int) all perform similar function.             
 * 
 * They all take in one argument (how many angular position you want the motor to move).                      
 * Then use the value to calculate the destination position and assign it to the variable that                
 * is in charge for hold position of that spefic command servo ID                                                      
 */

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
/**
 * writeToServo(int servo, int position, int time)
 * It's used for moving one servo at a time
 */
 /**
void ClawController::writeToServo(int servo, int position, int time) {	

   writeToServo(servo, position);
   Serial.print(" T");
   Serial.println(time);
   delay(time); 
}
*/
/**
 * writeToServo(int servo, int position)
 * print the servo ID with its command postion to the serial port
 */
void ClawController::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   
}


/**
 * writeToClawServos()
 * pair each servos with its desired postion                           
 * used writeToServo funtion to print these data to the serial port
 */

void ClawController::writeToClawServos(){

  writeToServo(LEFT_CLAW, leftClawP);
  writeToServo(RIGHT_CLAW, rightClawP);
  writeToServo(UP_DOWN, upDownP);
  writeToServo(LEFT_RIGHT, leftRightP);
  writeToServo(ROTATION, rotationP);
  
} 


/**
 * writeToClawServos(int time)
 * call writeToClawServos() 
 * print execution time and carriage return to the serial port
 */
void ClawController::writeToClawServos(int time){
  writeToClawServos();
  Serial.print("T");
  Serial.println(time);
  delay(time);
}
