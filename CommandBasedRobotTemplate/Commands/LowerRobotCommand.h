/*
 * LowerRobotCommand.h
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#ifndef LOWER_ROBOTCOMMAND_H_
#define LOWER_ROBOTCOMMAND_H_

#include "../CommandBase.h"

class LowerRobotCommand : public CommandBase{
public:
	LowerRobotCommand() : CommandBase("LowerRobotCommand"){}
	virtual ~LowerRobotCommand(){}
	void Initialize(){
		robotLift->lower();
	}
	void Execute(){}
	bool IsFinished(){
		return !robotLift->isLifted();
	}
	void End(){}
	void Interrupted(){}
};

#endif /* LOWERROBOTCOMMAND_H_ */
