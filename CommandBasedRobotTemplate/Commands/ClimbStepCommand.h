/*
 * ClimbStepCommand.h
 *
 *  Created on: Feb 17, 2013
 *      Author: Team2481
 */

#ifndef CLIMBSTEPCOMMAND_H_
#define CLIMBSTEPCOMMAND_H_

#include "../CommandBase.h"

class ClimbStepCommand: public CommandBase {
public:
	ClimbStepCommand() : CommandBase("ClimbStepCommand"){
	}
	virtual ~ClimbStepCommand(){}
	virtual void Execute(){}
	virtual void Initialize(){}
	virtual void End(){}
	virtual void Interrupted(){}
	bool IsFinished(){
		return oi->GetShooterStick()->GetRawButton(XboxController::xbStartButton);
	}
};

#endif /* CLIMBSTEPCOMMAND_H_ */
