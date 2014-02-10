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
		intake->RollerOn();
	}
	virtual void Execute(){
		count++;
	}
	virtual bool IsFinished(){
		if (count > 50) {
			intake->RollerOff();
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
