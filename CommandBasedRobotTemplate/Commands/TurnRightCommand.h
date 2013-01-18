#ifndef TURN_RIGHT_COMMAND_H
#define TURN_RIGHT_COMMAND_H

#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class TurnRightCommand: public DriveCommandBase {
public:
	TurnRightCommand(float speed, double time):DriveCommandBase(speed, time) {
		
	}
	virtual void Execute() {
		driveTrain->TurnRight(driveSpeed);
	}
};

#endif
