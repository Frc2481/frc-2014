#include "OI.h"
#include "Commands/ShiftUpCommand.h"
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
#include "Commands/CycleBottomLightsCommand.h"
#include "Commands/CycleTopLightsCommand.h"
#include "Commands/FineTuneToggle.h"
#include "Commands/SetPCommand.h"
#include "Commands/SetICommand.h"
#include "Commands/AutoFireCommandGroup.h"
#include "Commands/FlipRobotCommand.h"
#include "Commands/ToggleTipCorrection.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick2481(DRIVER_STICK_PORT);
	shooterStick = new Joystick2481(SHOOTER_STICK_PORT);
	pidTuneStick = new Joystick2481(PID_STICK_PORT);
	
	pUpButton = new JoystickButton(pidTuneStick, XboxController::xbAButton);
	pUpButton->WhenPressed(new SetPCommand(true));
	pDownButton = new JoystickButton(pidTuneStick, XboxController::xbBButton);
	pDownButton->WhenPressed(new SetPCommand(false));
	
	iUpButton = new JoystickButton(pidTuneStick, XboxController::xbXButton);
	iUpButton->WhenPressed(new SetICommand(true));
	iDownButton = new JoystickButton(pidTuneStick, XboxController::xbYButton);
	iDownButton->WhenPressed(new SetICommand(false));

	speedUpShooterPIDButton = new JoystickButton(pidTuneStick, XboxController::xbStartButton);
	speedUpShooterPIDButton->WhenPressed(new SpeedUpShooterCommand());
	slowDownShooterPIDButton = new JoystickButton(pidTuneStick, XboxController::xbBackButton);
	slowDownShooterPIDButton->WhenPressed(new SlowDownShooterCommand());
	
	fireDiscPIDButton = new AnalogJoystickButton(pidTuneStick, XboxController::xbZAxis, -0.5);
	//fireDiscPIDButton->WhileHeld(new FireDiscCommand(false));
	
	firePIDButtonScheduler = new HeldButtonScheduler2481(0, fireDiscPIDButton, new FireDiscCommand(false));
	firePIDButtonScheduler->Start();
	
	
	shiftUpButton = new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -0.5); //TODO change button argument to desired button
	shiftUpButton->WhileHeld(new ShiftUpCommand());
	
	toggleFineTuneButton = new AnalogJoystickButton(driverStick, XboxController::xbZAxis, 0.5);
	toggleFineTuneButton->WhileHeld(new FineTuneToggle());
	
	fireDiscButton = new AnalogJoystickButton(shooterStick, XboxController::xbZAxis, -0.5);
	//fireDiscButton->WhileHeld(new FireDiscCommandGroup());
	//fireDiscButton->WhileHeld(new FireDiscCommand(false));
	
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
	
	cycleBottomLightsButton = new JoystickButton(driverStick, XboxController::xbBButton);
	cycleBottomLightsButton->WhenPressed(new CycleBottomLightsCommand());
	
	cycleTopLightsButton = new JoystickButton(driverStick, XboxController::xbAButton);
	cycleTopLightsButton->WhenPressed(new CycleTopLightsCommand());
	
	blueLightsButton = new JoystickButton(driverStick, XboxController::xbXButton); // not blue. needs to be changed
	blueLightsButton->WhenPressed(new AutoFireCommandGroup());
	
	fireButtonScheduler = new HeldButtonScheduler2481(0, fireDiscButton, new FireDiscCommand(false));
	fireButtonScheduler->Start();
	
	flipRobotButton = new JoystickButton(driverStick, XboxController::xbRightBumper);
	flipRobotButton->WhileHeld(new FlipRobotCommand());
	
	toggleTipCorrectionButton = new JoystickButton(driverStick, XboxController::xbStartButton);
	toggleTipCorrectionButton->WhenPressed(new ToggleTipCorrection());
	
	
}


Joystick* OI::GetDriverStick() {
	return driverStick;
}
Joystick* OI::GetShooterStick() {
	return shooterStick;
}

AnalogJoystickButton* OI::GetFireDiscButton() {
	return fireDiscButton;
}

bool OI::GetDeadMan1() {
	return 1;
	//return driverStick->GetRawButton(XboxController::xbBackButton);
}

bool OI::GetDeadMan2() {
	return 1;
	//return shooterStick->GetRawButton(XboxController::xbBackButton);
}
