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
public:
	FireInterruptedCommand(){
		Requires(hopper);
		SetInterruptible(false);
		SetTimeout(2);
	}
	virtual ~FireInterruptedCommand(){}
	virtual void Execute(){
		if (TimeSinceInitialized() > HOPPER_EXTEND_TIME) {
			airCompressor->Start();
			hopper->Retract();
		}
	}
	virtual void Initialize(){}
	virtual void Interrupted(){}
	bool IsFinished(){
		return IsTimedOut();
	}
	void End(){
		
	}
	
};

#endif /* FIREINTERRUPTEDCOMMAND_H_ */
