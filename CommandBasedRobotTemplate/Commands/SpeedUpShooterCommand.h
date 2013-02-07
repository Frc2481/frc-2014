/*
 * SpeedUpShooterCommand.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Team2481
 */

#ifndef SPEEDUPSHOOTERCOMMAND_H_
#define SPEEDUPHOOTERCOMMAND_H_

#include "../CommandBase.h"

class SpeedUpShooterCommand : public CommandBase{
public:
	SpeedUpShooterCommand(){}
	virtual ~SpeedUpShooterCommand(){}
	void Initialize(){
		CommandBase::shooter->setSpeed(CommandBase::shooter->GetSetpoint() + 50);
	}
	void Execute(){}
	bool IsFinished() {
		return true;
	}
	void End() {}
	void Interrupted(){}
	
};

#endif /* SPEEDUPSHOOTERCOMMAND_H_ */
