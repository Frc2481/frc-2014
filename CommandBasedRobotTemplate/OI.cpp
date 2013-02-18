#include "OI.h"
#include "Commands/EnableShiftCommand.h"
#include "Commands/FireDiscCommandGroup.h"
#include "Commands/FireDiscCommand.h"
#include "Commands/ExtendArmCommand.h"
#include "Commands/RetractArmCommand.h"
#include "Commands/ToggleLatchCommand.h"
#include "Commands/ClimbingCommandGroup.h"
#include "Commands/ToggleLiftCommand.h"
#include "Commands/ShooterToggleCommand.h"
#include "Commands/SpeedUpShooterCommand.h"
#include "Commands/SlowDownShooterCommand.h"
#include "Commands/ArmTiltToggleCommand.h"
#include "Commands/TiltArmBackwardCommand.h"
#include "Commands/TiltArmForwardCommand.h"
#include "Commands/ShooterUpToggleCommand.h"
#include "Commands/OpenHopperLidCommand.h"
#include "Commands/CloseHopperLidCommand.h"
#include "Commands/ToggleHopperLidCommand.h"
#include "Commands/DeadmanTestCommandGroup.h"
#include "Commands/SetLightsCommand.h"


OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick2481(DRIVER_STICK_PORT);
	shooterStick = new Joystick2481(SHOOTER_STICK_PORT);
	
	enableShiftButton = new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -0.5); //TODO change button argument to desired button
	enableShiftButton->WhileHeld(new EnableShiftCommand());
	
	fireDiscButton = new AnalogJoystickButton(shooterStick, XboxController::xbZAxis, -0.5);
	//fireDiscButton->WhileHeld(new FireDiscCommandGroup());
	fireDiscButton->WhileHeld(new FireDiscCommand());
	
	manualArmExtendButton = new AnalogJoystickButton(shooterStick, XboxController::xbRightYAxis, -0.5);
	manualArmExtendButton->WhileHeld(new ExtendArmCommand());
	
	manualArmRetractButton = new AnalogJoystickButton(shooterStick, XboxController::xbRightYAxis, 0.5);
	manualArmRetractButton->WhileHeld(new RetractArmCommand());
	
	manualLatchButton = new JoystickButton(shooterStick, XboxController::xbYButton);
	manualLatchButton->WhenPressed(new ToggleLatchCommand());
	
	climbSequenceButton = new JoystickButton(shooterStick, XboxController::xbStartButton);
	climbSequenceButton->WhenPressed(new ClimbingCommandGroup());
	
	liftButton = new JoystickButton(shooterStick, XboxController::xbXButton);
	liftButton->WhenPressed(new ToggleLiftCommand()); 
	
	toggleShooterButton = new JoystickButton(shooterStick, XboxController::xbRightBumper);
	toggleShooterButton->WhenPressed(new ShooterToggleCommand());
	
	tiltArmForwardButton =  new AnalogJoystickButton(shooterStick, XboxController::xbLeftYAxis, 0.5);
	tiltArmForwardButton->WhenPressed(new TiltArmForwardCommand(true));

	tiltArmBackwardButton =  new AnalogJoystickButton(shooterStick, XboxController::xbLeftYAxis, -0.5);
	tiltArmBackwardButton->WhenPressed(new TiltArmBackwardCommand(true));
	
	speedUpShooterButton = new JoystickButton(shooterStick, XboxController::xbAButton);
	speedUpShooterButton->WhenPressed(new SpeedUpShooterCommand());
	
	slowDownShooterButton = new JoystickButton(shooterStick, XboxController::xbBButton);
	slowDownShooterButton->WhenPressed(new SlowDownShooterCommand());
	
	ExtendArmButton = new JoystickButton(shooterStick, XboxController::xbLeftStickClick);
	ExtendArmButton->WhenPressed(new FullyExtendArmPositionCommand());
	
	RetractArmButton = new JoystickButton(shooterStick, XboxController::xbRightStickCLick);
	RetractArmButton->WhenPressed(new FullyRetractArmPositionCommand());
	
	toggleHooksButton = new JoystickButton(driverStick, XboxController::xbYButton);
	toggleHooksButton->WhenPressed(new ToggleLatchCommand());
	
	toggleShooterPositionButton = new AnalogJoystickButton(shooterStick, XboxController::xbZAxis, 0.5);
	toggleShooterPositionButton->WhenPressed(new ShooterUpToggleCommand);
	
	hopperLidToggleButton = new JoystickButton(shooterStick, XboxController::xbLeftBumper);
	hopperLidToggleButton->WhenPressed(new ToggleHopperLidCommand());
	
	redLightsButton = new JoystickButton(driverStick, XboxController::xbBButton);
	redLightsButton->WhenPressed(new SetLightsCommand(1));
	
	greenLightsButton = new JoystickButton(driverStick, XboxController::xbAButton);
	greenLightsButton->WhenPressed(new SetLightsCommand(2));
	
	blueLightsButton = new JoystickButton(driverStick, XboxController::xbXButton);
	blueLightsButton->WhenPressed(new SetLightsCommand(4));
}


Joystick* OI::GetDriverStick() {
	return driverStick;
}
Joystick* OI::GetShooterStick() {
	return shooterStick;
}

bool OI::GetDeadMan1() {
	return driverStick->GetRawButton(XboxController::xbBackButton);
}

bool OI::GetDeadMan2() {
	return shooterStick->GetRawButton(XboxController::xbBackButton);
}
