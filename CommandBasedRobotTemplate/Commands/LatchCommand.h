/*
 * LatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef LATCHCOMMAND_H_
#define LATCHCOMMAND_H_
#include "../CommandBase.h"

class LatchCommand : public CommandBase{
public:
	LatchCommand() : CommandBase("LatchCommand"){}
	~LatchCommand(){}
	void Initialize(){
		climbingHooks->latch();
	}
	void Execute(){}
	bool IsFinished(){
		return climbingHooks->isLatched();
	}
	void End(){}
	void Interrupted(){}
};

#endif /* LATCHCOMMAND_H_ */
