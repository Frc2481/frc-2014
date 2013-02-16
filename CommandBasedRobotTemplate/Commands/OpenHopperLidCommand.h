/*
 * OpenHopperLidCommand.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Team2481
 */

#ifndef OPENHOPPERLIDCOMMAND_H_
#define OPENHOPPERLIDCOMMAND_H_

#include "../CommandBase.h"

class OpenHopperLidCommand: public CommandBase {
public:
	OpenHopperLidCommand(){}
	virtual ~OpenHopperLidCommand(){}
	virtual void Initialize(){
		hopper->open();
	}
	virtual void Execute(){}
	virtual bool isFinished(){
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* OPENHOPPERLIDCOMMAND_H_ */
