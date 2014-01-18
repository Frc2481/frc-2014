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
				BLWheel(new SwerveModule(BLDRIVE, BLSTEER, BLENCODER)) {
				//headingSource(new HeadingSource(GYRO_CHANNEL, COMPASS_MODULE)){
	prevAngle = 90.0;
	// TODO Auto-generated constructor stub
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new CrabDriveCommand());
}

void DriveTrain::Crab(double xPos, double yPos, double twist, bool fieldCentric){
	double FWD = yPos;
	double STR = xPos;
	
	
	SmartDashboard::PutNumber("FWD", FWD);
	SmartDashboard::PutNumber("STR", STR);
	SmartDashboard::PutNumber("twist", twist);

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
	
	if (fieldCentric) {
		float heading = headingSource->GetHeading();
		wheelAngleFR += heading;
		wheelAngleFL += heading;
		wheelSpeedBR += heading;
		wheelSpeedBL += heading;
	}
	
	//FRWheel->Set(wheelSpeedFR, wheelAngleFR + 180);
	//FLWheel->Set(wheelSpeedFL, wheelAngleFL + 180);
	BRWheel->Set(wheelSpeedBR, wheelAngleBR + 180);
	//BLWheel->Set(wheelSpeedBL, wheelAngleBL + 180);

}

void DriveTrain::SetLengthAndWidth(double robotLength, double robotWidth) {
	baseLength = robotLength;
	baseWidth = robotWidth;
	radius = sqrt(pow(robotLength, 2)+pow(robotWidth, 2));
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
}
