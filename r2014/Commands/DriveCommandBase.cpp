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
}
void DriveCommandBase::Initialize() {
	SetTimeout(timeout);
}
 bool DriveCommandBase::IsFinished() {
	return IsTimedOut();
}
void DriveCommandBase::End(){
	driveTrain->Stop();
}
void DriveCommandBase::Interrupted(){}

