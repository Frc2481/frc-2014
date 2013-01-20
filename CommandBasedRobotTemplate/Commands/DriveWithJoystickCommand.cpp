#include "DriveWithJoystickCommand.h"

DriveWithJoystickCommand::DriveWithJoystickCommand() : CommandBase("DriveWithJoyStick") {
	// Use Requires() here to declare subsystem dependencies
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void DriveWithJoystickCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystickCommand::Execute() {
	driveTrain->DriveWithJoystick(oi->GetDriverStick());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystickCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystickCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystickCommand::Interrupted() {
}
