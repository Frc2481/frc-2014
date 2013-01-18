#include "OI.h"
#include "Commands/DisableShiftCommand.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick(DRIVER_STICK_PORT);
	shooterStick = new Joystick(SHOOTER_STICK_PORT);
	disableShiftButton = new JoystickButton(driverStick, Joystick::kDefaultTriggerButton); //TODO change button argument to desired button
	disableShiftButton->WhileHeld(new DisableShiftCommand());
}

Joystick* OI::GetDriverStick() {
	return driverStick;
}
Joystick* OI::GetShooterStick() {
	return shooterStick;
}
