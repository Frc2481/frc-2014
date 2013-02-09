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

class ClimbFirstLevel: public CommandGroup {
public:
	ClimbFirstLevel(){
	AddSequential(new UnlatchCommand());
	AddSequential(new FirstRungArmPositionCommand());
	
	//Lift and give time for the robot to lift before
	//climbing on to the first rung.
	AddParallel(new LiftRobotCommand());
	AddSequential(new WaitCommand(1.5));
	
	AddSequential(new FullyRetractArmPositionCommand());
	
	//Latch and give time for the hooks to latch
	//before continuing.
	AddParallel(new LatchCommand());
	AddSequential(new WaitCommand(.5));
	AddSequential(new LowerRobotCommand());
	}
	virtual ~ClimbFirstLevel();
};

#endif /* CLIMBFIRSTLEVEL_H_ */
