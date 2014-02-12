/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef UPDATESHOOTERCOMMAND_H_
#define UPDATESHOOTERCOMMAND_H_

#include "../CommandBase.h"

class UpdateShooterCommand: public CommandBase {
public:
	UpdateShooterCommand(){
		Requires(shooter);
	}
	virtual ~UpdateShooterCommand(){
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
		shooter->Periodic();
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
