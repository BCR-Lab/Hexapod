// @author Ting Ting Huang

#include "FiddlerCrab.h"

/**
 * uploadToSerialPort()
 * pair each servo of the robot with the command angular position
 * and print these code to the serial port
 */
void FiddlerCrab::uploadToSerialPort(){
  writeToClawServos();
  writeToLegServos();
}


/**
 * uploadToSerialPort(int time)
 * call  uploadToSerialPort()
 * Then print the execution time and carriage return to serial port
 */
void FiddlerCrab::uploadToSerialPort(int time){
  uploadToSerialPort();
  
  Serial.print("T");
  Serial.println(time);
  delay(time);
  
}


/**
 * neutralPosition()
 * pair all the servos of the robot with its neutral position
 */
void FiddlerCrab::neutralPosition() {
  setClawToNeutral();
  setLegsToNeutral();
}
