/*
 * PickUpBallCommand.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Team2481
 */

#ifndef PICKUPBALLCOMMAND_H_
#define PICKUPBALLCOMMAND_H_

#include "WPILib.h"
#include "TurnOnIntakeCommand.h"
#include "WaitForBallCommand.h"
#include "TurnOffIntakeCommand.h"



class PickUpBallCommand: public CommandGroup {
public:
	PickUpBallCommand() : CommandGroup(){
		AddSequential(new TurnOnIntakeCommand());
		AddSequential(new WaitForBallCommand());
		AddSequential(new TurnOffIntakeCommand());
	}
	virtual ~PickUpBallCommand() {}
};

#endif /* CLIMBFIRSTLEVEL_H_ */
