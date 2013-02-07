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
	TurnRightCommand(float speed, float distance):DriveCommandBase(speed, distance, -distance, "TurnRightCommand") {
		
	}
	virtual void Execute() {
		driveTrain->TurnRight(driveSpeed);
	}
};

#endif
