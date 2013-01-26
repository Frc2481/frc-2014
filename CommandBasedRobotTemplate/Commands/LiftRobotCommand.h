/*
 * LiftRobotCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#ifndef LIFT_ROBOTCOMMAND_H_
#define LIFT_ROBOTCOMMAND_H_

#include "../CommandBase.h"

class LiftRobotCommand : public CommandBase {
public:
	LiftRobotCommand() : CommandBase("LiftRobotCommand"){}
	virtual ~LiftRobotCommand(){}
	void Initialize(){
		robotLift->lift();
	}
	void Execute(){}
	bool IsFinished(){
		return robotLift->isLifted();
	}
	void End(){}
	void Interrupted(){}
};

#endif /* LIFTROBOTCOMMAND_H_ */
