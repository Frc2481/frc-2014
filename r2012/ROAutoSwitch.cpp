#include "ROAutoSwitch.h"

ROAutoSwitch::ROAutoSwitch (int startChannel){
	S1B1 = new DigitalInput(startChannel + 1);
	S1B2 = new DigitalInput(startChannel + 2);
	S1B3 = new DigitalInput(startChannel + 6);
	S1B4 = new DigitalInput(startChannel + 7);
	
	S2B1 = new DigitalInput(startChannel);
	S2B2 = new DigitalInput(startChannel + 3);
	S2B3 = new DigitalInput(startChannel + 4);
	S2B4 = new DigitalInput(startChannel + 5);
}

int ROAutoSwitch::GetMode() {
	return !S1B1->Get() + (!S1B2->Get() * 2) + (!S1B3->Get() * 4) + (!S1B4->Get() * 8);
}

int ROAutoSwitch::GetDelay() {
	return !S2B1->Get() + (!S2B2->Get() * 2) + (!S2B3->Get() * 4) + (!S2B4->Get() * 8);
}
