#include "OI.h"
#include "Commands/SetEncoderOffsetCommand.h"
#include "Commands/SetICommand.h"
#include "Commands/SetPCommand.h"
#include "Commands/ResetGyroCommand.h"
#include "Commands/JukeCommand.h"
#include "Robotmap.h"
#include "RobotParameters.h"
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
#include "Commands/SetForwardCommand.h"
#include "Commands/FireDistanceCommand.h"
#include "Commands/ShooterPassCommandGroup.h"
#include "Commands/ManualSetShooterPositionCommand.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick2481(DRIVER_STICK_PORT);
	auxStick = new Joystick2481(AUX_STICK_PORT);
	tuningStick = new Joystick2481(TUNE_STICK_PORT);
	throttleStick = new Joystick(THROTTLE_STICK_PORT);
	
	FROffsetButton = FR_OFFSET_BUTTON;
	FROffsetButton->WhenPressed(new SetEncoderOffsetCommand(FRENCODER));
//	FROffsetButton->WhenPressed(new SetICommand(true));
	
	FLOffsetButton = FL_OFFSET_BUTTON;
	FLOffsetButton->WhenPressed(new SetEncoderOffsetCommand(FLENCODER));
//	FLOffsetButton->WhenPressed(new SetPCommand(true));
	
	BROffsetButton = BR_OFFSET_BUTTON;
	BROffsetButton->WhenPressed(new SetEncoderOffsetCommand(BRENCODER));
//	BROffsetButton->WhenPressed(new SetICommand(false));
	
	BLOffsetButton = BL_OFFSET_BUTTON;
	BLOffsetButton->WhenPressed(new SetEncoderOffsetCommand(BLENCODER));
//	BLOffsetButton->WhenPressed(new SetPCommand(false));
	
	//CalibrateCompassButton = CALIBRATE_COMPASS_BUTTON;
	//CalibrateCompassButton->WhenPressed(new CalibrateCompassCommand());	
	/*
	RightJukeButton = new JoystickButton(driverStick, XboxController::xbRightBumper); 
	RightJukeButton->WhenPressed(new JukeCommand(true));
	
	LeftJukeButton = new JoystickButton(driverStick, XboxController::xbLeftBumper);
	LeftJukeButton->WhenPressed(new JukeCommand(false));
	*/
	//SetFieldOffsetButton = SET_FIELD_OFFSET_BUTTON;
	//SetFieldOffsetButton->WhenPressed(new SetFieldOffsetCommand());	
	
	//ResetGyroButton = RESET_GYRO_BUTTON;
	//ResetGyroButton->WhenPressed(new ResetGyroCommand());	
	
	
//	RetractShooterButton = RETRACT_SHOOTER_BUTTON;
//	RetractShooterButton->WhileHeld(new RetractShooterCommand());	
//	
//	ReleaseShooterButton = RELEASE_SHOOTER_BUTTON;
//	ReleaseShooterButton->WhileHeld(new ReleaseShooterCommand());	

	ManualFireButton = FIRE_BUTTON;
	ManualFireButton->WhenPressed(new FireCommandGroup());	
	//ManualFireButton->WhileHeld(new RetractShooterCommand());	
	
//	ManualLatchButton = new JoystickButton(auxStick, MANUAL_LATCH_BUTTON);
//	ManualLatchButton->WhenPressed(new ManualLatchShooterCommand());
	
	TurnOnIntakeButton = TURN_ON_INTAKE_BUTTON;
	TurnOnIntakeButton->WhenPressed(new TurnOnIntakeCommand());
	
	TurnOffIntakeButton = TURN_OFF_INTAKE_BUTTON;
	TurnOffIntakeButton->WhenReleased(new TurnOffIntakeCommand());
	
	SpitOutButton = VOMIT_BUTTON;
	SpitOutButton->WhileHeld(new SpitOutBallCommand());
	
	ToggleLeftEarButton = TOGGLE_LEFT_EAR_BUTTON;
	ToggleLeftEarButton->WhenPressed(new ToggleLeftEarCommand());
	
	ToggleRightEarButton = TOGGLE_RIGHT_EAR_BUTTON;
	ToggleRightEarButton->WhenPressed(new ToggleRightEarCommand());
	
	ToggleIntakeReadyButton = TOGGLE_INTAKE_READY_BUTTON;
	ToggleIntakeReadyButton->WhenPressed(new ToggleIntakeReadyCommand());
	
	AutoCockShooterButton = AUTO_COCK_SHOOTER_BUTTON;
	AutoCockShooterButton->WhenPressed(new AutoCockShooterCommand());
	//AutoCockShooterButton->WhileHeld(new ReleaseShooterCommand());
	
	AutoSetShooterButton = AUTO_SET_SHOOTER_BUTTON;
	AutoSetShooterButton->WhileHeld(new AutoSetShooterCommand());
	
//	IncShooterButton = new JoystickButton (auxStick, INC_SHOOTER_BUTTON);
//	IncShooterButton->WhenPressed(new IncShooterSetPointCommand());
//	
//	DecShooterButton = new JoystickButton (auxStick, DEC_SHOOTER_BUTTON);
//	DecShooterButton->WhenPressed(new DecShooterSetPointCommand());
	
	ShooterToThrottleButton = SHOOTER_TO_THROTTLE_BUTTON;
	ShooterToThrottleButton->WhenPressed(new SetShooterToThrottleCommand());
	
//	ToggleFieldCentricButton = TOGGLE_FIELD_CENTRIC_BUTTON;
//	ToggleFieldCentricButton->WhileHeld(new ToggleFieldCentricCommand());
	
	ForwardButton = FORWARD_BUTTON;
	ForwardButton->WhenPressed(new SetForwardCommand(true));
	
	BackwardButton = BACKWARD_BUTTON;
	BackwardButton->WhenPressed(new SetForwardCommand(false));
	
	TrussPassButton = TRUSS_PASS_BUTTON;
	TrussPassButton->WhenPressed(new ManualSetShooterPositionCommand(TRUSS_SHOT_DISTANCE, false));
	
	OutletPassButton = OUTLET_PASS_BUTTON;
	OutletPassButton->WhenPressed(new ManualSetShooterPositionCommand(OUTLET_SHOT_DISTANCE, true));
	
	CornerShotButton = CORNER_SHOT_BUTTON;
	CornerShotButton->WhenPressed(new ManualSetShooterPositionCommand(CORNER_SHOT_DISTANCE, false));
	
	NormalShotButton = NORMAL_SHOT_BUTTON;
	NormalShotButton->WhenPressed(new ManualSetShooterPositionCommand(NORMAL_SHOT_DISTANCE, true));
	
	ShooterPassButton = SHOOTER_PASS_BUTTON;
	ShooterPassButton->WhenPressed(new ShooterPassCommandGroup());
	
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
