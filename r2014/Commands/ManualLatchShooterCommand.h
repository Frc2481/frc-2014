/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef MANUALLATCHSHOOTER_H_
#define MANUALLATCHSHOOTER_H_

#include "../CommandBase.h"

class ManualLatchShooterCommand: public CommandBase {
public:
	ManualLatchShooterCommand(){
		
	}
	virtual ~ManualLatchShooterCommand(){
		
	}
	virtual void Initialize(){
		shooter->ManualLatch();
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
