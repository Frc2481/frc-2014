/*
 * SafeUnlatchCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: jonathanB
 */

#ifndef SAFE_UNLATCHCOMMAND_H_
#define SAFE_UNLATCHCOMMAND_H_
#include "../Components/DeadmanCommand.h"

/*
 * SafeUnlatch: The idea behind this command is to unlatch only after we have
 * 				retracted the arm half way.  In other words when we are halfway 
 * 				to the next level we unlatch.
 */
class SafeUnlatchCommand : public DeadmanCommand{
public:
	SafeUnlatchCommand() : DeadmanCommand("SafeUnlatchCommand"){}
	~SafeUnlatchCommand(){}
	void Initialize(){}
	bool IsFinished(){
		return (climbingArm->getCurrentPosition() > 2.0); // TODO Change > to <
	}
	void End(){
		climbingHooks->unlatch();
		climbingArm->tiltBackward();
	}
	void Interrupted(){}
	void DeadmanInterrupt(){}
	void DeadmanExecute(){}
};

#endif /* SAFEUNLATCHCOMMAND_H_ */
