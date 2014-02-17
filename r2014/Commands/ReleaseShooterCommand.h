/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef RELEASESHOOTERCOMMAND_H_
#define RELEASESHOOTERCOMMAND_H_

#include "../CommandBase.h"

class ReleaseShooterCommand: public CommandBase {
public:
	ReleaseShooterCommand(){
		Requires(shooter);
		
	}
	virtual ~ReleaseShooterCommand(){
		
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		shooter->ManualReleaseWinch();
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
//		shooter->SetPosition(shooter->GetPosition());
		shooter->ManualStopWinch();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* RELEASESHOOTERCOMMAND_H_ */
