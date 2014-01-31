/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef INCSHOOTERSETPOINTCOMMAND_H_
#define INCSHOOTERSETPOINTCOMMAND_H_

#include "../CommandBase.h"

class IncShooterSetPointCommand: public CommandBase {
public:
	IncShooterSetPointCommand(){
		bool isFinished = 0;
		SetTimeout(1.5);
	}
	virtual ~IncShooterSetPointCommand(){
		
	}
	virtual void Initialize(){
		shooter->Fire(distanceSensors->Get());
	}
	virtual void Execute(){
		if(!shooter->GetEars()){
			isFinished = true;
		}
	}
	virtual bool IsFinished(){
		return isFinished;
	}
	virtual void End(){
		shooter->ManualFire();
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
