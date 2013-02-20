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
	FireInterruptedCommand *fireInterruptCmd;
	bool hasFired;
public:
	FireDiscCommand(){
		fireInterruptCmd = new FireInterruptedCommand();
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
		return hasFired;
	}
	virtual void End(){
			fireInterruptCmd->Start();
	}
	virtual void Interrupted(){
		//End();
			fireInterruptCmd->Start();
	}
};

#endif /* FIREDISCCOMMAND_H_ */
