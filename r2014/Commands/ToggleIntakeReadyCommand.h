#ifndef TOGGLEINTAKEREADYCOMMAND_H
#define TOGGLEINTAKEREADYCOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"

/**
 *
 *
 * @author paulRich, thomasSpeciale
 */
class ToggleIntakeReadyCommand: public CommandBase {
public:
	ToggleIntakeReadyCommand(){

	}
	virtual void Initialize(){
		intake->SetReadySolenoid(!intake->GetReadySolenoid());
	}
	virtual void Execute(){
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
