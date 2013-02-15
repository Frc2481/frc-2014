/*
 * UnlatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef UNLATCHCOMMAND_H_
#define UNLATCHCOMMAND_H_
#include "ClimbCommandBase.h"

class UnlatchCommand : public ClimbCommandBase{
public:
	UnlatchCommand(int seq, bool autoCmd=false) : ClimbCommandBase(seq, "UnlatchCommand", autoCmd){}
	~UnlatchCommand(){}
	void ClimbInitialize(){
		climbingHooks->unlatch();
	}
	void ClimbExecute(){}
	bool IsFinished(){
		return !climbingHooks->isLatched() || ClimbCommandBase::IsFinished();
	}
	void ClimbEnd(){}
	void Interrupted(){}
};

#endif /* UNLATCHCOMMAND_H_ */
