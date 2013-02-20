/*
 *      Author: Team2481
 */

#include "Arm.h"

float Arm::speedRatioUp = ARM_UP_SPEED_RATIO;
float Arm::speedRatioDown = ARM_DOWN_SPEED_RATIO;
float Arm::armSpeed = ARM_SPEED;
float Arm::armPositionTolerance = ARM_POSITION_TOLERANCE;
float Arm::armHighPos = ARM_OUT_LIMIT;
float Arm::armLowPos = ARM_IN_LIMIT;

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
	//printf("ArmLift %f \n", -armSpeed*speedRatioDown);
	//printf("ArmWinch %f \n", -armSpeed);
}

void Arm::retractArm() {
	if (getCurrentPosition() >= armLowPos) {
		armLift->Set(speedRatioDown*(float)armSpeed);
		robotLift->Set((float)armSpeed);
	}
	//printf("ArmLift %f \n", armSpeed*speedRatioDown);
	//printf("ArmWinch %f \n", armSpeed);
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
	//printf("Position + tol %f \n", getCurrentPosition() + armPositionTolerance);
	//printf("Position - tol %f \n", getCurrentPosition() - armPositionTolerance);
	//printf("Desired Position %f \n", getDesiredPosition());
	//printf("Position %f \n \n", getCurrentPosition());
}
void Arm::tiltForward(){
	armTiltSolenoid->Set(1);
}
void Arm::tiltBackward(){
	armTiltSolenoid->Set(0);
}

bool Arm::isTilted() {
	return armTiltSolenoid->Get();
}
