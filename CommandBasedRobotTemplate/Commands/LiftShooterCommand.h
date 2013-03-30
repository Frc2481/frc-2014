/*
 * LiftShooterCommand.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Team2481
 */

#ifndef LIFTSHOOTERCOMMAND_H_
#define LIFTSHOOTERCOMMAND_H_

#include "CommandBase.h"

class LiftShooterCommand: public CommandBase {
public:
	LiftShooterCommand() : CommandBase("LiftShooterCommand"){}
	virtual ~LiftShooterCommand(){}
	virtual void Initialize() {
		if (climbingArm->getCurrentPosition() < 1) {
			shooter->LiftShooter();
		}
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return shooter->isShooterUp() ||
				climbingArm->getCurrentPosition() > 1;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* LIFTSHOOTERCOMMAND_H_ */
