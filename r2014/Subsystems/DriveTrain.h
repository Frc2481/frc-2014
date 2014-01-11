/*
 * DriveTrain.h
 *
 *  Created on: Jan 9, 2014
 *      Author: Team2481
 */

#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_
#include "../RobotParameters.h"
#include "../Components/SwerveModule.h"
#include "WPILib.h"

class DriveTrain {

private:
	SwerveModule *FLWheel;
	SwerveModule *FRWheel;
	SwerveModule *BRWheel;
	SwerveModule *BLWheel;
	
	static const double pi = 3.14159;
	static const float baseWidth = ROBOTWIDTH;
	static const float baseLength = ROBOTLENGTH;
public:
	DriveTrain();
	virtual ~DriveTrain();
	void Crab(float xPos, float yPos, float twist, bool useGyro);
};

#endif /* DRIVETRAIN_H_ */
