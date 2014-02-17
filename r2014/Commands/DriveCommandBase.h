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
	DriveCommandBase(float speed, double time, const char *name);
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
