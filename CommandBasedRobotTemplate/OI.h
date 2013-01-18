#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int SHOOTER_STICK_PORT = 2;
	Joystick *driverStick;
	Joystick *shooterStick;
	JoystickButton *disableShiftButton;
	
public:
	OI();
	Joystick* GetDriverStick();
	Joystick* GetShooterStick();
};

#endif
