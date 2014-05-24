/*
 * RetractShooterCommand.h
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
		Requires(shooter);
	}
	virtual ~RetractShooterCommand(){
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
		shooter->ManualRetractWinch();
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		//shooter->SetPosition(shooter->GetPosition());
		shooter->ManualStopWinch();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* RETRACTSHOOTER_H_ */
