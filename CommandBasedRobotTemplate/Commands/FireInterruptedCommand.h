/*
 * FireInterruptedCommand.h
 *
 *  Created on: Feb 18, 2013
 *      Author: Team2481
 */

#ifndef FIREINTERRUPTEDCOMMAND_H_
#define FIREINTERRUPTEDCOMMAND_H_

#include "../CommandBase.h"

class FireInterruptedCommand: public CommandBase {
private:
	bool finished;
public:
	FireInterruptedCommand(){
		Requires(hopper);
		SetInterruptible(false);
		SetTimeout(2);
	}
	virtual void Initialize(){
		finished = false;
	}
	virtual ~FireInterruptedCommand(){}
	virtual void Execute(){
		
		if (TimeSinceInitialized() > HOPPER_EXTEND_TIME && hopper->isFired()) {
			airCompressor->Start();
			hopper->Retract();
		}
		else {
			finished = true;
		}
	}
	virtual void Interrupted(){
		finished = false;
	}
	bool IsFinished(){
		return IsTimedOut() || finished;
	}
	void End(){
		finished = false;
	}
	
};

#endif /* FIREINTERRUPTEDCOMMAND_H_ */
