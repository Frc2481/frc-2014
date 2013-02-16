/*
 * DeadmanTestCommandGroup.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Team2481
 */

#ifndef DEADMANTESTCOMMANDGROUP_H_
#define DEADMANTESTCOMMANDGROUP_H_

#include "WPILib.h"
#include "FullyExtendArmCommand.h"
#include "FullyRetractArmCommand.h"
#include "LatchCommand.h"
#include "UnlatchCommand.h"
#include "SafeUnlatchCommand.h"
#include "FirstRungPositionArmCommand.h"

class DeadmanTestCommandGroup: public CommandGroup {
public:
	DeadmanTestCommandGroup(){
		AddSequential(new TiltArmBackwardCommand());
		AddSequential(new WaitCommand(5));
		AddSequential(new LatchCommand());
		AddSequential(new WaitCommand(5));
		AddSequential(new UnlatchCommand());
		AddSequential(new WaitCommand(5));
		AddSequential(new SafeUnlatchCommand());
			
	}
	virtual ~DeadmanTestCommandGroup(){}
};

#endif /* DEADMANTESTCOMMANDGROUP_H_ */
