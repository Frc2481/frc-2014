/*
 * TiltArmBackwardsCommand.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef TILTARMBACKWARDSCOMMAND_H_
#define TILTARMBACKWARDSCOMMAND_H_

#include "../Components/DeadmanCommand.h"

class TiltArmBackwardCommand : public DeadmanCommand{
public:
	TiltArmBackwardCommand() : DeadmanCommand("TiltArmBackwardCommand"){}
	virtual ~TiltArmBackwardCommand(){}
	void Initialize(){}
	bool IsFinished(){
		return !climbingArm->isTilted();
	}
	void End(){}
	void Interrupted(){}
	void DeadmanInterrupt(){}
	void DeadmanExecute(){
		climbingArm->tiltBackward();
	}
};

#endif /* TILTARMBACKWARDSCOMMAND_H_ */
