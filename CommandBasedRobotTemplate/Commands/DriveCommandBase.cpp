#include "DriveCommandBase.h"

/**
 *
 *
 * @author jacobM
 */

DriveCommandBase::DriveCommandBase(float speed, float distanceL, float distanceR, const char *name):CommandBase(name) {
	Requires(driveTrain);
	driveSpeed = speed;
	leftDistance = distanceL;
	rightDistance = distanceR;
}
void DriveCommandBase::Initialize() {
	driveTrain->SetPID(leftDistance, rightDistance);
	
}
void DriveCommandBase::Execute() {}
bool DriveCommandBase::IsFinished() {
	return driveTrain->IsPIDAtDistance();
}
void DriveCommandBase::End(){
	driveTrain->Stop();
}
void DriveCommandBase::Interrupted(){}

