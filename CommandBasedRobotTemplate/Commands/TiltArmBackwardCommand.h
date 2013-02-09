/*
 * TiltArmBackwardsCommand.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef TILTARMBACKWARDSCOMMAND_H_
#define TILTARMBACKWARDSCOMMAND_H_

#include "../CommandBase.h"

class TiltArmBackwardCommand : public CommandBase{
public:
	TiltArmBackwardCommand(){
	}
	void Initialize(){
		climbingArm->tiltBackward();
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
	virtual ~TiltArmBackwardCommand();
};

#endif /* TILTARMBACKWARDSCOMMAND_H_ */
