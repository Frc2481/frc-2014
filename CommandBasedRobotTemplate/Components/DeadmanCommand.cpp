

#include "DeadmanCommand.h"


DeadmanCommand::DeadmanCommand(const char *name) : CommandBase(name){
	firstRun = true;
	commandName = name;
}

DeadmanCommand::~DeadmanCommand(){}
	
void DeadmanCommand::Execute(){
	if(oi->GetDeadMan1() && oi->GetDeadMan2()){
		//if(firstRun) 
			printf("Deadman Command Name - Execute %s \n", commandName);
		
		firstRun = false;
		DeadmanExecute();
	}
	else{
		DeadmanInterrupt();
		printf("Deadman Command Name - Interupt %s \n", commandName);
	}
}
void DeadmanCommand::Initialize(){}
void DeadmanCommand::End(){}
void DeadmanCommand::Interrupted(){}
