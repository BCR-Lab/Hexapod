/*
 *Author: Eric Li 
 *This program is a program made to be able to walk forward and diagonally.
 *It utilizes the Botboarduino to send commands to the SSC-32 Control board.
 *These functions are built specifically for Constantz so keep in mind:
 *- Constantz has the servos flipped around hence pin 0 is the Top Left Horizontal Hip 
 *  on the SSC-32 manual but on Constantz it is the Bottom Right Horizontal Hip. 
 *- The right side and the left side of Constantz move opposite given the same pulse width hence
 *  the program is written as the difference of instead and the left side is the side I considered correct.
 */
#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

#include "servoIO.h" //class created by Joyce Chiu
#include "tripod.h"

servoIO ApodServos[25];
bool firstMovement = true;
int servoPinNumbers[25] = {0,1,2,4,5,6,8,9,10,16,17,18,20,21,22,24,25,26,28,29,30,31,12,13,14};
float slope[25] = {0.89,0.95,0.98,0.86,0.94,0.9,0.91,0.9,0.97,0.9,0.92,0.88,0.92,0.87,0.95,0.92,0.92,0.93,1,1,1,1,1,1,1};
float yIntecept[25] = {9.65,1.49,0.89,0.51,-4.42,-11.85,2.47,1.72,-0.49,-1.3,-0.85,-13.74,-3.33,5.95,-3.63,-4.08,-3.62,-5.68,0,0,0,0,0,0,0};
//servoIO testServo(20); //LMH randomly chosen to test if BotBoarduino is transmitting commands to SSC-32 and that SSC-32 is receiving it
tripod A,B;

/*
 * void walkForward()
 * 
 * This function performs a walk forward.
 */
void walkForward(float angle){
  A.lift();
  A.forward();
  if(firstMovement){
    firstMovement = false;
    B.stand();
  }
  else{
    B.pushFoward(angle); 
  }
  A.down();
  B.stand();
  B.lift();
  B.forward();
  A.pushFoward(-angle);
  B.down();
  A.stand();
  
}
/*
 * void setup()
 * 
 * This function is called once at the start of the program.
 */
void setup() {
  Serial.begin(BAUDRATE); // begin communication using 115.2K baud rate
  while(!Serial){} // wait while connecting
  //Assign a pin number to each servoIO class
  for(int i = 0; i < 25; i++) {
    ApodServos[i] = servoIO(servoPinNumbers[i],slope[i],yIntecept[i]);
  }
  /*
   * Only for testing default position
   */
   /*
  for(int i = 0; i < 25; i++){
    ApodServos[i].setServoPosition(DEFAULT_POSITION);
  }
  */
  //Set Initial Position for Leg Servos
  for(int i = 0; i < 18; i+=9){
    for (int j = 0; j < 9; j++){
        if (i == 0){
          ApodServos[i+j].setReverse(true);
        }
        else{
          ApodServos[i+j].setReverse(false);
        }
    }
    for(int j = 0; j < 3; j++){
      ApodServos[i+(3*j)].setServoPosition(DEFAULT_POSITION);
      ApodServos[i+1+(3*j)].setServoPosition(DEFAULT_POSITION + (ApodServos[i+1+(3*j)].notReverse()*500));
      ApodServos[i+2+(3*j)].setServoPosition(DEFAULT_POSITION);
    }
    /*
    //Horizontal Hips
    ApodServos[i].setServoPosition(DEFAULT_POSITION);
    ApodServos[i+3].setServoPosition(DEFAULT_POSITION);
    ApodServos[i+6].setServoPosition(DEFAULT_POSITION + (ApodServos[i+6].notReverse()*250));

    //Vertical Hips
    ApodServos[i+1].setServoPosition(DEFAULT_POSITION + (ApodServos[i+1].notReverse()*600));
    ApodServos[i+4].setServoPosition(DEFAULT_POSITION + (ApodServos[i+4].notReverse()*500));
    ApodServos[i+7].setServoPosition(DEFAULT_POSITION + (ApodServos[i+7].notReverse()*400));

    //Knees
     ApodServos[i+2].setServoPosition(DEFAULT_POSITION);
     ApodServos[i+5].setServoPosition(DEFAULT_POSITION);
     ApodServos[i+8].setServoPosition(DEFAULT_POSITION);
    */
  }
  //The two tripods declared here.
  A = tripod(ApodServos[0] ,ApodServos[6] ,ApodServos[12] ,ApodServos[1] ,ApodServos[7] ,
    ApodServos[13] ,ApodServos[2] ,ApodServos[8] ,ApodServos[14] );
  B = tripod(ApodServos[9] ,ApodServos[15] ,ApodServos[3] ,ApodServos[10] ,ApodServos[16] ,
    ApodServos[4] ,ApodServos[11] ,ApodServos[17] ,ApodServos[5] );
  
  //Set Initial Position for Mandibles and Abdomen.
  for(int i = 18; i < 25; i++){
    ApodServos[i].setServoPosition(DEFAULT_POSITION);
  }
  ApodServos[20].setServoPosition(DEFAULT_POSITION - 100);
  ApodServos[21].setServoPosition(DEFAULT_POSITION + 250);
  ApodServos[24].setServoPosition(DEFAULT_POSITION + 250);
  
  //Send the positions for every servo to the SSC-32 via BotBoarduino
  for(int i = 0; i < 25; i++){
    ApodServos[i].writeToServo();
  }
  Serial.println("T1000");
  delay(1000);
}

/*
 * void loop()
 * 
 * The endless loop that is called by the BotBaorduino
 */
void loop() {
  Serial.println(digitalRead(4));
  delay(1000);
  Serial.println(analogRead(4));
  delay(1000);
  /* For testing digital and analog input
  for (int i = 0; i < 4; i++){
    Serial.println(digitalRead(2+i));
    delay(1000);
    Serial.println(analogRead(2+i));
    delay(1000);
    Serial.println(digitalRead(10+i));
    delay(1000);
    Serial.println(analogRead(10+i));
    delay(1000);
  }
  */
  walkForward(0);
  /*
  if(firstMovement){
    float angle = 45;
    walkForward(angle); 
  }
  
  else{
    walkForward(0);
  }
  */
}
