	#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Components/Joystick2481.h"
#include "XboxController.h"
#include "Components/AnalogJoystickButton.h"
#include "Components/HeldButtonScheduler2481.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int SHOOTER_STICK_PORT = 2;
	static const int PID_STICK_PORT = 3;
	Joystick2481 *driverStick;
	Joystick2481 *shooterStick;
	Joystick2481 *pidTuneStick;
	AnalogJoystickButton *shiftUpButton;
	AnalogJoystickButton *fireDiscButton;
	AnalogJoystickButton *manualArmExtendButton;
	AnalogJoystickButton *manualArmRetractButton;
	JoystickButton *manualLatchButton;
	JoystickButton *climbSequenceButton;
	JoystickButton *liftButton;
	JoystickButton *toggleShooterButton;
	JoystickButton *speedUpShooterButton;
	JoystickButton *slowDownShooterButton;
	JoystickButton *ExtendArmButton;
	JoystickButton *RetractArmButton;
	AnalogJoystickButton *tiltArmForwardButton;
	AnalogJoystickButton *tiltArmBackwardButton;	
	AnalogJoystickButton *toggleShooterPositionButton;
	JoystickButton *hopperLidToggleButton;
	JoystickButton *cycleTopLightsButton;
	JoystickButton *cycleBottomLightsButton;
	JoystickButton *blueLightsButton;
	JoystickButton *toggleHooksButton;
	AnalogJoystickButton *toggleFineTuneButton;
	JoystickButton *pUpButton;
	JoystickButton *pDownButton;
	JoystickButton *iUpButton;
	JoystickButton *iDownButton;
	JoystickButton *speedUpShooterPIDButton;
	JoystickButton *slowDownShooterPIDButton;
	JoystickButton *flipRobotButton;
	AnalogJoystickButton *fireDiscPIDButton;
	HeldButtonScheduler2481 *fireButtonScheduler;
	HeldButtonScheduler2481 *firePIDButtonScheduler;
	
public:
	OI();
	Joystick* GetDriverStick();
	Joystick* GetShooterStick();
	AnalogJoystickButton* GetFireDiscButton();
	bool GetDeadMan1();
	bool GetDeadMan2();
};

#endif
