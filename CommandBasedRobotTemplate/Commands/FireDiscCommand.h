/*
 * FireDiscCommand.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef FIREDISCCOMMAND_H_
#define FIREDISCCOMMAND_H_

#include "../CommandBase.h"

class FireDiscCommand: public CommandBase {
private:
	static const double timeout = 1;
public:
	FireDiscCommand(){
		Requires(shooter);
		Requires(hopper);
	}
	virtual ~FireDiscCommand(){}
	virtual void Initialize(){
		
		//if (shooter->isShooterUp() && shooter->OnTarget()) {
			SetTimeout(timeout);
			hopper->Load();
		//}
		//else {
		//	SetTimeout(0);
		//}
	}
	virtual void Execute(){}
	virtual bool IsFinished(){
		return IsTimedOut();
	}
	virtual void End(){
		hopper->Retract();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* FIREDISCCOMMAND_H_ */
