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
		Requires(climbingArm);
	}
	virtual ~ExtendArmCommand() {
		
	}
	void Initialize() {
		climbingArm->extendArm();
	}
	void Execute() {
	}
	bool IsFinished() {
		return false;
	}
	void End() {
		climbingArm->stopArm();
	}
	void Interrupted() {
		climbingArm->stopArm();
	}
};

#endif /* EXTENDARMCOMMAND_H_ */
