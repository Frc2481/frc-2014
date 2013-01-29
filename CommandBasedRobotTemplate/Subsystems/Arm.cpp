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

Arm::Arm(UINT32 armLiftChannel, UINT32 robotLiftChannel, UINT32 armPosFarChannel, UINT32 armPosCloseChannel, UINT32 armExtendChannel) : PIDSubsystem("Arm", 1, 0, 0) {
	armLift = new Talon(armLiftChannel);
	robotLift = new Talon(robotLiftChannel);
	armExtensionChannel = new AnalogChannel(armExtendChannel);
	armPositionFar = new DigitalInput(armPosFarChannel);
	armPositionClose = new DigitalInput(armPosCloseChannel);
	//Enable(); MUST ENABLE TO USE PID!!
}

Arm::~Arm() {	
	delete armLift;
	delete robotLift;
	delete armExtensionChannel;
	delete armPositionFar;
	delete armPositionClose;
}

double Arm::ReturnPIDInput(){
	//return armExtensionChannel->GetAverageVoltage();
	//return 1 to mock pid input
	return 1;
	//remove
}
void Arm::UsePIDOutput(double output){
	/*if(armPositionFar->Get() && output > 0)
		output = 0;
	else if (armPositionClose->Get() && output < 0)
		output = 0;
	armLift->Set((float)output);
	robotLift->Set(-speedRatio*(float)output);*/
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
