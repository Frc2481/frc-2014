#include "DisableShiftCommand.h"

DisableShiftCommand::DisableShiftCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DisableShiftCommand::Initialize() {
	driveTrain->SetShiftEnabled(false);
}

// Called repeatedly when this Command is scheduled to run
void DisableShiftCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool DisableShiftCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DisableShiftCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DisableShiftCommand::Interrupted() {
	driveTrain->SetShiftEnabled(true);
}
