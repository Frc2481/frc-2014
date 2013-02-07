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
	float leftDistance;
	float rightDistance;
public:
	DriveCommandBase(float speed, float leftDistance, float rightDistance, const char *name);
	virtual void Initialize();
	void DriveCommandBase::Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
