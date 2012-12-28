#ifndef DEBOUNCE_DIGITAL_INPUT_H_
#define DEBOUNCE_DIGITAL_INPUT_H_

#include "WPILib.h"

using namespace std;

#define DEBOUNCE_CYCLES		10


class DebounceDigitalInput : public DigitalInput{
private:
	bool values[DEBOUNCE_CYCLES];
	bool currentState;
	
public:
	DebounceDigitalInput(UINT8 channel);
	virtual ~DebounceDigitalInput();
	bool GetD();
};
#endif
