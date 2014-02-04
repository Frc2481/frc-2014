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
#include "../Components/HeadingSource.h"
#include "WPILib.h"
#include "Commands/Subsystem.h"

class DriveTrain: public Subsystem {

#define MAX_CHANGE 10
private:
	SwerveModule *FLWheel;
	SwerveModule *FRWheel;
	SwerveModule *BRWheel;
	SwerveModule *BLWheel;
	HeadingSource *headingSource;
	//ResetGyroCommand *resetGyroCommand;
	
	static const double pi = 3.14159;
	double baseWidth;
	double baseLength;
	double prevAngle;
	double radius;
	float prevAngleFR;
	float prevAngleFL;
	float prevAngleBR;
	float prevAngleBL;
	float angleOffset;
	float heading;
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();
	void Crab(double xPos, double yPos, double twist, bool fieldCentric);
	double degToRad(double deg);
	double radToDeg(double rad);
	double limitAngle(double angle);
	void SetLengthAndWidth(double robotLength, double robotWidth);
	float GetEncoderValue(int wheel);
	void SetP(float p);
	float GetP();
	void SetI(float i);
	float GetI();
	void ResetGyro();
	void UpdateCompass(bool done);
	void SetFieldOffset();
	float GetHeading();
};

#endif /* DRIVETRAIN_H_ */
