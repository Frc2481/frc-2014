/*
 * FPSdrive.h
 *
 *  Created on: Feb 2, 2013
 *      Author: Team2481
 */

#ifndef FPSDRIVE_H_
#define FPSDRIVE_H_

#include "WPILib.h"

class FPSDrive {
private:
	float driveValue;
	float turnValue;
	
public:
	FPSDrive(){}
	virtual ~FPSDrive(){}
	void Drive(GenericHID *rightStick, UINT32 rightAxis, GenericHID *leftStick, UINT32 leftAxis, RobotDrive *drive){
		driveValue = rightStick->GetRawAxis(rightAxis);
		turnValue = leftStick->GetRawAxis(leftAxis);
		
		if (driveValue > 0){
			driveValue = driveValue * driveValue;
		}
		else {
			driveValue = -driveValue * driveValue;
		}
		
		if (turnValue > 0){
			turnValue = turnValue * turnValue;
		}
		else {
			turnValue = -turnValue * turnValue;
		}
		
		
		drive->SetLeftRightMotorOutputs(driveValue - turnValue, driveValue + turnValue);
	}
};

#endif /* FPSDRIVE_H_ */
