#include "ClawClass.h"

void ClawClass::fully_close(int speed) {
 move('c', l_fullyClose,r_fullyClose,speed);
}

void ClawClass::close(int left_dest, int right_dest, int speed){
  move('c', left_dest, right_dest, speed);

}

void ClawClass::fully_open(int speed) {
  move('o', l_fullyOpen, r_fullyOpen, speed);
 
}

void ClawClass::move(char instruction,int left_dest, int right_dest, int speed){
  int increment=0;
  //int left_pos, right_pos;
  

  //'c' means close the claws
  if(instruction == 'c'){
    increment = (left_curr-left_dest)/speed;
    //left_pos = left_curr;
    //right_pos = right_curr;
    
  }else if(instruction =='o'){   //'o' means opening the claws
    
    increment=(left_dest-left_curr)/speed;
  //  left_pos = left_curr;
   // right_pos = right_curr;
    speed=-1*(speed);
  }
  
  for(int i=0; i<increment; i++) {
   // left_pos = left_pos - speed;
   // right_pos = right_pos + speed;
    left_curr = left_curr- speed;
    right_curr = right_curr + speed;


    writeToServo(left_Claw, left_curr, 10);
    writeToServo(right_Claw, right_curr, 10);
  }
  
  //left_curr=left_pos;
  //right_curr=right_pos;
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
