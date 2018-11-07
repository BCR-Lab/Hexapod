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


void ClawController::setToNeutral() {

  writeToServo(LEFT_CLAW, 1450);
  writeToServo(RIGHT_CLAW, 1500);
  writeToServo(UP_DOWN,1500);
  writeToServo(LEFT_RIGHT,1500);
  writeToServo(TORSION,1500);
 // Serial.println("T2000");
}

void ClawController::fully_close() {
  
 // moveClaw( l_fully_close,r_fully_close, time);

  writeToServo(LEFT_CLAW, l_fully_close);
  writeToServo(RIGHT_CLAW, r_fully_close);

  
}

void ClawController::close(int left_dest, int right_dest){
  
 // moveClaw(left_dest, right_dest, time);
  writeToServo(LEFT_CLAW, left_dest);
  writeToServo(RIGHT_CLAW, right_dest);

}

void ClawController::fully_open() {
 // moveClaw( l_fully_open, r_fully_open, time);
  writeToServo(LEFT_CLAW, l_fully_open);
  writeToServo(RIGHT_CLAW, r_fully_open);
 
}

void ClawController::horizontalMovement(int dest) {
  writeToServo(LEFT_RIGHT, dest);
}
void ClawController::verticalMovement(int dest){
  writeToServo(UP_DOWN, dest); 
}

/*
void ClawClass::moveClaw(int left_dest, int right_dest, int time){
  writeToServo(LEFT_CLAW, left_dest);
  writeToServo(RIGHT_CLAW, right_dest);

  
  Serial.print(" T");
  Serial.println(time);
  delay(2*time);
  
  
}*/


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
