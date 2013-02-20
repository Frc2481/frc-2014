/*
 * SetICommand.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Team2481
 */

#ifndef SETICOMMAND_H_
#define SETICOMMAND_H_

#include "../CommandBase.h"

class SetICommand: public CommandBase {
private:
	bool willRaise;
public:
	SetICommand(bool raise) {
		willRaise = raise;
	}
	virtual ~SetICommand() {
		
	}
	virtual void Initialize(){
		if (willRaise) {
			shooter->GetController()->SetPID(
					shooter->GetController()->GetP(), 
					shooter->GetController()->GetI() + .00001, 
					shooter->GetController()->GetD());
		}
		else {
			shooter->GetController()->SetPID(
					shooter->GetController()->GetP(), 
					shooter->GetController()->GetI() - .00001, 
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

#endif /* SETICOMMAND_H_ */
