#include "JukeCommand.h"

JukeCommand::JukeCommand(bool jukeRight){
	Requires (driveTrain);
	isRight = jukeRight;
}
	void JukeCommand::Initialize(){
		
	}
	void JukeCommand::Execute(){
		if (isRight == true){
				driveTrain->Crab(0,-1,-1);
		}
		else if (isRight == false){
				driveTrain->Crab(0,-1,1);
		}
	}

	bool JukeCommand::IsFinished(){
		if (fabs(oi->GetDriverStick()->GetRawAxis(XboxController::xbLeftXAxis)) > .2 ||
			fabs(oi->GetDriverStick()->GetRawAxis(XboxController::xbLeftYAxis)) > .2){
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
