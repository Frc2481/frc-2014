/*
 * FireDiscCommand.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef FIREDISCCOMMAND_H_
#define FIREDISCCOMMAND_H_

#include "../CommandBase.h"
#include "FireInterruptedCommand.h"

class FireDiscCommand: public CommandBase {
private:
	//FireInterruptedCommand *fireInterruptCmd;
	bool hasFired;
public:
	FireDiscCommand(){
		//fireInterruptCmd = new FireInterruptedCommand();
		SetTimeout(1);
		Requires(shooter);
		Requires(hopper);
	}
	virtual ~FireDiscCommand(){}
	virtual void Initialize(){
		hasFired = false;
		airCompressor->Stop();
		//SetInterruptible(true);
	}
	virtual void Execute(){
		if (shooter->isAtSpeed()) {
			hopper->Load();
			hasFired = true;
			//SetInterruptible(false);
		}
	}
	virtual bool IsFinished(){
		return IsTimedOut(); //hasFired || IsTimedOut();
	}
	virtual void End(){
		airCompressor->Start();
		hopper->Retract();
			//fireInterruptCmd->Start();
	}
	virtual void Interrupted(){
		End();
			//fireInterruptCmd->Start();
	}
};

#endif /* FIREDISCCOMMAND_H_ */
