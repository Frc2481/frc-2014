/*
 * TiltArmCommand.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef TILTARMFORWARDCOMMAND_H_
#define TILTARMFORWARDCOMMAND_H_

#include "../Components/DeadmanCommand.h"

class TiltArmForwardCommand: public DeadmanCommand {
public:
	TiltArmForwardCommand() : DeadmanCommand("TiltArmForwardCommand") {}
	virtual ~TiltArmForwardCommand(){}
	void Initialize(){}
	void DeadmanExecute(){
		climbingArm->tiltForward();
	}
	bool IsFinished(){
		return climbingArm->isTilted();
	}
	void End(){}
	void Interrupted(){}
	void DeadmanInterrupt(){}
};

#endif /* TILTARMCOMMAND_H_ */