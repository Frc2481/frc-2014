#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/DistanceSensors.h"
#include "Subsystems/Intake.h"
#include "Subsystems/AirCompressor.h"
#include "Subsystems/Camera2481.h"
#include "OI.h"
#include "PersistedSettings.h"
#include "Robotmap.h"
#include "CSVRecord.h"
#include "Subsystems/CalibrateDriveTrain.h"
#include "Subsystems/Lights.h"


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
	static ExampleSubsystem *examplesubsystem;
	static DriveTrain *driveTrain;
	//static CalibrateDriveTrain *driveTrain;
	static OI *oi;
//	static PersistedSettings *persistedSettings;
	static Shooter *shooter;
	static DistanceSensors *distanceSensors;
	static Intake *intake;
	static AirCompressor *compressor;
	static Camera2481 *camera;
	static Lights *lights;
};

#endif
