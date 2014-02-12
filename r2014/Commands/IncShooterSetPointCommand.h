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
		
	}
	virtual ~IncShooterSetPointCommand(){
		
	}
	virtual void Initialize(){
		shooter->SetPositionVolts(shooter->GetSetPoint() + .1);
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
