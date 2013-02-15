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

class ClimbOneLevel: public CommandGroup {
public:
	ClimbOneLevel() : CommandGroup(){
		AddSequential(new FullyExtendArmPositionCommand(1, true));
		AddParallel(new TiltArmForwardCommand(2, true));
		AddSequential(new WaitCommand(1));
		
		AddParallel(new SafeUnlatchCommand(4, true));
		
		AddSequential(new FullyRetractArmPositionCommand(4, true));
		AddParallel(new LatchCommand(5, true));
		AddSequential(new WaitCommand(.5));
		
	}
	virtual ~ClimbOneLevel(){}
};

#endif /* CLIMBONELEVEL_H_ */
