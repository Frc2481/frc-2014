

#include "DeadmanCommand.h"


DeadmanCommand::DeadmanCommand(const char *name) : CommandBase(name){
	commandName = name;
	interrupted = false;
}

DeadmanCommand::~DeadmanCommand(){}
	
void DeadmanCommand::Execute(){
	if(oi->GetDeadMan1() && oi->GetDeadMan2()){
		printf("Deadman Command Name - Execute %s \n", commandName);
		interrupted = false;
		DeadmanExecute();
	}
	else if (!interrupted) {
		interrupted = true;
		DeadmanInterrupt();
		printf("Deadman Command Name - Interupt %s \n", commandName);
	}
}
void DeadmanCommand::Initialize(){}
void DeadmanCommand::End(){}
void DeadmanCommand::Interrupted(){}
