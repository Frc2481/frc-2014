/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef WAITFORSHOOTERSETPOINTCOMMAND_H_
#define WAITFORSHOOTERSETPOINTCOMMAND_H_

#include "../CommandBase.h"

class WaitForShooterSetpointCommand: public CommandBase {
public:
	WaitForShooterSetpointCommand(float timeout){
		SetTimeout(timeout);
	}
	virtual ~WaitForShooterSetpointCommand(){
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return shooter->OnTarget() && IsTimedOut();
	}
	virtual void End(){
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
