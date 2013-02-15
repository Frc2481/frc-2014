/*
 * LatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef LATCHCOMMAND_H_
#define LATCHCOMMAND_H_
#include "ClimbCommandBase.h"

class LatchCommand : public ClimbCommandBase{
public:
	LatchCommand(int seqNum, bool autoCmd=false) : ClimbCommandBase(seqNum, "LatchCommand", autoCmd){}
	~LatchCommand(){}
	void ClimbInitialize(){
		climbingHooks->latch();
	}
	void ClimbExecute(){}
	bool IsFinished(){
		return climbingHooks->isLatched() || ClimbCommandBase::IsFinished();
	}
	void ClimbEnd(){}
	void Interrupted(){}
};

#endif /* LATCHCOMMAND_H_ */
