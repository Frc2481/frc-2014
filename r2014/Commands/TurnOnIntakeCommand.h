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
	virtual void Initialize(){
		if(shooter->IsLatched()) {
			printf("turn on Intake \n");
			intake->SetReadySolenoid(true);
			intake->SetCaptureSolenoid(true);
			intake->RollerOn();	
			shooter->SetLeftEar(1);
			shooter->SetRightEar(1);
		}
	}
	virtual void Execute(){
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
