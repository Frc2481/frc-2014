/*
 * Arm.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#include "Arm.h"

float Arm::speedRatioUp = .75;
float Arm::speedRatioDown = .125;
float Arm::armSpeed = 1;
float Arm::armPositionTolerance = 0.25;
float Arm::armHighPos = 4.5;
float Arm::armLowPos = 0.3;

Arm::Arm(UINT32 armLiftChannel, UINT32 robotLiftChannel, UINT32 armPosFarChannel, UINT32 armPosCloseChannel, UINT32 armExtendChannel) : PIDSubsystem("Arm", 1, 0, 0) {
	armLift = new Talon(armLiftChannel);
	robotLift = new Talon(robotLiftChannel);
	armExtensionChannel = new AnalogChannel(armExtendChannel);
	//Enable();// MUST ENABLE TO USE PID!!
	Disable();
	SetAbsoluteTolerance(1);
}

Arm::~Arm() {	
	delete armLift;
	delete robotLift;
	delete armExtensionChannel;
}

double Arm::ReturnPIDInput(){
	return armExtensionChannel->GetAverageVoltage();
	//return 1 to mock pid input
	//return 1;
	//remove
}
void Arm::UsePIDOutput(double output){
	if(armExtensionChannel->GetAverageVoltage() > armHighPos && output > 0) {
		output = 0;
	}
	else if (armExtensionChannel->GetAverageVoltage() < armLowPos && output < 0) {
		output = 0;
	}
	armLift->Set(speedRatioDown*(float)output);
	robotLift->Set((float)output);
	
	//use new ratios
}
void Arm::setPosition(double position){
	SetSetpoint(position);
}
float Arm::getCurrentPosition(){
	return armExtensionChannel->GetAverageVoltage();
}
double Arm::getDesiredPosition(){
	return GetSetpoint();
}

void Arm::extendArm() {
	armLift->Set(speedRatioUp*(float)-armSpeed);
	robotLift->Set((float)-armSpeed);
}

void Arm::retractArm() {
	armLift->Set(speedRatioDown*(float)armSpeed);
	robotLift->Set((float)armSpeed);
}

void Arm::stopArm() {
	armLift->Set(0);
	robotLift->Set(0);
}

bool Arm::isAtPosition() {
	return getCurrentPosition() < getDesiredPosition() + armPositionTolerance && getCurrentPosition() > getDesiredPosition() - armPositionTolerance;
}
