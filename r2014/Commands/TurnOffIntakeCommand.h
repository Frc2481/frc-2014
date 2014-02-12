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
	int count;
public:
	TurnOffIntakeCommand(){
		Requires(intake);
		count = 0;
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
		if (TimeSinceInitialized() > 1.5) {
			intake->RollerOff();
			shooter->SetLeftEar(0);
			shooter->SetRightEar(0);
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
