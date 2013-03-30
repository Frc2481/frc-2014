/*
 * ShooterToggleCommand.h
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#ifndef SHOOTERTOGGLECOMMAND_H_
#define SHOOTERTOGGLECOMMAND_H_

#include "../CommandBase.h"

class ShooterToggleCommand: public CommandBase {
public:
	ShooterToggleCommand() {	
	}
	~ShooterToggleCommand() {
	}
	virtual void Initialize(){
		if(shooter->isShooterOn()){
			shooter->turnOff();
			lights->setTop(1, 0, 0);
			airCompressor->Start();
		}
		else {
			shooter->turnOn();
			lights->setTop(1, 0, 1);
			airCompressor->Stop();
		}
	}
	virtual void Execute(){}
	virtual bool IsFinished() {
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* SHOOTERTOGGLECOMMAND_H_ */
