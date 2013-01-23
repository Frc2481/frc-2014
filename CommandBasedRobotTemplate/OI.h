#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Components/Joystick2481.h"
#include "XboxController.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int SHOOTER_STICK_PORT = 2;
	XboxController *driverStick;
	XboxController *shooterStick;
	JoystickButton *disableShiftButton;
	
public:
	OI();
	Joystick* GetDriverStick();
	Joystick* GetShooterStick();
};

#endif
