#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Shooter.h"
#include "OI.h"
#include "Subsystems/Hopper.h"
#include "Subsystems/AirCompressor.h"
#include "Subsystems/ClimbingHooks.h"
#include "Subsystems/Arm.h"
#include "Subsystems/RobotLift.h"
#include "Subsystems/Lights.h"
#include "RobotParameters.h"
#include "Subsystems/TipSensor.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveTrain *driveTrain;
	static OI *oi;
	static Shooter *shooter;
	static Hopper *hopper;
	static AirCompressor *airCompressor;
	static ClimbingHooks *climbingHooks;
	static Arm *climbingArm;
	static RobotLift *robotLift;
	static Lights *lights;
	static TipSensor *tipSensor;
	static bool tipCorrectionEnabled;
};

#endif
