/*
 * AutoCockShooterCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOCOCKSHOOTERCOMMAND_H_
#define AUTOCOCKSHOOTERCOMMAND_H_

#include "../CommandBase.h"

class AutoCockShooterCommand: public CommandBase {
public:
	AutoCockShooterCommand(){
		Requires(shooter);
	}
	virtual ~AutoCockShooterCommand(){
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
		shooter->CockWinch();
	}
	virtual bool IsFinished(){
		return shooter->IsLatched();
	}
	virtual void End(){
		shooter->ManualStopWinch();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
