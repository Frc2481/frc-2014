#include "OI.h"
#include "Commands/SetEncoderOffsetCommand.h"
#include "Commands/SetICommand.h"
#include "Commands/SetPCommand.h"
#include "Robotmap.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick2481(DRIVER_STICK_PORT);
	auxStick = new Joystick2481(AUX_STICK_PORT);
	FROffsetButton = new JoystickButton(driverStick, XboxController::xbBButton);
	FROffsetButton->WhenPressed(new SetEncoderOffsetCommand(FRENCODER));
//	FROffsetButton->WhenPressed(new SetICommand(true));
	FLOffsetButton = new JoystickButton(driverStick, XboxController::xbYButton);
	FLOffsetButton->WhenPressed(new SetEncoderOffsetCommand(FLENCODER));
//	FLOffsetButton->WhenPressed(new SetPCommand(true));
	BROffsetButton = new JoystickButton(driverStick, XboxController::xbAButton);
	BROffsetButton->WhenPressed(new SetEncoderOffsetCommand(BRENCODER));
//	BROffsetButton->WhenPressed(new SetICommand(false));
	BLOffsetButton = new JoystickButton(driverStick, XboxController::xbXButton);
	BLOffsetButton->WhenPressed(new SetEncoderOffsetCommand(BLENCODER));
//	BLOffsetButton->WhenPressed(new SetPCommand(false));
}

Joystick2481* OI::GetDriverStick() {
	return driverStick;
}
Joystick2481* OI::GetAuxStick() {
	return auxStick;
}
