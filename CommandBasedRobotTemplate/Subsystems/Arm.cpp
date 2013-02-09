/*

3
 *      Author: Team2481
 */

#include "Arm.h"

float Arm::speedRatioUp = .75;
float Arm::speedRatioDown = .125;
float Arm::armSpeed = 1;
float Arm::armPositionTolerance = 0.1;
float Arm::armHighPos = 2.575;
//float Arm::armHighPos = 1.7;
//float Arm::armLowPos = 0.2;
float Arm::armLowPos = .96;

Arm::Arm(UINT32 armLiftChannel, UINT32 robotLiftChannel, UINT32 armPosFarChannel, UINT32 armPosCloseChannel, UINT32 armExtendChannel, UINT32 armTiltChannel) : Subsystem("Arm") {
	armLift = new Talon(armLiftChannel);
	robotLift = new Talon(robotLiftChannel);
	armExtensionChannel = new AnalogChannel(armExtendChannel);
	armTiltSolenoid = new Solenoid(armTiltChannel);
	desiredPosition = 1;
	
}

Arm::~Arm() {	
	delete armLift;
	delete robotLift;
	delete armExtensionChannel;
}

//double Arm::ReturnPIDInput(){
//	return armExtensionChannel->GetAverageVoltage();
//}
//
//void Arm::UsePIDOutput(double output){
//	
//	if (output > 0) {
//		output = 1;
//	}
//	else if (output < 0){
//		output = -1;
//	}
//	
//	if(getCurrentPosition() > armHighPos && output > 0) {
//		output = 0;
//	}
//	else if (getCurrentPosition() < armLowPos && output < 0) {
//		output = 0;
//	}
//	armLift->Set(speedRatioDown*(float)-output);
//	robotLift->Set((float)-output);
//}
void Arm::setPosition(double position){
	desiredPosition = position;
}
float Arm::getCurrentPosition(){
	return armExtensionChannel->GetAverageVoltage();
}
double Arm::getDesiredPosition(){
	return desiredPosition;
}

void Arm::extendArm() {
	if (getCurrentPosition() <= armHighPos) {
		armLift->Set(speedRatioUp*(float)-armSpeed);
		robotLift->Set((float)-armSpeed);
	}
	printf("ArmLift %f \n", -armSpeed*speedRatioDown);
	printf("ArmWinch %f \n", -armSpeed);
}

void Arm::retractArm() {
	if (getCurrentPosition() >= armLowPos) {
		armLift->Set(speedRatioDown*(float)armSpeed);
		robotLift->Set((float)armSpeed);
	}
	printf("ArmLift %f \n", armSpeed*speedRatioDown);
	printf("ArmWinch %f \n", armSpeed);
}

void Arm::stopArm() {
	armLift->Set(0);
	robotLift->Set(0);
}
bool Arm::isAtPosition() {
	return 	getCurrentPosition() <= getDesiredPosition() + armPositionTolerance && 
			getCurrentPosition() >= getDesiredPosition() - armPositionTolerance;
}

void Arm::run() {
	if (getCurrentPosition() >= getDesiredPosition() + armPositionTolerance  && getCurrentPosition() >= armLowPos) {
		retractArm();
	}
	else if (getCurrentPosition() <= getDesiredPosition() - armPositionTolerance && getCurrentPosition() <= armHighPos) {
		extendArm();
	}
	else {
		stopArm();
	}
	printf("Position + tol %f \n", getCurrentPosition() + armPositionTolerance);
	printf("Position - tol %f \n", getCurrentPosition() - armPositionTolerance);
	printf("Desired Position %f \n", getDesiredPosition());
	printf("Position %f \n \n", getCurrentPosition());
}
void Arm::tiltForward(){
	armTiltSolenoid->Set(1);
}
void Arm::tiltBackward(){
	armTiltSolenoid->Set(0);
}
