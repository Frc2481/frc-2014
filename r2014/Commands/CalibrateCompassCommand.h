/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef CALIBRATECOMPASS_H_
#define CALIBRATECOMPASS_H_

#include "../CommandBase.h"

class CalibrateCompassCommand: public CommandBase {
public:
	CalibrateCompassCommand(){
		
	}
	virtual ~CalibrateCompassCommand(){
		
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		driveTrain->UpdateCompass(false);
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		driveTrain->UpdateCompass(true);
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
