/*
 * ShooterOnCommand.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef SHOOTERONCOMMAND_H_
#define SHOOTERONCOMMAND_H_

#include "../CommandBase.h"

class ShooterOnCommand: public CommandBase {
public:
	ShooterOnCommand() {
		
	}
	virtual ~ShooterOnCommand() {
		
	}
	virtual void Initialize(){
		shooter->turnOn();
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* SHOOTERONCOMMAND_H_ */
