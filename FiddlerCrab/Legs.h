#ifndef LEGS_H
#define LEGS_H

#include "Arduino.h"

class Legs{
	
public:
	Legs();
  void stand();
  void writeToServo(int servo, int position);

	
};
#endif
