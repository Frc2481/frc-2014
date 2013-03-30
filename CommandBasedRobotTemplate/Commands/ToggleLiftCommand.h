/*
 * ToggleLiftCommand.h
 *
 *  Created on: Jan 29, 2013
 *      Author: Team2481
 */

#ifndef TOGGLELIFTCOMMAND_H_
#define TOGGLELIFTCOMMAND_H_

#include "../CommandBase.h"

class ToggleLiftCommand: public CommandBase {
public:
	ToggleLiftCommand(){}
	virtual ~ToggleLiftCommand(){}
	void Initialize(){
		if (robotLift->isLifted()){
			robotLift->lower();
			tipCorrectionEnabled = false;
		}
		else {
			robotLift->lift();
			tipCorrectionEnabled = true;
		}
	}
	void Execute(){
	}
	bool IsFinished(){
		return true;
	}
	void Interrupted(){}
	void End(){}
};

#endif /* TOGGLELiftCOMMAND_H_ */
