/*
 * ToggleLatchCommand.h
 *
 *  Created on: Jan 29, 2013
 *      Author: Team2481
 */

#ifndef TOGGLELATCHCOMMAND_H_
#define TOGGLELATCHCOMMAND_H_

#include "../CommandBase.h"
#include "LatchCommand.h"
#include "UnlatchCommand.h"

class ToggleLatchCommand: public CommandBase {
public:
	ToggleLatchCommand(){}
	virtual ~ToggleLatchCommand(){}
	void Initialize(){
		if (climbingHooks->isLatched()){
			climbingHooks->unlatch();
		}
		else {
			climbingHooks->latch();
		}
	}
	void Execute(){
	}
	bool IsFinished(){
		return true;
	}
	void Interrupted(){}
	void End(){}
};

#endif /* TOGGLELATCHCOMMAND_H_ */
