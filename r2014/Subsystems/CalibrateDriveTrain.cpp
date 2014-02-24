/*
 * CalibrateDriveTrain.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: Team2481
 */

#include <cmath>
#include "CalibrateDriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/CrabDriveCommand.h"

CalibrateDriveTrain::CalibrateDriveTrain() : Subsystem("CalibrateDriveTrain"),
				FLWheel(new Talon(FLDRIVE)),
				FRWheel(new Talon(FRDRIVE)), 
				BRWheel(new Talon(BRDRIVE)),
				BLWheel(new Talon(BLDRIVE)),
				FLSteer(new Talon(FLSTEER)),
				FRSteer(new Talon(FRSTEER)), 
				BRSteer(new Talon(BRSTEER)),
				BLSteer(new Talon(BLSTEER)),
				count(0),
				headingSource(new HeadingSource(GYRO_CHANNEL, COMPASS_MODULE)){
				//wiiGyro(new WiiGyro(COMPASS_MODULE)){
	printf("Pre CalibrateDriveTrain Constructor \n");
	prevAngle = 90.0;
	printf("post CalibrateDriveTrain Constructor \n");
}

void CalibrateDriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new CrabDriveCommand());
}

void CalibrateDriveTrain::Stop() {
	FLWheel = 0;
	FRWheel = 0;
	BLWheel = 0;
	BRWheel = 0;
}

void CalibrateDriveTrain::Crab(double xPos, double yPos, double twist, bool fieldCentric){
	count++;
	if((count < 50)){
		FLWheel->Set(1);
		FRWheel->Set(1);
		BRWheel->Set(1);
		BLWheel->Set(1);
		FLSteer->Set(1);
		FRSteer->Set(1);
		BRSteer->Set(1);
		BLSteer->Set(1);
	}
	else if (count < 100){
		FLWheel->Set(-1);
		FRWheel->Set(-1);
		BRWheel->Set(-1);
		BLWheel->Set(-1);
		FLSteer->Set(-1);
		FRSteer->Set(-1);
		BRSteer->Set(-1);
		BLSteer->Set(-1);
	}
	else if (count < 300){
		FLWheel->Set(0);
		FRWheel->Set(0);
		BRWheel->Set(0);
		BLWheel->Set(0);
		FLSteer->Set(0);
		FRSteer->Set(0);
		BRSteer->Set(0);
		BLSteer->Set(0);
		
	}
	else {
		count = 0;
	}
	printf("count %d \n", count);
}

void CalibrateDriveTrain::SetLengthAndWidth(double robotLength, double robotWidth) {
}

double CalibrateDriveTrain::degToRad(double deg) {
	return deg * pi / 180;
}

double CalibrateDriveTrain::radToDeg(double rad) {
	return rad * 180 / pi;
}

float CalibrateDriveTrain::GetEncoderValue(int wheel) {
}

CalibrateDriveTrain::~CalibrateDriveTrain() {
}

float CalibrateDriveTrain::GetP() { 
}

void CalibrateDriveTrain::SetP(float p) {
}

float CalibrateDriveTrain::GetI() { 
}

void CalibrateDriveTrain::SetI(float i) {
}
void CalibrateDriveTrain::ResetGyro(){
}
void CalibrateDriveTrain::UpdateCompass(bool done){
	//headingSource->CompassPeriodic(done);
}
void CalibrateDriveTrain::SetFieldOffset(){
	//headingSource->SetZeroAngle();
}
float CalibrateDriveTrain::GetHeading(){
	return heading;
}
float CalibrateDriveTrain::GetWheelAngle(int wheel){
}

void CalibrateDriveTrain::SetWheelAngle(int wheel, float angle){
}
void CalibrateDriveTrain::SetOptimized(bool optimized){
}
void CalibrateDriveTrain::SetForward(bool fwd) {
}
void CalibrateDriveTrain::SetGyroCorrection(bool b) {
}
void CalibrateDriveTrain::SetFieldCentric(bool fieldCentric) {
}
