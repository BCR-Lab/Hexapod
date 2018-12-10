// @author Ting Ting Huang

#include "Arduino.h"
#include "FiddlerCrab.h"

FiddlerCrab crab;

void setup() {
  Serial.begin(115200);
  
  crab.neutralPosition();
  Serial.println("#30 P1500 #31 p1500 T200");
  crab.uploadToSerialPort(2000);
  delay(2000);
   
}

void loop() {
  /*
  for(int i =0; i<3; i++){
    testingServo(250);
  }
  delay(2000);
  
  for(int i =0; i<3; i++){
    testingServo(200);
  }
  delay(2000);

  for(int i =0; i<3; i++){
    testingServo(150);
  }
  delay(2000);

  for(int i =0; i<3; i++) {
    testingServo(100);
  }
  delay(2000);

  for(int i =0; i<3; i++) {
    testingServo(80);
  }
  delay(2000);

  for(int i =0; i<3; i++) {
    testingServo(50);
  }
  delay(2000);
*/
} 

/*

void testingServo(int time) {

  int p=200;
  
  crab.lift_left_frontleg(p);
  crab.lift_left_middleleg(p);
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

  crab.fullyOpenClaw();
  crab.turnClawToLeft(p);
  crab.liftClaw(p);
  crab.rotateClawToLeft(p);

  Serial.print("#30 P1300 #31 P1700");
  
  crab.uploadToSerialPort(time);
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

  crab.fullyCloseClaw();
  crab.turnClawToRight(p);
  crab.lowerClaw(p);
  crab.rotateClawToRight(p);

  Serial.print("#30 P1500 #31 P1500");
  crab.uploadToSerialPort(time);
  delay(2*time);           

}
*/
////////////////////////////////////////////////////////////


void presentation(){
  crab.neutralPosition();
  Serial.println("#30 P1500 #31 p1500 T200");
  crab.uploadToSerialPort(2000);
  delay(2000);
  int pos =500;

  /**
   * claw demonstration 
   */
  //turn claw left
  
  crab.turnClawToLeft(pos);
  crab.uploadToSerialPort(500);
  delay(500);

  //return back to center
  crab.turnClawToRight(pos);
  crab.uploadToSerialPort(500);
  delay(500);

  //turn to claw right
  crab.turnClawToRight(pos);
  crab.uploadToSerialPort(500);
  delay(500);

  //back to center
  crab.turnClawToLeft(pos);
  crab.uploadToSerialPort(500);
  delay(500);

  crab.liftClaw( pos);
  crab.uploadToSerialPort(300);
  delay(500);

  //showing claw open and close
  for(int i=0; i<5; i++) {
    crab.fullyOpenClaw();
    crab.uploadToSerialPort(300);
    delay(400);
  
    crab.fullyCloseClaw();
    crab.uploadToSerialPort(300);
    delay(400);
  }

  delay(2000);

  /**
   * gripping demonstration
   */
  //claw back to center
  crab.lowerClaw( pos);
  crab.uploadToSerialPort(300);
  delay(500);

  crab.fullyOpenClaw();
  crab.uploadToSerialPort(300);
  delay(500);
  
  crab.sit();
  crab.uploadToSerialPort(300);
  delay(1000);

  crab.lowerClaw( pos);
  crab.uploadToSerialPort(300);
  delay(500);

  crab.closeClaw(120);
  crab.uploadToSerialPort(300);
  delay(500);

  crab.liftClaw( pos);
  crab.uploadToSerialPort(300);
  delay(500);

  crab.setLegsToNeutral(); 
  crab.uploadToSerialPort(200);
  delay(1000);

  crab.stand(); 
  crab.uploadToSerialPort(200);
  delay(2000);

  crab.liftClaw(pos);
  crab.uploadToSerialPort(200);
  delay(2000);

  crab.lowerClaw( pos);
  crab.uploadToSerialPort(300);
  delay(500);
  
  crab.setLegsToNeutral(); 
  crab.uploadToSerialPort(200);
  delay(1000);

  crab.sit();
  crab.uploadToSerialPort(300);
  delay(1000);

  crab.fullyOpenClaw();
  crab.uploadToSerialPort(200);
  delay(1000);

  
}
