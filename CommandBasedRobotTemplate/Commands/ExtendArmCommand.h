/*
 * ExtendArmCommand.h
 *
 *  Created on: Jan 28, 2013
 *      Author: Team2481
 */

#ifndef EXTENDARMCOMMAND_H_
#define EXTENDARMCOMMAND_H_

#include "../CommandBase.h"

class ExtendArmCommand: public CommandBase {
public:
	ExtendArmCommand() {
		//Requires(climbingArm);
	}
	virtual ~ExtendArmCommand() {
		
	}
	void Initialize() {
	}
	void Execute() {
		printf("Extend");
		//This needs to be in execute so limits are enforced.
		if (!shooter->isShooterUp()) {
			climbingArm->extendArm();
		}
		driftCorrectionEnabled = false;
	}
	bool IsFinished() {
		return false;
	}
	void End() {
		climbingArm->stopArm();
	}
	void Interrupted() {
		End();
	}
};

#endif /* EXTENDARMCOMMAND_H_ */
