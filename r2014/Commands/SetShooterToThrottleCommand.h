/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef SETSHOOTERTOTHROTTLE_H_
#define SETSHOOTERTOTHROTTLE_H_

#include "../CommandBase.h"

class SetShooterToThrottleCommand: public CommandBase {
public:
	SetShooterToThrottleCommand(){
	}
	virtual ~SetShooterToThrottleCommand(){
		
	}
	virtual void Initialize(){
		shooter->SetPosition(((-oi->GetThrottleStick()->GetRawAxis(4) + 1) / 2) * 16);
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
