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

class ClimbOneLevel: public CommandGroup {
public:
	ClimbOneLevel() : CommandGroup(){
		AddSequential(new FullyExtendArmPositionCommand());
		AddSequential(new TiltArmForwardCommand());
		AddSequential(new HighRungArmPositionCommand());
		AddSequential(new ClimbStepCommand);
		
		AddParallel(new SafeUnlatchCommand());
		
		AddSequential(new FullyRetractArmPositionCommand());
		AddParallel(new LatchCommand());
		AddSequential(new ClimbStepCommand());
		
	}
	virtual ~ClimbOneLevel(){}
};

#endif /* CLIMBONELEVEL_H_ */
