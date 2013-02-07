#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Robotmap.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;
Shooter* CommandBase::shooter = NULL;
Hopper* CommandBase::hopper = NULL;
AirCompressor* CommandBase::airCompressor = NULL;
Arm* CommandBase::climbingArm = NULL;
ClimbingHooks* CommandBase::climbingHooks = NULL;
RobotLift* CommandBase::robotLift = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveTrain = new DriveTrain(LEFT_DRIVE_MOTOR, RIGHT_DRIVE_MOTOR,
								LEFT_DRIVE_ENCODER_A, LEFT_DRIVE_ENCODER_B, RIGHT_DRIVE_ENCODER_A, RIGHT_DRIVE_ENCODER_B,
								LEFT_DRIVE_SOLENOID);
	driveTrain->SetRightDriveAxis(XboxController::xbRightYAxis);
	driveTrain->SetLeftDriveAxis(XboxController::xbLeftYAxis); 
	driveTrain->SetFPSTurnAxis(XboxController::xbRightXAxis);
	
	shooter = new Shooter(SHOOTER_MOTOR, SHOOTER_ENCODER, SHOOTER_LIFT_SOLENOID);
	hopper = new Hopper(HOPPER_SOLENOID);
	airCompressor = new AirCompressor(COMPRESSOR_SENSOR, COMPRESSOR_SPIKE);
	climbingArm = new Arm(ARM_LIFT_MOTOR, ROBOT_LIFT_MOTOR, UPPER_ARM_SENSOR, LOWER_ARM_SENSOR, ARM_EXTENSION_SENSOR);
	climbingHooks = new ClimbingHooks(LOCK_HOOK_SOLENOID,UNLOCK_HOOK_SOLENOID, RIGHT_HOOK_MAGNET, LEFT_HOOK_MAGNET);
	robotLift = new RobotLift(ROBOT_LIFT_SOLENOID,LIFT_ROBOT_SENSOR);
	oi = new OI();
}
