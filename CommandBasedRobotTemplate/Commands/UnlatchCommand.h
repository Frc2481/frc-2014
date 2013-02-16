/*
 * UnlatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef UNLATCHCOMMAND_H_
#define UNLATCHCOMMAND_H_
#include "../Components/DeadmanCommand.h"

class UnlatchCommand : public DeadmanCommand{
public:
	UnlatchCommand() : DeadmanCommand("UnlatchCommand"){}
	~UnlatchCommand(){}
	void Initialize(){}
	void DeadmanExecute(){
		climbingHooks->unlatch();
	}
	bool IsFinished(){
		return !climbingHooks->isLatched();
	}
	void End(){}
	void Interrupted(){}
	void DeadmanInterrupt(){}
};

#endif /* UNLATCHCOMMAND_H_ */
