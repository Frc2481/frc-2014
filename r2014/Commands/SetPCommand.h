/*
 * SetPCommand.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Team2481
 */

#ifndef SETPCOMMAND_H_
#define SETPCOMMAND_H_

#include "../CommandBase.h"

class SetPCommand: public CommandBase {
private:
	bool willRaise;
public:
	SetPCommand(bool raise, Subsystem subsystem) {
		willRaise = raise;
	}
	virtual ~SetPCommand() {
		
	}
	virtual void Initialize(){
		if (willRaise) {
			subsystem->GetController()->SetPID(
					subsystem->GetController()->GetP() + .0001, 
					subsystem->GetController()->GetI(), 
					subsystem->GetController()->GetD());
		}
		else {
			subsystem->GetController()->SetPID(
					subsystem->GetController()->GetP() - .0001, 
					subsystem->GetController()->GetI(), 
					subsystem->GetController()->GetD());
		}
	}
	virtual void Execute(){}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
	
};

#endif /* SETPCOMMAND_H_ */
