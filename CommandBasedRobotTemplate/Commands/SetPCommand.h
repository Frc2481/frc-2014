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
	SetPCommand(bool raise) {
		willRaise = raise;
	}
	virtual ~SetPCommand() {
		
	}
	virtual void Initialize(){
		if (willRaise) {
			shooter->GetController()->SetPID(
					shooter->GetController()->GetP() + .0001, 
					shooter->GetController()->GetI(), 
					shooter->GetController()->GetD());
		}
		else {
			shooter->GetController()->SetPID(
					shooter->GetController()->GetP() - .0001, 
					shooter->GetController()->GetI(), 
					shooter->GetController()->GetD());
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
