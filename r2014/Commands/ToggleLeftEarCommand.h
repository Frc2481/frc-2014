#ifndef TOGGLELEFTEARCOMMAND_H
#define TOGGLELEFTEARCOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"

/**
 *
 *
 * @author paulRich, thomasSpeciale
 */
class ToggleLeftEarCommand: public CommandBase {
public:
	ToggleLeftEarCommand(){
		//Requires(intake);
	}
	virtual void Initialize(){
		shooter->SetLeftEar(!shooter->GetLeftEar());
		
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
