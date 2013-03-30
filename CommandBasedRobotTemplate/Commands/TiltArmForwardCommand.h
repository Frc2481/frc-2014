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
private:
	bool mManual;
public:
	TiltArmForwardCommand(bool manual=false) : DeadmanCommand("TiltArmForwardCommand"), mManual(manual) {
		SetTimeout(0.7);
	}
	virtual ~TiltArmForwardCommand(){}
	void Initialize(){
		if (mManual) {
			climbingArm->tiltForward();
		}	
	}
	void DeadmanExecute(){
		climbingArm->tiltForward();
	}
	bool IsFinished(){
		return IsTimedOut() && climbingArm->isTilted();
	}
	void End(){}
	void Interrupted(){}
	void DeadmanInterrupt(){}
};

#endif /* TILTARMCOMMAND_H_ */
