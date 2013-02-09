/*
 * SafeUnlatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef SAFE_UNLATCHCOMMAND_H_
#define SAFE_UNLATCHCOMMAND_H_
#include "../CommandBase.h"

/*
 * SafeUnlatch: The idea behind this command is to unlatch only after we have
 * 				retracted the arm half way.  In other words when we are halfway 
 * 				to the next level we unlatch.
 */
class SafeUnlatchCommand : public CommandBase{
public:
	SafeUnlatchCommand() : CommandBase("UnlatchCommand"){}
	~SafeUnlatchCommand(){}
	void Initialize(){}
	void Execute(){}
	bool IsFinished(){
		return climbingArm->getCurrentPosition() < 2.0;
	}
	void End(){
		climbingHooks->unlatch();
		climbingArm->tiltBackward();
	}
	void Interrupted(){}
};

#endif /* SAFEUNLATCHCOMMAND_H_ */
