/*
 * FireDiscCommandGroup.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Team2481
 */

#ifndef FIREDISCCOMMANDGROUP_H_
#define FIREDISCCOMMANDGROUP_H_

#include "WPILib.h"
#include "LoadHopperCommand.h"
#include "RetractHopperCommand.h"

class FireDiscCommandGroup: public CommandGroup {
public:
	FireDiscCommandGroup(){
		SetInterruptible(false);
		AddSequential(new LoadHopperCommand());
		AddSequential(new WaitCommand(HOPPER_EXTEND_TIME));
		AddSequential(new RetractHopperCommand());
		AddSequential(new WaitCommand(HOPPER_LOCKOUT_TIME));
	}
	virtual ~FireDiscCommandGroup(){}
};

#endif /* FIREDISCCOMMANDGROUP_H_ */
