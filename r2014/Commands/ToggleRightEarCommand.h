#ifndef TOGGLERIGHTEARCOMMAND_H
#define TOGGLERIGHTEARCOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"

/**
 *
 *
 * @author paulRich, thomasSpeciale
 */
class ToggleRightEarCommand: public CommandBase {
public:
	ToggleRightEarCommand(){
		//Requires(intake);
	}
	virtual void Initialize(){
		shooter->SetRightEar(!shooter->GetRightEar());
		
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
