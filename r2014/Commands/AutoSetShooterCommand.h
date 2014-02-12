/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOSETSHOOTERCOMMAND_H_
#define AUTOSETSHOOTERCOMMAND_H_

#include "../CommandBase.h"

class AutoSetShooterCommand: public CommandBase {
public:
	AutoSetShooterCommand(){
	}
	virtual ~AutoSetShooterCommand(){
		
	}
	virtual void Initialize(){
		shooter->SetPosition(distanceSensors->GetRight() / 12);
	}
	virtual void Execute(){
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
