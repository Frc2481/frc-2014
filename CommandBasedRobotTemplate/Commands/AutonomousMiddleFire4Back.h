/*
 * AutonomousMiddleFire4Back.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSMIDDLEFIREFOURBACK_H_
#define AUTONOMOUSMIDDLEFIREFOURBACK_H_

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
#include "LiftShooterCommand.h"

class AutonomousMiddleFire4Back: public CommandGroup {
public:
	AutonomousMiddleFire4Back() {
		AddSequential(new LiftShooterCommand());
		AddSequential(new ShooterOnCommand());
		AddSequential(new WaitCommand(2));
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddParallel(new FireDiscCommand());
		AddSequential(new WaitCommand(.5));
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
	virtual ~AutonomousMiddleFire4Back() {
		
	}
};

#endif /* AUTONOMOUSMIDDLEFIREFOURBACK_H_ */
