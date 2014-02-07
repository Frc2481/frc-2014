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
public:
	TurnOffIntakeCommand(){
		Requires(intake);
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		intake->SetCaptureSolenoid(false);
		intake->RollerOff();
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
		
	}
	virtual void Interrupted(){
		
	}
};

#endif
