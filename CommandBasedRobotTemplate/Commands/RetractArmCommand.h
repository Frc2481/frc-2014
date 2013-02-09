/*
 * RetractArmCommand.h
 *
 *  Created on: Jan 28, 2013
 *      Author: Team2481
 */

#ifndef RETRACTARMCOMMAND_H_
#define RETRACTARMCOMMAND_H_

#include "../CommandBase.h"

class RetractArmCommand: public CommandBase {
public:
	RetractArmCommand() : CommandBase("RetractArmCommand"){
		Requires(climbingArm);
	}
	virtual ~RetractArmCommand() {
		
	}
	void Initialize() {}
	void Execute() {
		//This needs to be in execute so limits are enforced.
		climbingArm->retractArm();
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

#endif /* RETRACTARMCOMMAND_H_ */
