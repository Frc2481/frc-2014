/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef RETRACTSHOOTER_H_
#define RETRACTSHOOTER_H_

#include "../CommandBase.h"

class RetractShooterCommand: public CommandBase {
public:
	RetractShooterCommand(){
		
	}
	virtual ~RetractShooterCommand(){
		
	}
	virtual void Initialize(){
		shooter->ManualRetractWinch();
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		shooter->ManualStopWinch();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
