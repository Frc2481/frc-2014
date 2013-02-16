/*
 * CloseHopperLidCommand.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Team2481
 */

#ifndef CLOSEHOPPERLIDCOMMAND_H_
#define CLOSEHOPPERLIDCOMMAND_H_

#include "../CommandBase.h"

class CloseHopperLidCommand: public CommandBase {
public:
	CloseHopperLidCommand(){}
	virtual ~CloseHopperLidCommand(){}
	virtual void Initialize(){
		hopper->close();
	}
	virtual void Execute(){}
	bool isFinished(){
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* CLOSEHOPPERLIDCOMMAND_H_ */
