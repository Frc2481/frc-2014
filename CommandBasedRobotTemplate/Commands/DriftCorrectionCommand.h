/*
 * DriftCorrectionCommand.h
 *
 *  Created on: Apr 13, 2013
 *      Author: Team2481
 */

#ifndef DRIFTCORRECTIONCOMMAND_H_
#define DRIFTCORRECTIONCOMMAND_H_

#include "../CommandBase.h"

class DriftCorrectionCommand: public CommandBase {
private:
	bool autoCorrectingDrift;
public:
	DriftCorrectionCommand(){
		autoCorrectingDrift = false;
	}
	virtual ~DriftCorrectionCommand(){}
	void Initialize(){}
	void Execute(){
		if (driftCorrectionEnabled){
			if (climbingArm->getCurrentPosition() > ARM_IN_LIMIT + 0.3){
				printf("Fall detected\n");
				autoCorrectingDrift = true;
				climbingArm->setPosition(ARM_IN_LIMIT);
				climbingHooks->unlatch();
			}
			if(autoCorrectingDrift){
				climbingArm->run();
				if (climbingArm->isAtPosition()){
					printf("Auto Latching in fall detect\n");
					climbingHooks->latch();
					autoCorrectingDrift = false;
				}
			}
		}
		else {
			autoCorrectingDrift = false;
		}
		
	}
	bool IsFinished(){
		return false;
	}
	void End(){}
	void Interrupted(){}
};

#endif /* DRIFTCORRECTIONCOMMAND_H_ */
