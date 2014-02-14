/*
 * CrabDriveCommand.cpp
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#include "CrabDriveCommand.h"

CrabDriveCommand::CrabDriveCommand() {
	// TODO Auto-generated constructor stub
	Requires(driveTrain);
}

CrabDriveCommand::~CrabDriveCommand() {
	// TODO Auto-generated destructor stub
}

// Called just before this Command runs the first time
void CrabDriveCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void CrabDriveCommand::Execute() {
	
	driveTrain->Crab(oi->GetDriverStick()->GetRawAxis(XboxController::xbLeftXAxis), 
			-oi->GetDriverStick()->GetRawAxis(XboxController::xbLeftYAxis), 
			oi->GetDriverStick()->GetRawAxis(XboxController::xbRightXAxis));
}

// Make this return true when this Command no longer needs to run execute()
bool CrabDriveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CrabDriveCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrabDriveCommand::Interrupted() {
	
}

