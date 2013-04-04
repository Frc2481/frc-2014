/*
 * FlipRobotCommand.h
 *
 *  Created on: Mar 28, 2013
 *      Author: Team2481
 */

#ifndef FLIPROBOTCOMMAND_H_
#define FLIPROBOTCOMMAND_H_

#include "../CommandBase.h"

class FlipRobotCommand: public CommandBase {

public:
	FlipRobotCommand(){}
	virtual ~FlipRobotCommand(){}
	void Initialize() {
		robotLift->flip();
		tipCorrectionEnabled = false;
	}
	void Execute(){}
	void Interrupted(){
		End();
	}
	bool IsFinished(){
		return false;
	}
	void End(){
		robotLift->retractFlip();
		tipCorrectionEnabled = true;
	}
};

#endif /* FLIPROBOTCOMMAND_H_ */
