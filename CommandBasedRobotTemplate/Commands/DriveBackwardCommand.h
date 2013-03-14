#ifndef DRIVE_BACKWARD_COMMAND_H
#define DRIVE_BACKWARD_COMMAND_H

#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class DriveBackwardCommand: public DriveCommandBase {
public:
	DriveBackwardCommand(float speed, double time):DriveCommandBase(speed, time, "DriveBackwardCommadn") {
		
	}
	virtual void Execute() {
		driveTrain->DriveBackward(driveSpeed);
	}
};

#endif
