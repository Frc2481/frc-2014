#include "OI.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick2481(DRIVER_STICK_PORT);
	auxStick = new Joystick2481(AUX_STICK_PORT);
}

Joystick* OI::GetDriverStick() {
	return driverStick;
}
Joystick* OI::GetAuxStick() {
	return auxStick;
}
