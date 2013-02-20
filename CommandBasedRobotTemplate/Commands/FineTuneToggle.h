/*
 * FineTuneToggle.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Team2481
 */

#ifndef FINETUNETOGGLE_H_
#define FINETUNETOGGLE_H_

#include "../CommandBase.h"

class FineTuneToggle: public CommandBase {
public:
	FineTuneToggle() {
		
	}
	virtual ~FineTuneToggle() {
		
	}
	virtual void Initialize(){
		driveTrain->SetFineTuned(true);
	}
	virtual void Execute(){}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		driveTrain->SetFineTuned(false);
	}
};

#endif /* FINETUNETOGGLE_H_ */
