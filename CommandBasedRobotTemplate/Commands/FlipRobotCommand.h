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
	bool finished;
public:
	FlipRobotCommand(){}
	virtual ~FlipRobotCommand(){}
	void Initialize() {
		finished = false;
	}
	void Execute(){
		if (oi->GetDriverStick()->GetRawButton(XboxController::xbRightBumper) &&
			oi->GetDriverStick()->GetRawButton(XboxController::xbLeftBumper)) {
			robotLift->flip();
			tipCorrectionEnabled = false;
		} else {
			finished = true;
		}
	}
	void Interrupted(){
		End();
	}
	bool IsFinished(){
		return finished;
	}
	void End(){
		robotLift->retractFlip();
		tipCorrectionEnabled = true;
	}
};

#endif /* FLIPROBOTCOMMAND_H_ */
