#ifndef VARIABLEINTAKECOMMAND_H
#define VARIABLEINTAKECOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"
/*
 *
 *  Author: paulRich, thomasSpeciale
 */
class VariableIntakeCommand :  public CommandBase {
public:
	VariableIntakeCommand() {
		Requires(intake);
	}
	virtual void Initialize(){
		if(shooter->IsLatched()) {
			printf("turn on Intake \n");
			intake->SetCaptureSolenoid(true);
			intake->SetRollerSpeed(0.5);	
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
