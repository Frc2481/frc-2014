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
//CalibrateDriveTrain* CommandBase::driveTrain = NULL;
//PersistedSettings* CommandBase::persistedSettings = NULL;
OI* CommandBase::oi = NULL;
Shooter* CommandBase::shooter = NULL;
DistanceSensors *CommandBase::distanceSensors = NULL;
Intake *CommandBase::intake = NULL;
AirCompressor *CommandBase::compressor = NULL;
Camera2481 *CommandBase::camera = NULL;
Lights *CommandBase::lights = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
//	persistedSettings = &PersistedSettings::GetInstance();
	printf("commandBaseInit \n");
	driveTrain = new DriveTrain();
	//driveTrain = new CalibrateDriveTrain();
	if(driveTrain){
		printf("driveTrain \n");
	}
	driveTrain->SetLengthAndWidth(ROBOTLENGTH, ROBOTWIDTH);
	shooter = new Shooter(WINCH, WINCH_SENSOR, EAR_LEFT, EAR_RIGHT, RELEASE, POT_SWITCH);
	if(shooter){
		printf("shooter \n");
	}
	distanceSensors = new DistanceSensors(ULTRASONIC_RIGHT);
	if(distanceSensors){
		printf("distanceSensors \n");
	}
	intake = new Intake();
	if(intake){
		printf("intake \n");
	}
	lights = new Lights(LIGHTS_A, LIGHTS_B, LIGHTS_C, LIGHTS_D);
	if(lights){
		printf("lights \n");
	}
	camera = new Camera2481();
	compressor = new AirCompressor(COMPRESSOR_SENSOR, COMPRESSOR_SPIKE_CHANNEL);
	oi = new OI();
	if(oi){
		printf("oi \n");
	}
}
