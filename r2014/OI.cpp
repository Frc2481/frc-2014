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
#include "Commands/TurnOnIntakeCommand.h"
#include "Commands/TurnOffIntakeCommand.h"
#include "Commands/SpitOutBallCommand.h"
#include "Commands/ToggleLeftEarCommand.h"
#include "Commands/ToggleRightEarCommand.h"
#include "Commands/ToggleIntakeReadyCommand.h"
#include "Commands/AutoCockShooterCommand.h"
#include "Commands/AutoSetShooterCommand.h"
#include "Commands/FireCommandGroup.h"
#include "Commands/IncShooterSetPointCommand.h"
#include "Commands/DecShooterSetPointCommand.h"
#include "Commands/SetShooterToThrottleCommand.h"
#include "Commands/ToggleFieldCentricCommand.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick2481(DRIVER_STICK_PORT);
	auxStick = new Joystick2481(AUX_STICK_PORT);
	tuningStick = new Joystick2481(TUNE_STICK_PORT);
	throttleStick = new Joystick(THROTTLE_STICK_PORT);
	
	FROffsetButton = new JoystickButton(tuningStick, FR_OFFSET_BUTTON);
	FROffsetButton->WhenPressed(new SetEncoderOffsetCommand(FRENCODER));
//	FROffsetButton->WhenPressed(new SetICommand(true));
	
	FLOffsetButton = new JoystickButton(tuningStick, FL_OFFSET_BUTTON);
	FLOffsetButton->WhenPressed(new SetEncoderOffsetCommand(FLENCODER));
//	FLOffsetButton->WhenPressed(new SetPCommand(true));
	
	BROffsetButton = new JoystickButton(tuningStick, BR_OFFSET_BUTTON);
	BROffsetButton->WhenPressed(new SetEncoderOffsetCommand(BRENCODER));
//	BROffsetButton->WhenPressed(new SetICommand(false));
	
	BLOffsetButton = new JoystickButton(tuningStick, BL_OFFSET_BUTTON);
	BLOffsetButton->WhenPressed(new SetEncoderOffsetCommand(BLENCODER));
//	BLOffsetButton->WhenPressed(new SetPCommand(false));
	
	CalibrateCompassButton = new AnalogJoystickButton(driverStick, CALIBRATE_COMPASS_BUTTON, -.5);
	CalibrateCompassButton->WhenPressed(new CalibrateCompassCommand());	
	/*
	RightJukeButton = new JoystickButton(driverStick, XboxController::xbRightBumper); 
	RightJukeButton->WhenPressed(new JukeCommand(true));
	
	LeftJukeButton = new JoystickButton(driverStick, XboxController::xbLeftBumper);
	LeftJukeButton->WhenPressed(new JukeCommand(false));
	*/
	SetFieldOffsetButton = new JoystickButton(driverStick, SET_FIELD_OFFSET_BUTTON);
	SetFieldOffsetButton->WhenPressed(new SetFieldOffsetCommand());	
	
	ResetGyroButton = new JoystickButton(driverStick, RESET_GYRO_BUTTON);
	ResetGyroButton->WhenPressed(new ResetGyroCommand());	
	
	
	RetractShooterButton = new AnalogJoystickButton(auxStick, RETRACT_SHOOTER_BUTTON, -.5);
	RetractShooterButton->WhileHeld(new RetractShooterCommand());	
	
	ReleaseShooterButton = new AnalogJoystickButton(auxStick, RELEASE_SHOOTER_BUTTON, .5);
	ReleaseShooterButton->WhileHeld(new ReleaseShooterCommand());	

	ManualFireButton = new AnalogJoystickButton(auxStick, FIRE_BUTTON, -.5);
	ManualFireButton->WhenPressed(new FireCommandGroup());	
	
//	ManualLatchButton = new JoystickButton(auxStick, MANUAL_LATCH_BUTTON);
//	ManualLatchButton->WhenPressed(new ManualLatchShooterCommand());
	
	TurnOnIntakeButton = new JoystickButton(driverStick, TURN_ON_INTAKE_BUTTON);
	TurnOnIntakeButton->WhenPressed(new TurnOnIntakeCommand());
	
	TurnOffIntakeButton = new JoystickButton(driverStick, TURN_OFF_INTAKE_BUTTON);
	TurnOffIntakeButton->WhenPressed(new TurnOffIntakeCommand());
	
	SpitOutButton = new JoystickButton(auxStick, VOMIT_BUTTON);
	SpitOutButton->WhileHeld(new SpitOutBallCommand());
	
	ToggleLeftEarButton = new JoystickButton(auxStick, TOGGLE_LEFT_EAR_BUTTON);
	ToggleLeftEarButton->WhenPressed(new ToggleLeftEarCommand());
	
	ToggleRightEarButton = new JoystickButton(auxStick, TOGGLE_RIGHT_EAR_BUTTON);
	ToggleRightEarButton->WhenPressed(new ToggleRightEarCommand());
	
	ToggleIntakeReadyButton = new JoystickButton(auxStick, TOGGLE_INTAKE_READY_BUTTON);
	ToggleIntakeReadyButton->WhenPressed(new ToggleIntakeReadyCommand());
	
	AutoCockShooterButton = new AnalogJoystickButton (auxStick, AUTO_COCK_SHOOTER_BUTTON, .5);
	AutoCockShooterButton->WhenPressed(new AutoCockShooterCommand());
	
	AutoSetShooterButton = new JoystickButton (auxStick, AUTO_SET_SHOOTER_BUTTON);
	AutoSetShooterButton->WhileHeld(new AutoSetShooterCommand());
	
//	IncShooterButton = new JoystickButton (auxStick, INC_SHOOTER_BUTTON);
//	IncShooterButton->WhenPressed(new IncShooterSetPointCommand());
//	
//	DecShooterButton = new JoystickButton (auxStick, DEC_SHOOTER_BUTTON);
//	DecShooterButton->WhenPressed(new DecShooterSetPointCommand());
	
	ShooterToThrottleButton = new JoystickButton(auxStick, SHOOTER_TO_THROTTLE_BUTTON);
	ShooterToThrottleButton->WhenPressed(new SetShooterToThrottleCommand());
	
	ToggleFieldCentricButton = new AnalogJoystickButton(driverStick, TOGGLE_FIELD_CENTRIC_BUTTON, -.5);
	ToggleFieldCentricButton->WhileHeld(new ToggleFieldCentricCommand());
	
	SmartDashboard::PutData(new ResetGyroCommand());
}

Joystick2481* OI::GetDriverStick() {
	return driverStick;
}
Joystick2481* OI::GetAuxStick() {
	return auxStick;
}
Joystick* OI::GetThrottleStick(){
	return throttleStick;
}
