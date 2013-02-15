/*
 * TiltArmCommand.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef TILTARMFORWARDCOMMAND_H_
#define TILTARMFORWARDCOMMAND_H_

#include "ClimbCommandBase.h"

class TiltArmForwardCommand: public ClimbCommandBase {
public:
	TiltArmForwardCommand(int seq, bool autoCmd=false) : ClimbCommandBase(seq, "TiltArmForwardCommand", autoCmd) {
	}
	void ClimbInitialize(){
		climbingArm->tiltForward();
	}
	void ClimbExecute(){}
	bool IsFinished(){
		return true;
	}
	void ClimbEnd(){}
	void Interrupted(){}
	virtual ~TiltArmForwardCommand(){}
};

#endif /* TILTARMCOMMAND_H_ */
