/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef CHECKOTGOALCOMMAND_H_
#define CHECKHOTGOALCOMMAND_H_

#include "../CommandBase.h"
class CheckHotGoalCommand: public CommandBase {
public:
	CheckHotGoalCommand(){
		SetTimeout(10);
	}
	virtual ~CheckHotGoalCommand(){
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
		camera->CheckHotTarget();
	}
	virtual bool IsFinished(){
		return camera->HasTarget() || IsTimedOut();
	}
	virtual void End(){
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
