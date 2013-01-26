/*
 * ClimbingCommandGroup.h
 *
 *  Created on: Jan 26, 2013
 *      Author: Team2481
 */

#ifndef CLIMBINGCOMMANDGROUP_H_
#define CLIMBINGCOMMANDGROUP_H_

#include "WPILib.h"
#include "FirstRungPositionArmCommand.h"
#include "FullyExtendArmCommand.h"
#include "FullyRetractArmCommand.h"
#include "LatchCommand.h"
#include "UnlatchCommand.h"
#include "LiftRobotCommand.h"
#include "LowerRobotCommand.h"

class ClimbingCommandGroup: public CommandGroup {
public:
	ClimbingCommandGroup() {
		AddSequential(new FirstRungArmPositionCommand());
		AddSequential(new LiftRobotCommand());
		AddSequential(new LatchCommand());
		AddSequential(new LowerRobotCommand());
		AddSequential(new FullyExtendArmPositionCommand());
		AddSequential(new UnlatchCommand());
		AddSequential(new FullyRetractArmPositionCommand());
		AddSequential(new LatchCommand());
		AddSequential(new FullyExtendArmPositionCommand());
		AddSequential(new UnlatchCommand());
		AddSequential(new FullyRetractArmPositionCommand());
		AddSequential(new LatchCommand());
		//Shoot
		//spin up motor in parallel?
	}
	~ClimbingCommandGroup() {
		
	}
	void Execute() {
		
	}
};

#endif /* CLIMBINGCOMMANDGROUP_H_ */
