/*
 * ArmTiltToggleCommand.h
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#ifndef ARMTILTTOGGLECOMMAND_H_
#define ARMTILTTOGGLECOMMAND_H_

#include "../CommandBase.h"

class ArmTiltToggleCommand: public CommandBase {
public:
	ArmTiltToggleCommand() {	
	}
	~ArmTiltToggleCommand() {
	}
	virtual void Initialize(){
		if(climbingArm->isTilted()){
			climbingArm->tiltBackward();
		}
		else {
			climbingArm->tiltForward();
		}
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* ARMTILTTOGGLECOMMAND_H_ */
