#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */

DriveCommandBase::DriveCommandBase(float speed, double time, const char *name):CommandBase(name) {
	Requires(driveTrain);
	driveSpeed = speed;
	timeout = time;
	SetTimeout(time);
}
void DriveCommandBase::Initialize() {
}
 bool DriveCommandBase::IsFinished() {
	 printf("isFinished %f %f\n", TimeSinceInitialized(), timeout);
	return TimeSinceInitialized() >= timeout;
}
void DriveCommandBase::End(){
	driveTrain->Crab(0,0,0);
}
void DriveCommandBase::Interrupted(){
	End();
}

