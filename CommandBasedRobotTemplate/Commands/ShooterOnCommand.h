/*
 * ShooterOffCommand.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef SHOOTEROFFCOMMAND_H_
#define SHOOTEROFFCOMMAND_H_

#include "../CommandBase.h"

class ShooterOffCommand: public CommandBase {
public:
	ShooterOffCommand() {
		
	}
	virtual ~ShooterOffCommand() {
		
	}
	virtual void Initialize(){
		shooter->turnOff();
		airCompressor->Start();
		lights->setTop(1, 0, 1);
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* SHOOTEROFFCOMMAND_H_ */
