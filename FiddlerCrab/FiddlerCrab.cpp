// @author Ting Ting Huang

#include "FiddlerCrab.h"

void FiddlerCrab::uploadToSerialPort(){
  writeToClawServos();
  writeToLegServos();
}

void FiddlerCrab::uploadToSerialPort(int time){
  uploadToSerialPort();
  
  Serial.print("T");
  Serial.println(time);
  
}

void FiddlerCrab::neutralPosition() {
  setClawToNeutral();
  setLegsToNeutral();
}
