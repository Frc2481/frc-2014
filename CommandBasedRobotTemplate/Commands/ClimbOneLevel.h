/*
 * ClimbOneLevel.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef CLIMBONELEVEL_H_
#define CLIMBONELEVEL_H_

#include "WPILib.h"
#include "FullyExtendArmCommand.h"
#include "FullyRetractArmCommand.h"
#include "LatchCommand.h"
#include "UnlatchCommand.h"
#include "SafeUnlatchCommand.h"
#include "TiltArmBackwardCommand.h"
#include "TiltArmForwardCommand.h"
#include "ClimbStepCommand.h"
#include "HighRungArmPositionCommand.h"
#include "SetLightsCommand.h"

class ClimbOneLevel: public CommandGroup {
public:
	ClimbOneLevel() : CommandGroup(){
		//yellow
		AddParallel(new SetLightsCommand(1,1,0));
		
		AddSequential(new FullyExtendArmPositionCommand());
		AddSequential(new TiltArmForwardCommand());
		AddSequential(new HighRungArmPositionCommand());
		//red
		AddParallel(new SetLightsCommand(1,0,0));
		
		AddSequential(new ClimbStepCommand);
		//teal
		AddParallel(new SetLightsCommand(0,1,1));
		
		AddParallel(new SafeUnlatchCommand());
		AddSequential(new FullyRetractArmPositionCommand());
		AddParallel(new LatchCommand());
		//red
		AddParallel(new SetLightsCommand(1,0,0));
		
		AddSequential(new ClimbStepCommand());
		
	}
	virtual ~ClimbOneLevel(){}
};

#endif /* CLIMBONELEVEL_H_ */
