#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Components/Joystick2481.h"
#include "XboxController.h"
#include "Components/AnalogJoystickButton.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int SHOOTER_STICK_PORT = 2;
	XboxController *driverStick;
	XboxController *shooterStick;
	JoystickButton *disableShiftButton;
	AnalogJoystickButton *fireDiscButton;
	JoystickButton *manualArmExtendButton;
	JoystickButton *manualArmRetractButton;
	JoystickButton *manualLatchButton;
	AnalogJoystickButton *climbSequenceButton;
	JoystickButton *liftButton;

public:
	OI();
	Joystick* GetDriverStick();
	Joystick* GetShooterStick();
};

#endif
