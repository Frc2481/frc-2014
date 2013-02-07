/*
 * SlowDownShooterCommand.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Team2481
 */

#ifndef SPEEDUPSHOOTERCOMMAND_H_
#define SPEEDUPSHOOTERCOMMAND_H_

#include "../CommandBase.h"

class SlowDownShooterCommand : public CommandBase{
public:
	SlowDownShooterCommand(){}
	virtual ~SlowDownShooterCommand(){}
	void Initialize(){
		CommandBase::shooter->setSpeed(CommandBase::shooter->GetSetpoint() - 50);
	}
	void Execute(){}
	bool IsFinished() {
		return true;
	}
	void End() {}
	void Interrupted(){
	}
};

#endif /* SLOWDOWNSHOOTERCOMMAND_H_ */
