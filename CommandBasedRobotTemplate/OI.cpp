#include "OI.h"
#include "Commands/DisableShiftCommand.h"
#include "Commands/FireDiscCommand.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new XboxController(DRIVER_STICK_PORT);
	shooterStick = new XboxController(SHOOTER_STICK_PORT);
	disableShiftButton = new JoystickButton(driverStick, XboxController::xbAButton); //TODO change button argument to desired button
	disableShiftButton->WhileHeld(new DisableShiftCommand());
	fireDiscButton = new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5);
	fireDiscButton->WhileHeld(new FireDiscCommand);
}

Joystick* OI::GetDriverStick() {
	return driverStick;
}
Joystick* OI::GetShooterStick() {
	return shooterStick;
}
