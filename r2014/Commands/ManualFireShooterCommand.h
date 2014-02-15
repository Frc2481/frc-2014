/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef MANUALFIRESHOOTER_H_
#define MANUALFIRESHOOTER_H_

#include "../CommandBase.h"
#include "../ControllerMap.h"

class ManualFireShooterCommand: public CommandBase {

public:
	ManualFireShooterCommand(){
		Requires(shooter);
	}
	virtual ~ManualFireShooterCommand(){
		
	}
	virtual void Initialize(){
		if (!intake->GetPosition()) {
			shooter->ManualFire();
		}
	}
	virtual void Execute(){
		
	}
	virtual bool IsFinished(){
		return !(oi->GetAuxStick()->GetRawAxis(FIRE_BUTTON_NUM) < -.5);
	}
	virtual void End(){
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
