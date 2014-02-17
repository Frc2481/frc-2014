#ifndef SETFORWARDCOMMAND_H
#define SETFORWARDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class SetForwardCommand : public CommandBase {
private:
	bool forward;
public:
	SetForwardCommand(bool fwd){
		forward = fwd;
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		driveTrain->SetForward(forward);
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
