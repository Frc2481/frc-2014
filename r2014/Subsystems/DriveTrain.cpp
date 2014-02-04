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
				BLWheel(new SwerveModule(BLDRIVE, BLSTEER, BLENCODER)),
				headingSource(new HeadingSource(GYRO_CHANNEL, COMPASS_MODULE)) {
	prevAngle = 90.0;
	FLWheel->SetOffset(PersistedSettings::GetInstance().Get("FL_ENCODER_OFFSET"));
	FRWheel->SetOffset(PersistedSettings::GetInstance().Get("FR_ENCODER_OFFSET"));
	BRWheel->SetOffset(PersistedSettings::GetInstance().Get("BR_ENCODER_OFFSET"));
	BLWheel->SetOffset(PersistedSettings::GetInstance().Get("BL_ENCODER_OFFSET"));
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new CrabDriveCommand());
}

void DriveTrain::Crab(double xPos, double yPos, double twist, bool fieldCentric){
//	double FWD = yPos;
//	double STR = -xPos;
	twist = -twist * .4;
	
	heading = headingSource->GetHeading();
	double FWD = yPos * cos(heading * pi / 180) + xPos *sin(heading * pi / 180);
	double STR = xPos * cos(heading * pi / 180) - yPos * sin(heading * pi / 180);
	STR = -STR;
	
	
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
	SmartDashboard::PutNumber("twist", twist);
	double wheelSpeedFL = sqrt(pow(B, 2) + pow(C, 2));
	double wheelSpeedFR = sqrt(pow(B, 2) + pow(D, 2));
	double wheelSpeedBL = sqrt(pow(A, 2) + pow(C, 2));
	double wheelSpeedBR = sqrt(pow(A, 2) + pow(D, 2));
	double wheelAngleFL = atan2(B, C) * 180 / pi;
	double wheelAngleFR = atan2(B, D) * 180 / pi;
	double wheelAngleBL = atan2(A, C) * 180 / pi;
	double wheelAngleBR = atan2(A, D) * 180 / pi;
	
	
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
	SmartDashboard::PutNumber("heading", headingSource->GetHeading());
//	SmartDashboard::PutData(resetGyroCommand);
	
	//if (fieldCentric) {
	/*
		float heading = headingSource->GetHeading();
		wheelAngleFR += heading;
		wheelAngleFL += heading;
		wheelAngleBR += heading;
		wheelAngleBL += heading;
		*/
	//}
	
	//printf("%f\n", FLWheel->GetAngle());
	//printf("setPoint  = %f\n",FLWheel->GetController()->GetSetPoint());
	FLWheel->Set(wheelSpeedFL, wheelAngleFL + 180);
	FRWheel->Set(wheelSpeedFR, wheelAngleFR + 180);
	BRWheel->Set(wheelSpeedBR, wheelAngleBR + 180);
	BLWheel->Set(wheelSpeedBL, wheelAngleBL + 180);
	
//	FLWheel->Set(wheelSpeedFL, wheelAngleFL + 180);
//	FRWheel->Set(wheelSpeedFR, wheelAngleFR + 180);
//	BRWheel->Set(wheelSpeedBR, 0);
//	BLWheel->Set(wheelSpeedBL, wheelAngleBL + 180);
	
	angleOffset = wheelAngleFL + 180;
	
	printf("%f %f %f %f \n", FLWheel->GetRawAngle(), FRWheel->GetRawAngle(), BLWheel->GetRawAngle(), BRWheel->GetRawAngle());
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

float DriveTrain::GetEncoderValue(int wheel) {
	if (wheel == FRENCODER) {
		return FRWheel->GetRawAngle();
	}else if (wheel == FLENCODER) {
		return FLWheel->GetRawAngle();
	}else if (wheel == BRENCODER) {
		return BRWheel->GetRawAngle();
	}else if (wheel == BLENCODER) {
		return BLWheel->GetRawAngle();
	}
	return 0.0;
}

DriveTrain::~DriveTrain() {
	delete FRWheel;
	delete BRWheel;
	delete FLWheel;
	delete BLWheel;
}

float DriveTrain::GetP() { 
	return FLWheel->GetController()->GetP();
}

void DriveTrain::SetP(float p) {
	FLWheel->GetController()->SetP(p);
	FRWheel->GetController()->SetP(p);
	BRWheel->GetController()->SetP(p);
	BLWheel->GetController()->SetP(p);
}

float DriveTrain::GetI() { 
	return FLWheel->GetController()->GetI();
}

void DriveTrain::SetI(float i) {
	FLWheel->GetController()->SetI(i);
	FRWheel->GetController()->SetI(i);
	BRWheel->GetController()->SetI(i);
	BLWheel->GetController()->SetI(i);
}
void DriveTrain::ResetGyro(){
	headingSource->ResetGyro();
}
void DriveTrain::UpdateCompass(bool done){
	headingSource->CompassPeriodic(done);
}
void DriveTrain::SetFieldOffset(){
	headingSource->setFieldHeadingOffset(-angleOffset);
}
float DriveTrain::GetHeading(){
	return heading;
}
