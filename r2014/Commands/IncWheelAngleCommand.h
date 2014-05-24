/*
 * IncWheelAngleCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef INCWHEELANGLECOMMAND_H_
#define INCWHEELANGLECOMMAND_H_

#include "../CommandBase.h"

class IncWheelAngleCommand: public CommandBase {
	int mWheel;
public:
	IncWheelAngleCommand(int wheel){
		mWheel = wheel;
	}
	virtual ~IncWheelAngleCommand(){
		
	}
	virtual void Initialize(){
		driveTrain->SetWheelAngle(mWheel, (int)(driveTrain->GetWheelAngle(mWheel) + 5) % 360);
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* INCWHEELANGLECOMMAND_H_ */
