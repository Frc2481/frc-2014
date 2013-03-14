#ifndef TURN_LEFT_COMMAND_H
#define TURN_LEFT_COMMAND_H

#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class TurnLeftCommand: public DriveCommandBase {
public:
	TurnLeftCommand(float speed, double time):DriveCommandBase(speed, time, "TurnLeftCommand") {
		
	}
	virtual void Execute() {
		driveTrain->TurnLeft(driveSpeed);
	}
};

#endif
