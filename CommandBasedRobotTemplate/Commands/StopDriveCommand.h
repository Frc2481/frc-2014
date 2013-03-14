#ifndef STOP_DRIVE_COMMAND_H
#define STOP_DRIVE_COMMAND_H

#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class StopDriveCommand: public DriveCommandBase {
public:
	StopDriveCommand():DriveCommandBase(0, 0, "StopDriveCommand") {
		
	}
	virtual void Execute() {
		driveTrain->Stop();
	}
};

#endif
