#include "Arduino.h"
#include "FiddlerCrab.h"

FiddlerCrab crab;

void setup() {
  Serial.begin(115200);
  crab.setClawToNeutral();
  crab.setLegsToNeutral();
  Serial.println("#30 P1500 # 31 p1500 T200");
  
  crab.uploadToController(2000);
 
  

   
}
void loop(){
  testingServo(2000);
  delay(1000);

  testingServo(1000);
  delay(1000);

  testingServo(500);
  delay(1000);

  
}


void testingServo(int time) {

  int p=200;
  
  crab.lift_left_frontleg(p);
  crab.lift_left_middleleg( p);
  crab.lift_left_rearleg( p);
  
  crab.lift_right_frontleg( p);
  crab.lift_right_middleleg( p);
  crab.lift_right_rearleg( p);
  
  crab.left_frontleg_forward( p);
  crab.left_middleleg_forward(p); 
  crab.left_rearleg_forward( p);
  
  crab.right_frontleg_backward( p);
  crab.right_middleleg_backward(p);
  crab.right_rearleg_backward( p);

  crab.left_frontknee_out( p);
  crab.left_middleknee_out( p);
  crab.left_rearknee_out( p);
  crab.right_frontknee_out( p);
  crab.right_middleknee_out( p);
  crab.right_rearknee_out( p);

  crab.fully_open();
  crab.turnClawToLeft(p);
  crab.liftClaw(p);
  crab.rotateClawToLeft(p);

  Serial.print("#30 P1300 #32 P1100");
  
  crab.uploadToController(time);
  delay(2*time);

  crab.lower_left_frontleg( p);
  crab.lower_left_middleleg( p);
  crab.lower_left_rearleg( p);
  crab.lower_right_frontleg( p);
  crab.lower_right_middleleg( p);
  crab.lower_right_rearleg( p);


  crab.left_frontleg_backward( p);
  crab.left_middleleg_backward(p);
  crab.left_rearleg_backward( p);

  crab.right_frontleg_forward( p);
  crab.right_middleleg_forward(p); 
  crab.right_rearleg_forward( p);
  
  crab.left_frontknee_in( p);
  crab.left_middleknee_in( p);
  crab.left_rearknee_in( p);
  crab.right_frontknee_in( p);
  crab.right_middleknee_in( p);
  crab.right_rearknee_in( p);

  crab.fully_close();
  crab.turnClawToRight(p);
  crab.LowerClaw(p);
  crab.rotateClawToRight(p);

  Serial.print("#30 P1500 #32 P1500");
  crab.uploadToController(time);
  delay(2*time);  

}
