#include "ClawClass.h"

ClawClass::ClawClass() {
  left_curr=1450;
  right_curr=1500;

  Serial.println( "#29 P1450 #28 P1500 #14 P1500 #13 P1550 #12 P1500 T2000");

 
}
ClawClass::ClawClass(int l_claw_pos, int r_claw_pos, int l_r_pos, int up_down_pos, int torsion_pos){
  
  writeToServo(LEFT_CLAW, l_claw_pos,200);
  writeToServo(RIGHT_CLAW, r_claw_pos,200);
  writeToServo(LEFT_RIGHT, l_r_pos,200);
  writeToServo(UP_DOWN, up_down_pos,200);
  writeToServo(LEFT_CLAW, torsion_pos,200);
  
}
void ClawClass::fully_close(int speed) {
  move('c', L_FULLY_CLOSE,R_FULLY_CLOSE,speed);
}

void ClawClass::close(int left_dest, int right_dest, int speed){
  move('c', left_dest, right_dest, speed);

}

void ClawClass::fully_open(int speed) {
  move('o', L_FULLY_OPEN, R_FULLY_OPEN, speed);
 
}

void ClawClass::horizontalMovement(int dest, int speed) {
  writeToServo(LEFT_RIGHT, dest, speed);
}
void ClawClass::verticalMovement(int dest, int speed){
  writeToServo(UP_DOWN, dest, speed); 
}


void ClawClass::move(char instruction,int left_dest, int right_dest, int speed){
  int increment=0;
  
  //'c' means close the claws
  if(instruction == 'c'){
    increment = (left_curr-left_dest)/speed;
    
   
  //'o' means opening the claws
  }else if(instruction =='o'){  
    
    increment=(left_dest-left_curr)/speed;
    speed=-1*(speed);
  }
  
  for(int i=0; i<increment; i++) {
   
    left_curr = left_curr- speed;
    right_curr = right_curr + speed;


    writeToServo(LEFT_CLAW, left_curr, 10);
    writeToServo(RIGHT_CLAW, right_curr, 10);
  }
  
}
void ClawClass::writeToServo(int servo, int position, int time) {	

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   Serial.print(" T");
   Serial.println(time);
   delay(time); 
}
