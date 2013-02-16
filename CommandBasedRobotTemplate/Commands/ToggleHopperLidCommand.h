/*
 * ToggleHopperLidCommand.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Team2481
 */

#ifndef TOGGLEHOPPERLIDCOMMAND_H_
#define TOGGLEHOPPERLIDCOMMAND_H_

#include "../CommandBase.h"

class ToggleHopperLidCommand: public CommandBase {
public:
	ToggleHopperLidCommand(){}
	virtual ~ToggleHopperLidCommand(){}
	virtual void Initialize(){
		if (hopper->isOpen()){
			hopper->close();
		}
		else {
			hopper->open();
		}
	}
	virtual void Execute(){}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* TOGGLEHOPPERLIDCOMMAND_H_ */
