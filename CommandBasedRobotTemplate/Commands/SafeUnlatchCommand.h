/*
 * SafeUnlatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef SAFE_UNLATCHCOMMAND_H_
#define SAFE_UNLATCHCOMMAND_H_
#include "ClimbCommandBase.h"

/*
 * SafeUnlatch: The idea behind this command is to unlatch only after we have
 * 				retracted the arm half way.  In other words when we are halfway 
 * 				to the next level we unlatch.
 */
class SafeUnlatchCommand : public ClimbCommandBase{
public:
	SafeUnlatchCommand(int seq, bool autoCmd=false) : ClimbCommandBase(seq, "SafeUnlatchCommand", autoCmd){}
	~SafeUnlatchCommand(){}
	void ClimbInitialize(){}
	void ClimbExecute(){}
	bool IsFinished(){
		return (climbingArm->getCurrentPosition() < 2.0) || ClimbCommandBase::IsFinished();
	}
	void ClimbEnd(){
		climbingHooks->unlatch();
		climbingArm->tiltBackward();
	}
	void Interrupted(){}
};

#endif /* SAFEUNLATCHCOMMAND_H_ */
