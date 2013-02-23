/*
 * FireDiscInstantCommand.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef FIREDISCINSTANTCOMMAND_H_
#define FIREDISCINSTANTCOMMAND_H_

#include "../CommandBase.h"
#include "FireInterruptedCommand.h"

class FireDiscInstantCommand: public CommandBase {
private:
	//FireInterruptedCommand *fireInterruptCmd;
	bool hasFired;
public:
	FireDiscInstantCommand(){
		//fireInterruptCmd = new FireInterruptedCommand();
		SetTimeout(1);
		Requires(shooter);
		Requires(hopper);
	}
	virtual ~FireDiscInstantCommand(){}
	virtual void Initialize(){
		hasFired = false;
		airCompressor->Stop();
		//SetInterruptible(true);
	}
	virtual void Execute(){
		if (shooter->isSettled()) {
			hopper->Fire();
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

#endif /* FIREDISCINSTANTCOMMAND_H_ */
