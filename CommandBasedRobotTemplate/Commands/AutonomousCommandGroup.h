/*
 * AutonomousCommandGroup.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSCOMMANDGROUP_H_
#define AUTONOMOUSCOMMANDGROUP_H_

#include "WPILib.h"
#include "DriveForwardCommand.h"
#include "DriveBackwardCommand.h"
#include "TurnRightCommand.h"
#include "TurnLeftCommand.h"
#include "StopDriveCommand.h"
#include "FireDiscCommand.h"
#include "ShooterOnCommand.h"
#include "ShooterOffCommand.h"
#include "ShooterUpToggleCommand.h"

class AutonomousCommandGroup: public CommandGroup {
public:
	AutonomousCommandGroup(float delay, bool willMove) {
		AddSequential(new ShooterUpToggleCommand());
		AddSequential(new ShooterOnCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new ShooterOffCommand());
		if (willMove) {
			AddSequential(new DriveBackwardCommand(0.5,5));
		}
	}
	virtual ~AutonomousCommandGroup() {
		
	}
};

#endif /* AUTONOMOUSCOMMANDGROUP_H_ */
