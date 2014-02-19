#ifndef TURNOFFINTAKECOMMAND_H
#define TURNOFFINTAKECOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"

/**
 *
 *
 * @author paulRich, thomasSpeciale
 */
class TurnOffIntakeCommand: public CommandBase {
private:
	bool auton;
	int count;
public:
	TurnOffIntakeCommand(bool autonomous = false){
		Requires(intake);
		count = 0;
		auton = autonomous;
	}
	virtual void Initialize(){
		intake->SetCaptureSolenoid(false);
		if(intake->GetPosition()){
			intake->RollerOn();
		}
		count = 0;
	}
	virtual void Execute(){
		count++;
	}
	virtual bool IsFinished(){
		if (TimeSinceInitialized() > 1.5 || (TimeSinceInitialized() > .75 && auton)) {
			intake->RollerOff();
			if(!shooter->HasSetPosition()){
				shooter->SetLeftEar(0);
				shooter->SetRightEar(0);
			}
			return true;
		}
		return false;
	}
	virtual void End(){
		
	}
	virtual void Interrupted(){
		
	}
};

#endif
