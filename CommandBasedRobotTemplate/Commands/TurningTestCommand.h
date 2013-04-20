/*
 * TurningTestCommand.h
 *
 *  Created on: Apr 20, 2013
 *      Author: Team2481
 */

#ifndef TURNINGTESTCOMMAND_H_
#define TURNINGTESTCOMMAND_H_

#include "../CommandBase.h"
#include "TurnLeftCommand.h"

class TurningTestCommand: public DriveCommandBase {
public:
	TurningTestCommand() : DriveCommandBase(1, 0.3, "TestTurnCommand"){}
	virtual void Execute() {
		driveTrain->TurnLeft(driveSpeed);
	}
};

#endif /* TURNINGTESTCOMMAND_H_ */
