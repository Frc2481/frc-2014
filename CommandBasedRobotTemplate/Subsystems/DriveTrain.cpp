#include "DriveTrain.h"
#include "../Commands/DriveWithJoystickCommand.h"
#include "../Robotmap.h"

DriveTrain::DriveTrain(UINT32 motorL, UINT32 motorR, 
					   UINT32 encoderLA, UINT32 encoderLB, UINT32 encoderRA, UINT32 encoderRB, 
					   UINT32 solenoidL, UINT32 solenoidR) 
: Subsystem("DriveTrain") {
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystickCommand());
}
