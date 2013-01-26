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
}

ArmPositionCommandBase::~ArmPositionCommandBase() {}

void ArmPositionCommandBase::Initialize(){
	climbingArm->setPosition(armPosition);
}
bool ArmPositionCommandBase::IsFinished(){
	bool isOnTarget = climbingArm->OnTarget();
	return isOnTarget;
}
void ArmPositionCommandBase::Execute() {}
void ArmPositionCommandBase::End(){}
void ArmPositionCommandBase::Interrupted(){}
