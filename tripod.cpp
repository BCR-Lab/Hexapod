#include "tripod.h"

/*
 * tripod()
 * 
 * This is the default constructor.
 * Since a tripod cannot exist without 3 legs,
 * this constructor is only there to allow one to declare the tripod.
 */
tripod::tripod(){}

/*
 * tripod(servoIO HH1, servoIO HH2, servoIO HH3,servoIO VH1, servoIO VH2, servoIO VH3, servoIO KN1, servoIO KN2, servoIO KN3)
 * 
 * This constructor takes the Horizontal Hip the Vertical Hip and the Knee of the 
 * back leg, front leg and middle leg of the tripod respectively to construct a tripod
 */
 
tripod::tripod(servoIO HH1, servoIO HH2, servoIO HH3,servoIO VH1, servoIO VH2, servoIO VH3, servoIO KN1, servoIO KN2, servoIO KN3){
  horizontalHip[0] = HH1;
  horizontalHip[1] = HH2;
  horizontalHip[2] = HH3;
  verticalHip[0] = VH1;
  verticalHip[1] = VH2;
  verticalHip[2] = VH3;
  knee[0] = KN1;
  knee[1] = KN2;
  knee[2] = KN3;
}

/*
 * void lift()
 * 
 * This function lifts the legs of the tripod
 */
void tripod::lift(){
  /*
   for (int i = 0; i < 3; i++){
    verticalHip[i].setServoPosition(DEFAULT_POSITION);
  }
  */
  verticalHip[0].setServoPosition(DEFAULT_POSITION + (verticalHip[0].notReverse()*100));
  verticalHip[1].setServoPosition(DEFAULT_POSITION - (verticalHip[1].notReverse()*100));
  verticalHip[2].setServoPosition(DEFAULT_POSITION);
  for (int i = 0; i < 3; i++){
    verticalHip[i].writeToServo();
    knee[i].writeToServo();
  }
}

/*
 * void stand()
 * 
 * This keeps the Robot standing.
 */
void tripod::stand(){
  for (int i = 0; i < 3; i++){
    horizontalHip[i].writeToServo();
    verticalHip[i].writeToServo();
    knee[i].writeToServo();
  }
  Serial.println("T1000");
  delay(2000);
}
/*
 * void forward()
 * 
 * This function moves the suspended legs of the tripod forward
 */
void tripod::forward(){
  horizontalHip[0].setServoPosition(DEFAULT_POSITION - (horizontalHip[0].notReverse()*250));
  horizontalHip[1].setServoPosition(DEFAULT_POSITION - (horizontalHip[1].notReverse()*250));
  horizontalHip[2].setServoPosition(DEFAULT_POSITION - (horizontalHip[2].notReverse()*250));
  
  for (int i = 0; i < 3; i++){
    horizontalHip[i].writeToServo();
  }
}

/*
 * void down()
 * 
 * This function brings the legs down
 */
void tripod::down(){
  /*
  for (int i = 0; i < 3; i++){
    verticalHip[i].setServoPosition(DEFAULT_POSITION + (verticalHip[i].notReverse()*500));
  }
  */
  verticalHip[0].setServoPosition(DEFAULT_POSITION + (verticalHip[0].notReverse()*600));
  verticalHip[1].setServoPosition(DEFAULT_POSITION + (verticalHip[1].notReverse()*400));
  verticalHip[2].setServoPosition(DEFAULT_POSITION + (verticalHip[2].notReverse()*500));
  
  for (int i = 0; i < 3; i++){
    horizontalHip[i].writeToServo();
    verticalHip[i].writeToServo();
    knee[i].writeToServo();
  }
}

/*
 * void pushFoward(float angle)
 * 
 * This function pushes forward for a forward walk
 */
void tripod::pushFoward(float angle){
  /*
  for(int i = 0; i < 3; i++){
    //horizontalHip[i].setServoPosition(DEFAULT_POSITION + (horizontalHip[i].notReverse()*250));
    verticalHip[i].setServoPosition(DEFAULT_POSITION + (verticalHip[i].notReverse()*500));
    knee[i].setServoPosition(DEFAULT_POSITION);
  }
  */
  if(angle < 0){
    horizontalHip[0].setServoPosition(DEFAULT_POSITION + (horizontalHip[0].notReverse()*250));
    horizontalHip[1].setServoPosition(DEFAULT_POSITION + (horizontalHip[1].notReverse()*250));
    horizontalHip[2].setServoPosition(DEFAULT_POSITION + (horizontalHip[2].notReverse()*(250 - (500 * angle/90))));
  }
  else{
    horizontalHip[0].setServoPosition(DEFAULT_POSITION + (horizontalHip[0].notReverse()* (250 - (500 * angle/90))));
    horizontalHip[1].setServoPosition(DEFAULT_POSITION + (horizontalHip[1].notReverse()* (250 - (500 * angle/90))));
    horizontalHip[2].setServoPosition(DEFAULT_POSITION + (horizontalHip[2].notReverse()*250));
  }
  /*
  verticalHip[0].setServoPosition(DEFAULT_POSITION + (verticalHip[0].notReverse()*500));
  verticalHip[1].setServoPosition(DEFAULT_POSITION + (verticalHip[1].notReverse()*750));
  verticalHip[2].setServoPosition(DEFAULT_POSITION + (verticalHip[2].notReverse()*500));
  knee[0].setServoPosition(DEFAULT_POSITION + (knee[0].notReverse()*500));
  knee[1].setServoPosition(DEFAULT_POSITION - (knee[1].notReverse()*250));
  knee[2].setServoPosition(DEFAULT_POSITION);
  */
  
  for (int i = 0; i < 3; i++){
    horizontalHip[i].writeToServo();
    knee[i].writeToServo();
    verticalHip[i].writeToServo();
  }
  Serial.println("T1000");
  delay(2000);
}
