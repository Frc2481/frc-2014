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
#include "LowerShooterCommand.h"

class AutonomousCommandGroup: public CommandGroup {
public:
	AutonomousCommandGroup(float delay, bool willMove) {
		AddSequential(new ShooterUpToggleCommand());
		AddSequential(new ShooterOnCommand());
		AddSequential(new WaitCommand(2));
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new ShooterUpToggleCommand());
		AddSequential(new DriveBackwardCommand(.75, 1.6));
		AddSequential(new StopDriveCommand());
		// (willMove) {
			//AddSequential(new DriveBackwardCommand(0.5,5));
			/*AddSequential(new TurnLeftCommand(0.5, 1.5));
			AddSequential(new DriveForwardCommand(0.5, 10));
			AddSequential(new TurnLeftCommand(0.5, 1.5));
			AddSequential(new StopDriveCommand());*/
		//}
	}
	virtual ~AutonomousCommandGroup() {
		
	}
};

#endif /* AUTONOMOUSCOMMANDGROUP_H_ */
