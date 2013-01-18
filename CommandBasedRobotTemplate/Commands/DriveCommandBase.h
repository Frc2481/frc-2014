#ifndef DRIVE_COMMAND_BASE_H
#define DRIVE_COMMAND_BASE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class DriveCommandBase: public CommandBase {
protected:
	float driveSpeed;
	double timeout;
public:
	DriveCommandBase(float speed, double time) {
		Requires(driveTrain);
		driveSpeed = speed;
		timeout = time;
	}
	virtual void Initialize() {
		SetTimeout(timeout);
	}
	virtual bool IsFinished() {
		return IsTimedOut();
	}
	virtual void End();
	virtual void Interrupted();
};

#endif
