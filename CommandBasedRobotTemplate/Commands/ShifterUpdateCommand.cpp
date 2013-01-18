#include "ShifterUpdateCommand.h"

ShifterUpdateCommand::ShifterUpdateCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShifterUpdateCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShifterUpdateCommand::Execute() {
	driveTrain->Periodic();
}

// Make this return true when this Command no longer needs to run execute()
bool ShifterUpdateCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShifterUpdateCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShifterUpdateCommand::Interrupted() {
	
}
