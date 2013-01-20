#ifndef DRIVE_FORWARD_COMMAND_H
#define DRIVE_FORWARD_COMMAND_H

#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class DriveForwardCommand: public DriveCommandBase {
public:
	DriveForwardCommand(float speed, double time):DriveCommandBase(speed, time, "driveForwardCommand") {
		
	}
	virtual void Execute() {
		driveTrain->DriveForward(driveSpeed);
	}
};

#endif
