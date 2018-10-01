
#include <Servo.h>
#include <Arduino.h>

int pos1=1500;
int pos2=1500;
void setup() {
  Serial.begin(12500);
  initialization();


}

void loop() {
  for(int i=0; i<270; i++) {
    pos1=pos1-1;
    pos2=pos2+1;
    moveBothClaws(pos1, pos2, 10);
  }

   for(int i=0; i<270; i++) {
    pos1=pos1+1;
    pos2=pos2-1;
    moveBothClaws(pos1, pos2, 10);
  }


}

void moveBothClaws(int l_position, int r_position, int time) {
   Serial.println("#29 p"+String(l_position) + " #28 p"+ String(r_position) +" T"+String(time) + " <cr>");
}

void initialization () {
  Serial.println("#00 p1500 #01 p1500 #02 p1500 #04 p1500 #05 p1500 #06 p1500 #08 p1500 #09 p1500 #10 p1500 #13 p1500 #12 p1500 #14 p1500 #28 p1500 #29 p1500 #24 p1500 #25 p1500 #26 p1500 #20 p1500 #21 p1500 #22 p1500 #16 p1500 #17 p1500 #18 p1500 #30 p1500 #31 p1500 T2000");
                  
                 
}
