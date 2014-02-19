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
		printf("SetShooterToThrottle distance: %f \n",((-oi->GetThrottleStick()->GetRawAxis(3) + 1) / 2) * 16);
		shooter->SetPosition(((-oi->GetThrottleStick()->GetRawAxis(3) + 1) / 2) * 16);
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
