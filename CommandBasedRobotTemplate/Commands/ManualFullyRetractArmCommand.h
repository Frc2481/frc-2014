/*
 * ManuallyFullyExtendArmCommand.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */
#include "../CommandBase.h"

class ManuallyFullyExtendArmCommand : public CommandBase {
ManuallyFullyExtendArmCommand(float position, const char * name) : CommandBase(name) {
	//DO NOT Require(climbingArm)
}

~ManuallyFullyExtendArmCommand() {}

void Initialize(){
	climbingArm->setPosition(ARM_OUT_LIMIT);
}
void Execute() {
	climbingArm->run();
}

bool IsFinished(){
	return climbingArm->isAtPosition();
}
void End(){
	climbingArm->stopArm();
}
void Interrupted(){
	End();
}
