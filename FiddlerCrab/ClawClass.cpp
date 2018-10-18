#include "ClawClass.h"


ClawClass::ClawClass(){
  
  l_fully_open=1450;
  r_fully_open=1500;
  l_fully_close=1210;
  r_fully_close=1740;
  
}
ClawClass::ClawClass(int l_open, int r_open, int l_close, int r_close ) {
  l_fully_open=l_open;
  r_fully_open=r_open;
  l_fully_close=l_close;
  r_fully_close=r_close;
}


void ClawClass::setToNeutral() {
  Serial.println("#29 P1450 #28 P1500 #14 P1500 #13 P1550 #12 P1500 T2000");
}

void ClawClass::fully_close(int time) {
  //move('c', L_FULLY_CLOSE,R_FULLY_CLOSE,speed);

  moveClaw( l_fully_close,r_fully_close, time);
  
}

void ClawClass::close(int left_dest, int right_dest, int time){
  //move('c', left_dest, right_dest, time);
  moveClaw(left_dest, right_dest, time);

}

void ClawClass::fully_open(int time) {
 // move('o', L_FULLY_OPEN, R_FULLY_OPEN, speed);
  moveClaw( l_fully_open, r_fully_open, time);
 
}

void ClawClass::horizontalMovement(int dest, int speed) {
  writeToServo(LEFT_RIGHT, dest, speed);
}
void ClawClass::verticalMovement(int dest, int speed){
  writeToServo(UP_DOWN, dest, speed); 
}


void ClawClass::moveClaw(int left_dest, int right_dest, int time){
  writeToServo(LEFT_CLAW, left_dest);
  writeToServo(RIGHT_CLAW, right_dest);
  Serial.print(" T");
  Serial.println(time);
  delay(2*time);
   
  
}


/**
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


    writeToServo(LEFT_CLAW, left_curr, abs(speed));
    writeToServo(RIGHT_CLAW, right_curr, abs(speed));

    
    writeToServo(LEFT_CLAW, left_curr);
    writeToServo(RIGHT_CLAW, right_curr);
    Serial.print(" T");
    Serial.println(abs(speed)); 
     
     
  }
  
}

*/
void ClawClass::writeToServo(int servo, int position, int time) {	

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   Serial.print(" T");
   Serial.println(time);
   delay(time); 
}

void ClawClass::writeToServo(int servo, int position) {  

   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   
}
