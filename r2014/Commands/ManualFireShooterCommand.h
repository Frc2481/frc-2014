/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef MANUALFIRESHOOTER_H_
#define MANUALFIRESHOOTER_H_

#include "../CommandBase.h"

class ManualFireShooterCommand: public CommandBase {
public:
	ManualFireShooterCommand(){
		
	}
	virtual ~ManualFireShooterCommand(){
		
	}
	virtual void Initialize(){
		shooter->ManualFire();
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
