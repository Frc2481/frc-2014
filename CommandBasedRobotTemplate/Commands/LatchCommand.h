/*
 * LatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef LATCHCOMMAND_H_
#define LATCHCOMMAND_H_
#include "../Components/DeadmanCommand.h"

class LatchCommand : public DeadmanCommand{
public:
	LatchCommand() : DeadmanCommand("latchCommand"){}
	~LatchCommand(){}
	void Initialize(){}
	void DeadmanExecute(){
		climbingHooks->latch();
	}
	bool IsFinished(){
		return climbingHooks->isLatched();
	}
	void End(){}
	void Interrupted(){}
	void DeadmanInterrupt(){}
};

#endif /* LATCHCOMMAND_H_ */
