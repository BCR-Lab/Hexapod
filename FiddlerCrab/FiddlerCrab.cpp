#include "FiddlerCrab.h"

void FiddlerCrab::uploadToController(){
  writeToClawServos();
  writeToLegServos();
}

void FiddlerCrab::uploadToController(int time){
  writeToClawServos();
  writeToLegServos();

  Serial.print("T");
  Serial.println(time);
  
}
