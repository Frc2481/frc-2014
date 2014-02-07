#include "JukeCommand.h"

JukeCommand::JukeCommand(bool jukeRight){
	Requires (driveTrain);
	isRight = jukeRight;
}
	void JukeCommand::Initialize(){
		
	}
	void JukeCommand::Execute(){
		if (isRight == true){
			if (TimeSinceInitialized() < .25){
				driveTrain->Crab(1,0,0,false);
			}
			else if (TimeSinceInitialized() < .75){
				driveTrain->Crab(-1,0,0,false);
			}
			else if (TimeSinceInitialized() < 1.75){
				driveTrain->Crab(-.25,1,-.5,false);
			}	
			else if (TimeSinceInitialized() < .25){
				driveTrain->Crab(-1,0,0,false);
			}
			else if (TimeSinceInitialized() < .75){
				driveTrain->Crab(1,0,0,false);
			}
			else if (TimeSinceInitialized() < 1.75){
				driveTrain->Crab(.25,1,.5,false);
			}
		}
	}
	bool JukeCommand::IsFinished(){
		if (TimeSinceInitialized() > 2.25){
			return true;
		}
		return false;
	}
	void JukeCommand::End(){
		driveTrain->Stop();
	}
	void JukeCommand::Interrupted(){
		
	}


JukeCommand::~JukeCommand()
{
}
