#ifndef TURNONINTAKECOMMAND_H
#define TURNONINTAKECOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"
/*
 *
 *  Author: paulRich, thomasSpeciale
 */
class TurnOnIntakeCommand :  public CommandBase {
public:
	TurnOnIntakeCommand() {
		Requires(intake);
	}
	virtual void Initialize(){}
	virtual void Execute(){
		intake->SetCaptureSolenoid(true);
		intake->RollerOn();	
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
		
	}
	virtual void Interrupted() {
		End();
	}
};

#endif
