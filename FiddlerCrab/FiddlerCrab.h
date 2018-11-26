// @author Ting Ting Huang

#ifndef FIDDLERCRAB_H
#define FIDDLERCRAB_H

#include "ClawController.h"
#include "LegsController.h"

class FiddlerCrab: public ClawController, public LegsController {
	public:
    
    void uploadToSerialPort();
    void uploadToSerialPort(int time);
    void neutralPosition();
};
#endif
