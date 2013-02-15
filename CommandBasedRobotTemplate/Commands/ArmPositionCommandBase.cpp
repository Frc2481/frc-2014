/*
 * ArmPositionCommandBase.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#include "ArmPositionCommandBase.h"

ArmPositionCommandBase::ArmPositionCommandBase(float position, int seq, bool autoCmd, const char * name) : ClimbCommandBase(seq, name, autoCmd) {
	Requires(climbingArm);
	armPosition = position;
	childCommandType = (char*)name;
}

ArmPositionCommandBase::~ArmPositionCommandBase() {}

void ArmPositionCommandBase::ClimbInitialize(){
	climbingArm->setPosition(armPosition);
}
void ArmPositionCommandBase::ClimbExecute() {
	climbingArm->run();
}
bool ArmPositionCommandBase::IsFinished(){
	return climbingArm->isAtPosition() || ClimbCommandBase::IsFinished();
}
void ArmPositionCommandBase::ClimbEnd(){
	climbingArm->stopArm();
}
void ArmPositionCommandBase::Interrupted(){
	End();
}
