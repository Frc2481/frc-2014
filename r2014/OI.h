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
	Button *FROffsetButton;
	Button *FLOffsetButton;
	Button *BROffsetButton;
	Button *BLOffsetButton;
//	Button *CalibrateCompassButton;
//	Button *SetFieldOffsetButton;
//	Button *ResetGyroButton;
	Button *ManualRetractShooterButton;
	Button *ManualReleaseShooterButton;
	Button *ManualFireButton;
	Button *ManualLatchButton;
	Button *WriteToCSVButton;
	Button *RightJukeButton;
	Button *LeftJukeButton;
//	Button *RetractShooterButton;
//	Button *ReleaseShooterButton;
	Button *TurnOnIntakeButton;
	Button *TurnOffIntakeButton;
	Button *SpitOutButton;
	Button *ToggleIntakeReadyButton;
	Button *AutoCockShooterButton;
	Button *ToggleRightEarButton;
	Button *ToggleLeftEarButton;
	Button *AutoSetShooterButton;
//	Button *IncShooterButton;
//	Button *DecShooterButton;
	Button *ShooterToThrottleButton;
//	Button *ToggleFieldCentricButton;
	Button *ForwardButton;
	Button *BackwardButton;
	Button *TrussPassButton;
	Button *OutletPassButton;
	Button *CornerShotButton;
	Button *NormalShotButton;
	Button *ShooterPassButton;
	
public:
	OI();
	Joystick2481* GetDriverStick();
	Joystick2481* GetAuxStick();
	Joystick *GetThrottleStick();
};

#endif
