	#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Components/Joystick2481.h"
#include "XboxController.h"
#include "Components/AnalogJoystickButton.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int SHOOTER_STICK_PORT = 2;
	static const int PID_STICK_PORT = 3;
	Joystick2481 *driverStick;
	Joystick2481 *shooterStick;
	Joystick2481 *pidTuneStick;
	AnalogJoystickButton *enableShiftButton;
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
	
	
public:
	OI();
	Joystick* GetDriverStick();
	Joystick* GetShooterStick();
	bool GetDeadMan1();
	bool GetDeadMan2();
};

#endif
