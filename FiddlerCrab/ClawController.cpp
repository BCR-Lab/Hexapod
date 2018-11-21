#include "ClawController.h"


ClawController::ClawController(){
  
  l_fully_open=1450;
  r_fully_open=1500;
  l_fully_close=1210;
  r_fully_close=1740;
  
}
ClawController::ClawController(int l_open, int r_open, int l_close, int r_close ) {
  l_fully_open=l_open;
  r_fully_open=r_open;
  l_fully_close=l_close;
  r_fully_close=r_close;
}


void ClawController::setClawToNeutral() {
  left_claw_p = 1450;
  right_claw_p = 1500;
  up_down_p = 1500;
  left_right_p = 1500;
  torsion_p = 1600;

}

void ClawController::fully_close() { 
  
  left_claw_p = l_fully_close;
  right_claw_p = r_fully_close;
  
}

void ClawController::close(int left_dest, int right_dest){
  
  left_claw_p = left_dest;
  right_claw_p = right_dest;

}

void ClawController::close(int pos){
  
  left_claw_p = left_claw_p - pos;
  right_claw_p =  right_claw_p + pos;

}

void ClawController::fully_open() {

  left_claw_p = l_fully_open;
  right_claw_p = r_fully_open;
 
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
  torsion_p = torsion_p + pos;
}

void ClawController::rotateClawToRight(int pos) {
  
  torsion_p = torsion_p - pos;
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

void ClawController::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   
}

void ClawController::writeToClawServos(){

  writeToServo(LEFT_CLAW, left_claw_p);
  writeToServo(RIGHT_CLAW, right_claw_p);
  writeToServo(UP_DOWN, up_down_p);
  writeToServo(LEFT_RIGHT, left_right_p);
  writeToServo(TORSION, torsion_p);
  
}
