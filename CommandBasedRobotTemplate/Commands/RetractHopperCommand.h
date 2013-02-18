/*
 * RetractHopperCommand.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Team2481
 */

#ifndef RETRACTHOPPERCOMMAND_H_
#define RETRACTHOPPERCOMMAND_H_

#include "../CommandBase.h"

class RetractHopperCommand: public CommandBase {
public:
	RetractHopperCommand(){
		Requires(hopper);
	}
	virtual ~RetractHopperCommand(){}
	void Initialize(){
		printf("RetractHopper \n");
		hopper->Retract();
	}
	virtual void Execute(){}
	bool IsFinished(){
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
	
};

#endif /* RETRACTHOPPERCOMMAND_H_ */
