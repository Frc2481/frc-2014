/*
 * UnlatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef UNLATCHCOMMAND_H_
#define UNLATCHCOMMAND_H_
#include "../CommandBase.h"

class UnlatchCommand : public CommandBase{
public:
	UnlatchCommand() : CommandBase("UnlatchCommand"){}
	~UnlatchCommand(){}
	void Initialize(){
		climbingHooks->unlatch();
	}
	void Execute(){}
	bool IsFinished(){
		return !climbingHooks->isLatched();
	}
	void End(){}
	void Interrupted(){}
};

#endif /* UNLATCHCOMMAND_H_ */
