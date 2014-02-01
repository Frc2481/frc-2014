#include "OI.h"
#include "Commands/SetEncoderOffsetCommand.h"
#include "Commands/SetICommand.h"
#include "Commands/SetPCommand.h"
#include "Commands/ResetGyroCommand.h"
#include "Commands/CalibrateCompassCommand.h"
#include "Commands/SetFieldOffsetCommand.h"
#include "Commands/JukeCommand.h"
#include "Robotmap.h"
#include "Commands/ReleaseShooterCommand.h"
#include "Commands/RetractShooterCommand.h"
#include "Commands/ManualFireShooterCommand.h"
#include "Commands/ManualLatchShooterCommand.h"
#include "Commands/WriteToCSVCommand.h"

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
	CalibrateCompassButton = new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5);
	CalibrateCompassButton->WhenPressed(new CalibrateCompassCommand());	
	RightJukeButton = new JoystickButton(driverStick, XboxController::xbRightBumper); 
	RightJukeButton->WhenPressed(new JukeCommand(true));
	LeftJukeButton = new JoystickButton(driverStick, XboxController::xbLeftBumper);
	LeftJukeButton->WhenPressed(new JukeCommand(false));
	SetFieldOffsetButton = new JoystickButton(driverStick, XboxController::xbStartButton);
	SetFieldOffsetButton->WhenPressed(new SetFieldOffsetCommand());	
	
	ResetGyroButton = new JoystickButton(driverStick, XboxController::xbBackButton);
	ResetGyroButton->WhenPressed(new ResetGyroCommand());	
	
	ManualRetractShooterButton = new JoystickButton(auxStick, XboxController::xbLeftBumper);
	ManualRetractShooterButton->WhileHeld(new RetractShooterCommand());	
	
	ManualReleaseShooterButton = new JoystickButton(auxStick, XboxController::xbRightBumper);
	ManualReleaseShooterButton->WhileHeld(new ReleaseShooterCommand());	

	ManualFireButton = new JoystickButton(auxStick, XboxController::xbAButton);
	ManualFireButton->WhenPressed(new ManualFireShooterCommand());	
	
	ManualLatchButton = new JoystickButton(auxStick, XboxController::xbBButton);
	ManualLatchButton->WhenPressed(new ManualLatchShooterCommand());	

	WriteToCSVButton = new JoystickButton(auxStick, XboxController::xbStartButton);
	WriteToCSVButton->WhenPressed(new WriteToCSVCommand());	
	

	
	SmartDashboard::PutData(new ResetGyroCommand());
}

Joystick2481* OI::GetDriverStick() {
	return driverStick;
}
Joystick2481* OI::GetAuxStick() {
	return auxStick;
}
