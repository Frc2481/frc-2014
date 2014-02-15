/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef WAITFORHOTGOALCOMMAND_H_
#define WAITFORHOTGOALCOMMAND_H_

#include "../CommandBase.h"
class WaitForHotGoalCommand: public CommandBase {
public:
	WaitForHotGoalCommand(){
	}
	virtual ~WaitForHotGoalCommand(){
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return camera->HasTarget();
	}
	virtual void End(){
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
