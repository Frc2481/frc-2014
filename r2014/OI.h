#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Components/Joystick2481.h"
#include "XboxController.h"
#include "Components/AnalogJoystickButton.h"
#include "ControllerMap.h"

class OI {
private:
	static const int DRIVER_STICK_PORT = 1;
	static const int AUX_STICK_PORT = 2;
	static const int TUNE_STICK_PORT = 4;
	static const int THROTTLE_STICK_PORT = 3;
	Joystick2481 *driverStick;
	Joystick2481 *auxStick;
	Joystick2481 *tuningStick;
	Joystick *throttleStick;
	JoystickButton *FROffsetButton;
	JoystickButton *FLOffsetButton;
	JoystickButton *BROffsetButton;
	JoystickButton *BLOffsetButton;
	AnalogJoystickButton *CalibrateCompassButton;
	JoystickButton *SetFieldOffsetButton;
	JoystickButton *ResetGyroButton;
	JoystickButton *ManualRetractShooterButton;
	JoystickButton *ManualReleaseShooterButton;
	AnalogJoystickButton *ManualFireButton;
	JoystickButton *ManualLatchButton;
	JoystickButton *WriteToCSVButton;
	JoystickButton *RightJukeButton;
	JoystickButton *LeftJukeButton;
	AnalogJoystickButton *RetractShooterButton;
	AnalogJoystickButton *ReleaseShooterButton;
	JoystickButton *TurnOnIntakeButton;
	JoystickButton *TurnOffIntakeButton;
	JoystickButton *SpitOutButton;
	JoystickButton *ToggleIntakeReadyButton;
	AnalogJoystickButton *AutoCockShooterButton;
	JoystickButton *ToggleRightEarButton;
	JoystickButton *ToggleLeftEarButton;
	JoystickButton *AutoSetShooterButton;
//	JoystickButton *IncShooterButton;
//	JoystickButton *DecShooterButton;
	JoystickButton *ShooterToThrottleButton;
	AnalogJoystickButton *ToggleFieldCentricButton;
	
public:
	OI();
	Joystick2481* GetDriverStick();
	Joystick2481* GetAuxStick();
	Joystick *GetThrottleStick();
};

#endif
