/*
 * TiltArmCommand.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef TILTARMFORWARDCOMMAND_H_
#define TILTARMFORWARDCOMMAND_H_

#include "../CommandBase.h"

class TiltArmForwardCommand: public CommandBase {
public:
	TiltArmForwardCommand(){
	}
	void Initialize(){
		climbingArm->tiltForward();
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
	virtual ~TiltArmForwardCommand(){}
};

#endif /* TILTARMCOMMAND_H_ */
