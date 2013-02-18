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
	bool hasFired;
public:
	FireDiscCommand(){
		Requires(shooter);
		Requires(hopper);
	}
	virtual ~FireDiscCommand(){}
	virtual void Initialize(){
		hasFired = false;
		airCompressor->Stop();
		SetInterruptible(true);
	}
	virtual void Execute(){
		if (shooter->isAtSpeed()) {
			hopper->Load();
			hasFired = true;
			SetTimeout(HOPPER_EXTEND_TIME);
			SetInterruptible(false);
		}
	}
	virtual bool IsFinished(){
		return hasFired && IsTimedOut();
	}
	virtual void End(){
		airCompressor->Start();
		hopper->Retract();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* FIREDISCCOMMAND_H_ */
