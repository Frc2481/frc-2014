/*
 * DecWheelAngleCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef DECWHEELANGLECOMMAND_H_
#define DECWHEELANGLECOMMAND_H_

#include "../CommandBase.h"

class DecWheelAngleCommand: public CommandBase {
	int mWheel;
public:
	DecWheelAngleCommand(int wheel){
		mWheel = wheel;
	}
	virtual ~DecWheelAngleCommand(){
		
	}
	virtual void Initialize(){
		driveTrain->SetWheelAngle(mWheel, (int)((driveTrain->GetWheelAngle(mWheel) - 5) + 360) % 360);
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

#endif /* DECWHEELANGLECOMMAND_H_ */
