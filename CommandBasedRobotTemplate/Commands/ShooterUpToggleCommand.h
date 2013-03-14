
/*
 * ShooterUpToggleCommand.h
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#ifndef SHOOTERUPTOGGLECOMMAND_H_
#define SHOOTERUPTOGGLECOMMAND_H_

#include "../CommandBase.h"

class ShooterUpToggleCommand: public CommandBase {
public:
	ShooterUpToggleCommand() {	
	}
	~ShooterUpToggleCommand() {
	}
	virtual void Initialize(){
		if(shooter->isShooterUp()){
			hopper->close();
			shooter->LowerShooter();
			shooter->turnOff();
			airCompressor->Start();
		}
		else if (climbingArm->getCurrentPosition() < 1) {
			shooter->LiftShooter();
		}
		printf("arm %f \n", climbingArm->getCurrentPosition());
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* SHOOTERUPTOGGLECOMMAND_H_ */
