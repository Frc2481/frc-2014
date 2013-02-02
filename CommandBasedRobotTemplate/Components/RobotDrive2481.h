/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTDRIVE_2481_H_
#define ROBOTDRIVE_2481_H_

#include "../XboxController.h"
#include "WPILib.h"
/**
 * Utility class for handling Robot drive based on a definition of the motor configuration.
 * The robot drive class handles basic driving for a robot. Currently, 2 and 4 motor standard
 * drive trains are supported. In the future other drive types like swerve and meccanum might
 * be implemented. Motor channel numbers are passed supplied on creation of the class. Those are
 * used for either the Drive function (intended for hand created drive code, such as autonomous)
 * or with the Tank/Arcade functions intended to be used for Operator Control driving.
 */
class RobotDrive2481: public RobotDrive
{
	Joystick *driveStick;
public:
	RobotDrive2481(SpeedController leftDrive, SpeedController rightDrive) : RobotDrive(leftDrive, rightDrive){}
	~RobotDrive2481(){}
	void FPSDrive(Joystick stick){
		driveStick = stick;
		SetLeftRightMotorOutputs(driveStick->GetRawAxis(XboxController::xbLeftYAxis) - driveStick->GetRawAxis(XboxController::xbRightXAxis),
				driveStick->GetRawAxis(XboxController::xbLeftYAxis) + driveStick->GetRawAxis(XboxController::xbRightXAxis));
		
	}
	void PIDOut::PIDwrite(float PIDfloat){}
	void SpeedController::Set(float speed, UINT8 port){}
	float SpeedContoller::Get(){}
	void SpeedController::Disable(){}
	
	
};

#endif

