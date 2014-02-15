#ifndef TOGGLEFORWARDCOMMAND_H
#define TOGGLEFORWARDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToggleForwardCommand : public CommandBase {
public:
	ToggleForwardCommand(){
		
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		driveTrain->ToggleForward();
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
		
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
