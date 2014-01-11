#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Components/Joystick2481.h"
#include "XboxController.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int AUX_STICK_PORT = 2;
	Joystick2481 *driverStick;
	Joystick2481 *auxStick;
public:
	OI();
	Joystick* GetDriverStick();
	Joystick* GetAuxStick();
};

#endif
