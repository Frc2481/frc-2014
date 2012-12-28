
#include "DebounceDigitalInput.h"

DebounceDigitalInput::DebounceDigitalInput(UINT8 channel) : DigitalInput(channel){
	for (int i = 0; i < DEBOUNCE_CYCLES; i++ ) {
		values[i] = false;
	}
	currentState = false;
}

DebounceDigitalInput::~DebounceDigitalInput() {
	
}

bool DebounceDigitalInput::GetD() {
	int debounceValues = 0;
	// shift every value over in the array
	for (int i = 0; i < DEBOUNCE_CYCLES - 1; i++) {
		values[i + 1] = values[i];
		debounceValues += values[i];
	}
	// set the current sensor state to the first item in your array
	values[0] = Get();
	debounceValues += values[0];
	if (debounceValues == DEBOUNCE_CYCLES) {
		currentState = true;
	}
	else if (debounceValues == 0){
		currentState = false;
	}
	return currentState;
}
