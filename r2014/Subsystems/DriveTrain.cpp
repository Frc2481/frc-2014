/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: Team2481
 */

#include <cmath>
#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/CrabDriveCommand.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
				FLWheel(new SwerveModule(FLDRIVE, FLSTEER, FLENCODER)),
				FRWheel(new SwerveModule(FRDRIVE, FRSTEER, FRENCODER)), 
				BRWheel(new SwerveModule(BRDRIVE, BRSTEER, BRENCODER)),
				BLWheel(new SwerveModule(BLDRIVE, BRSTEER, BRENCODER))  {
	prevAngle = 90.0;
	radius = sqrt(pow(baseLength,2)+pow(baseWidth,2));
	// TODO Auto-generated constructor stub
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new CrabDriveCommand());
}

double DriveTrain::limitAngle(double angle) {
	double diff1 = angle - prevAngle;
	bool invert = false;
	if (fabs(diff1) > 180)
		invert = true;
	if (diff1 < 0) {
		diff1 += 360;
	}
	double diff2 = 360 - diff1;
	bool goLeft = false;
	if (diff1 < diff2) {
		goLeft = true;
	}
	//if (invert)
		//goLeft = !goLeft;
	goLeft = goLeft ^ invert;
	double targetAngle;
	if (goLeft) {
		targetAngle = min(angle, prevAngle + MAX_CHANGE);
	}
	else {
		targetAngle = max(angle, prevAngle - MAX_CHANGE);
	}
	
	prevAngle = angle;
	return targetAngle;
}

void DriveTrain::Crab(double xPos, double yPos, double twist, bool useGyro){
	//twist = twist * pi;
	
	//double angle = radToDeg(atan2(yPos, xPos)) + 180;
	//double magnitude = sqrt(pow(xPos, 2) + pow(yPos, 2));
	/*angle limiting
	angle = this.limitAngle(angle);
	double FWD = magnitude * sin(degToRad(angle));
	double STR = magnitude * cos(degToRad(angle));
	*/
	double FWD = yPos;
	double STR = xPos;
	
	SmartDashboard::PutNumber("FWD", FWD);
	SmartDashboard::PutNumber("STR", STR);
	SmartDashboard::PutNumber("twist", twist);
	
	// TODO get gyro angle
	if (useGyro) {
		// TODO FWD = yPos * cosf(gyro angle) + xPos * sinf(gyro angle);
		// TODO STR = -yPos * sinf(gyro angle) + xPos * cosf(gyro angle);
	}
	double A = STR - twist * baseLength / radius;
	double B = STR + twist * baseLength / radius;
	double C = FWD - twist * baseWidth / radius;
	double D = FWD + twist * baseWidth / radius;
	SmartDashboard::PutNumber("A", A);
	SmartDashboard::PutNumber("B", B);
	SmartDashboard::PutNumber("C", C);
	SmartDashboard::PutNumber("D", D);
	double wheelSpeedFR = sqrt(pow(B, 2) + pow(C, 2));
	double wheelSpeedFL = sqrt(pow(B, 2) + pow(D, 2));
	double wheelSpeedBR = sqrt(pow(A, 2) + pow(C, 2));
	double wheelSpeedBL = sqrt(pow(A, 2) + pow(D, 2));
	double wheelAngleFR = atan2(B, C) * 180 / pi;
	double wheelAngleFL = atan2(B, D) * 180 / pi;
	double wheelAngleBR = atan2(A, C) * 180 / pi;
	double wheelAngleBL = atan2(A, D) * 180 / pi;
	
	//speeds normalized 0 to 1
	//maybe eventually reverse motor instead of turning far and going forward
	double maxWheelSpeed = wheelSpeedFR;
	if (wheelSpeedFL > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedFL;
	}
	if (wheelSpeedBR > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedBR;
	}
	if (wheelSpeedBL > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedBL;
	}
	if (maxWheelSpeed > 1) {
		wheelSpeedFR /= maxWheelSpeed;
		wheelSpeedFL /= maxWheelSpeed;
		wheelSpeedBR /= maxWheelSpeed;
		wheelSpeedBL /= maxWheelSpeed;
	}
	
	SmartDashboard::PutNumber("wheelSpeedFR", wheelSpeedFR);
	SmartDashboard::PutNumber("wheelSpeedFL", wheelSpeedFL);
	SmartDashboard::PutNumber("wheelSpeedBR", wheelSpeedBR);
	SmartDashboard::PutNumber("wheelSpeedBL", wheelSpeedBL);
	SmartDashboard::PutNumber("wheelAngleFR", wheelAngleFR);
	SmartDashboard::PutNumber("wheelAngleFL", wheelAngleFL);
	SmartDashboard::PutNumber("wheelAngleBR", wheelAngleBR);
	SmartDashboard::PutNumber("wheelAngleBL", wheelAngleBL);
	
	FRWheel->Set(wheelSpeedFR, wheelAngleFR);
	FLWheel->Set(wheelSpeedFL, wheelAngleFL);
	BRWheel->Set(wheelSpeedBR, wheelAngleBR);
	BLWheel->Set(wheelSpeedBL, wheelAngleBL);
}

double DriveTrain::degToRad(double deg) {
	return deg * pi / 180;
}

double DriveTrain::radToDeg(double rad) {
	return rad * 180 / pi;
}

DriveTrain::~DriveTrain() {
	delete FRWheel;
	delete BRWheel;
	delete FLWheel;
	delete BLWheel;
	
	// TODO Auto-generated destructor stub
}
