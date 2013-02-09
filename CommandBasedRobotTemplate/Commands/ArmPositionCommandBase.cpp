/*
 * ArmPositionCommandBase.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#include "ArmPositionCommandBase.h"

ArmPositionCommandBase::ArmPositionCommandBase(float position, const char * name) : CommandBase(name) {
	Requires(climbingArm);
	armPosition = position;
	childCommandType = (char*)name;
}

ArmPositionCommandBase::~ArmPositionCommandBase() {}

void ArmPositionCommandBase::Initialize(){
	climbingArm->setPosition(armPosition);
}
void ArmPositionCommandBase::Execute() {
	climbingArm->run();
}
bool ArmPositionCommandBase::IsFinished(){
	return climbingArm->isAtPosition();
}
void ArmPositionCommandBase::End(){
	climbingArm->stopArm();
}
void ArmPositionCommandBase::Interrupted(){
	End();
}
