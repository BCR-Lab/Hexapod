#ifndef FIDDLERCRAB_H
#define FIDDLERCRAB_H

#include "ClawController.h"
#include "LegsController.h"

class FiddlerCrab: public ClawController, public LegsController {
	public:
    
    void uploadToController();
    void uploadToController(int time);
    void neutralPosition();
};
#endif
