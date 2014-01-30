/*
 * ResetGyroCommand.cpp
 *
 *  Created on: Jan 23, 2014
 *      Author: Team2481
 */

#include "ResetGyroCommand.h"

ResetGyroCommand::ResetGyroCommand() : CommandBase("ResetGyroCommand"){
	// TODO Auto-generated constructor stub

}

ResetGyroCommand::~ResetGyroCommand() {
	// TODO Auto-generated destructor stub
}
void ResetGyroCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ResetGyroCommand::Execute() {
	driveTrain->ResetGyro();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetGyroCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetGyroCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetGyroCommand::Interrupted() {
}
