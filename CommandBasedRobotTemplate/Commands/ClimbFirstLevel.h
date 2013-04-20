/*
 * ClimbFirstLevel.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef CLIMBFIRSTLEVEL_H_
#define CLIMBFIRSTLEVEL_H_

#include "WPILib.h"
#include "FullyExtendArmCommand.h"
#include "FullyRetractArmCommand.h"
#include "LatchCommand.h"
#include "UnlatchCommand.h"
#include "SafeUnlatchCommand.h"
#include "FirstRungPositionArmCommand.h"
#include "SetLightsCommand.h"

class ClimbFirstLevel: public CommandGroup {
public:
	ClimbFirstLevel() : CommandGroup(){
	//purple
	AddParallel(new SetLightsCommand(0,1,1));
	
	AddSequential(new TiltArmBackwardCommand());
	AddSequential(new UnlatchCommand());
	AddSequential(new FirstRungArmPositionCommand());
	AddParallel(new LiftRobotCommand());
	//red
	AddParallel(new SetLightsCommand(1,0,0));
	
	AddSequential(new ClimbStepCommand());
	//white
	AddParallel(new SetLightsCommand(1,1,1));
	
	AddSequential(new FullyRetractArmPositionCommand());
	AddParallel(new LatchCommand());
	AddSequential(new LowerRobotCommand());
	//red
	AddParallel(new SetLightsCommand(1,0,0));
	
	AddSequential(new ClimbStepCommand());
	}
	virtual ~ClimbFirstLevel() {}
};

#endif /* CLIMBFIRSTLEVEL_H_ */
