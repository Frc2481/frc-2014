#ifndef VARIABLEINTAKECOMMAND_H
#define VARIABLEINTAKECOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"
/*
 *
 *  Author: paulRich, thomasSpeciale
 */
class VariableIntakeCommand :  public CommandBase {
private:
	float tgtSpeed;
public:
	VariableIntakeCommand(float speed) {
		Requires(intake);
		tgtSpeed = speed;
	}
	virtual void Initialize(){
		if(shooter->IsLatched()) {
			printf("turn on Intake \n");
			intake->SetCaptureSolenoid(true);
			intake->SetRollerSpeed(tgtSpeed);	
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
