#ifndef RO_AUTOSWITCH_H_
#define RO_AUTOSWITCH_H_
#include "WPILib.h"

class ROAutoSwitch {
private:
	DigitalInput *S1B1;
	DigitalInput *S1B2;
	DigitalInput *S1B3;
	DigitalInput *S1B4;
	DigitalInput *S2B1;
	DigitalInput *S2B2;
	DigitalInput *S2B3;
	DigitalInput *S2B4;
public:
	ROAutoSwitch(int startChannel);
	int GetMode();
	int GetDelay();
};
#endif
