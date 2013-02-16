/*
 * ArmPositionCommandBase.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#include "ArmPositionCommandBase.h"
#include "../Components/DeadmanCommand.h"

ArmPositionCommandBase::ArmPositionCommandBase(float position, const char * name) : DeadmanCommand(name) {
	Requires(climbingArm);
	armPosition = position;
	childCommandType = (char*)name;
}

ArmPositionCommandBase::~ArmPositionCommandBase() {}

void ArmPositionCommandBase::Initialize(){
	climbingArm->setPosition(armPosition);
}
void ArmPositionCommandBase::DeadmanExecute() {
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
void ArmPositionCommandBase::DeadmanInterrupt(){
	climbingArm->stopArm();
}
