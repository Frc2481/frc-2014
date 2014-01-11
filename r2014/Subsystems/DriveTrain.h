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
#include "Commands/Subsystem.h"

class DriveTrain: public Subsystem {

#define MAX_CHANGE 10
private:
	SwerveModule *FLWheel;
	SwerveModule *FRWheel;
	SwerveModule *BRWheel;
	SwerveModule *BLWheel;
	
	static const double pi = 3.14159;
	static const double baseWidth = ROBOTWIDTH;
	static const double baseLength = ROBOTLENGTH;
	double prevAngle;
	double radius;
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();
	void Crab(double xPos, double yPos, double twist, bool useGyro);
	double degToRad(double deg);
	double radToDeg(double rad);
	double limitAngle(double angle);
};

#endif /* DRIVETRAIN_H_ */
