/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOCOCKSHOOTERCOMMAND_H_
#define AUTOCOCKSHOOTERCOMMAND_H_

#include "../CommandBase.h"

class AutoCockShooterCommand: public CommandBase {
private:
	bool isFinished;
public:
	AutoCockShooterCommand(){
		Requires(shooter);
	}
	virtual ~AutoCockShooterCommand(){
		
	}
	virtual void Initialize(){
		isFinished = false;
	}
	virtual void Execute(){
		if (!shooter->IsLatched()){
			shooter->CockWinch();
		}
		else{
			shooter->ManualStopWinch();
			isFinished = true;
		}
	}
	virtual bool IsFinished(){
		return isFinished;
	}
	virtual void End(){
		shooter->ManualStopWinch();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
