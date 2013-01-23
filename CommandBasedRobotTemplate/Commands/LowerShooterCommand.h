/*
 * LowerShooterCommand.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Team2481
 */

#ifndef LOWERSHOOTERCOMMAND_H_
#define LOWERSHOOTERCOMMAND_H_

#include "CommandBase.h"

class LowerShooterCommand: public CommandBase {
public:
	LowerShooterCommand() : CommandBase("LowerShooterCommand"){}
	virtual ~LowerShooterCommand(){}
	virtual void Initialize() {
		shooter->LowerShooter();
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return !shooter->isShooterUp();
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* LOWERSHOOTERCOMMAND_H_ */
