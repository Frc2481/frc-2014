#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Scheduler.h"
#include "cRIOIOMap.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveTrain = new DriveTrain(LEFT_DRIVE_MOTOR, RIGHT_DRIVE_MOTOR,
								LEFT_DRIVE_ENCODER_A, LEFT_DRIVE_ENCODER_B, RIGHT_DRIVE_ENCODER_A, RIGHT_DRIVE_ENCODER_B,
								LEFT_DRIVE_SOLENOID, RIGHT_DRIVE_SOLENOID);
	
	oi = new OI();
}
