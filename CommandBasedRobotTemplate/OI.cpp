#include "OI.h"
#include "Commands/EnableShiftCommand.h"
#include "Commands/FireDiscCommand.h"
#include "Commands/ExtendArmCommand.h"
#include "Commands/RetractArmCommand.h"
#include "Commands/ToggleLatchCommand.h"
#include "Commands/ClimbingCommandGroup.h"
#include "Commands/ToggleLiftCommand.h"
#include "Commands/ShooterToggleCommand.h"
#include "Commands/SpeedUpShooterCommand.h"
#include "Commands/SlowDownShooterCommand.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new XboxController(DRIVER_STICK_PORT);
	shooterStick = new XboxController(SHOOTER_STICK_PORT);
	disableShiftButton = new JoystickButton(driverStick, XboxController::xbLeftBumper); //TODO change button argument to desired button
	disableShiftButton->WhileHeld(new EnableShiftCommand());
	fireDiscButton = new AnalogJoystickButton(shooterStick, XboxController::xbZAxis, -.5);
	fireDiscButton->WhileHeld(new FireDiscCommand());
	manualArmExtendButton = new JoystickButton(shooterStick, XboxController::xbRightBumper);
	manualArmExtendButton->WhileHeld(new ExtendArmCommand());
	manualArmRetractButton = new JoystickButton(shooterStick, XboxController::xbLeftBumper);
	manualArmRetractButton->WhileHeld(new RetractArmCommand());
	manualLatchButton = new JoystickButton(shooterStick, XboxController::xbYButton);
	manualLatchButton->WhenPressed(new ToggleLatchCommand());
	climbSequenceButton = new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5);
	ClimbingCommandGroup *climbingGroup = new ClimbingCommandGroup();
	//climbSequenceButton->WhileHeld(climbingGroup);
	liftButton = new JoystickButton(shooterStick, XboxController::xbXButton);
	liftButton->WhenPressed(new ToggleLiftCommand()); 
	toggleShooterButton = new JoystickButton(shooterStick, XboxController::xbBButton);
	toggleShooterButton->WhenPressed(new ShooterToggleCommand);
	speedUpShooterButton = new JoystickButton(shooterStick, XboxController::xbStartButton);
	speedUpShooterButton->WhenPressed(new SpeedUpShooterCommand);
	slowDownShooterButton = new JoystickButton(shooterStick, XboxController::xbSelectButton);
	slowDownShooterButton->WhenPressed(new SlowDownShooterCommand);
	//idclimbSequenceButton->WhenReleased(new ClimbResetCommand(climbingGroup));
}

Joystick* OI::GetDriverStick() {
	return driverStick;
}
Joystick* OI::GetShooterStick() {
	return shooterStick;
}
