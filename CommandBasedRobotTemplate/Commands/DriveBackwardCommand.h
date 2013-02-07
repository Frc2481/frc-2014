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
	DriveBackwardCommand(float speed, float distance):DriveCommandBase(speed, -distance, -distance, "DriveBackwardCommadn") {
		
	}
};

#endif
