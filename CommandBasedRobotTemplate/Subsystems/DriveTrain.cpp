#include "DriveTrain.h"
#include "../Robotmap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	drive = new RobotDrive(2, 1);
	drive->SetSafetyEnabled(false);
}

void InitDefaultCommand() {
	 setDefaultCommand(new DriveWithJoystick);
}
