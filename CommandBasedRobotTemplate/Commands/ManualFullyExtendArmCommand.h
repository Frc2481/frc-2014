/*
 * ManuallyFullyRetractArmCommand.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */
#include "../CommandBase.h"

class ManuallyFullyRetractArmCommand : public CommandBase {
public:
ManuallyFullyRetractArmCommand(float position, const char * name) : CommandBase(name) {
	//DO NOT Require(climbingArm)
}

~ManuallyFullyRetractArmCommand() {}

void Initialize(){
	climbingArm->setPosition(ARM_IN_LIMIT);
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
