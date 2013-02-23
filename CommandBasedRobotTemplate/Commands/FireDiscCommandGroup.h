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
#include "FireDiscInstantCommand.h"
#include "FireInterruptedCommand.h"

class FireDiscCommandGroup: public CommandGroup {
public:
	FireDiscCommandGroup(){
		AddSequential(new FireDiscInstantCommand());
		AddSequential(new FireInterruptedCommand());
	}
	virtual ~FireDiscCommandGroup(){}
};

#endif /* FIREDISCCOMMANDGROUP_H_ */
