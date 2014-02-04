#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
DriveTrain* CommandBase::driveTrain = NULL;
//PersistedSettings* CommandBase::persistedSettings = NULL;
OI* CommandBase::oi = NULL;
Shooter* CommandBase::shooter = NULL;
DistanceSensors *CommandBase::distanceSensors = NULL;
//CSVRecord *CommandBase::csvRecord = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
//	persistedSettings = &PersistedSettings::GetInstance();
	driveTrain = new DriveTrain();
	driveTrain->SetLengthAndWidth(ROBOTLENGTH, ROBOTWIDTH);
	oi = new OI();
	shooter = new Shooter(WINCH, WINCH_SENSOR, EARS, RELEASE);
	distanceSensors = new DistanceSensors(ULTRASONIC_RIGHT, ULTRASONIC_LEFT);
	//csvRecord = new CSVRecord();
}
