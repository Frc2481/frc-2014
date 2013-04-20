/*
 * AutonomousBackReturnFire.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSBACKRETURNFIRE_H_
#define AUTONOMOUSBACKRETURNFIRE_H_

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

class AutonomousBackReturnFire: public CommandGroup {
public:
	AutonomousBackReturnFire() {
		AddSequential(new DriveBackwardCommand(1, .8));
		AddSequential(new WaitCommand(6));
		AddSequential(new LiftShooterCommand());
		AddSequential(new ShooterOnCommand());
		AddSequential(new DriveForwardCommand(1, .8));
		AddSequential(new StopDriveCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new ShooterUpToggleCommand());
		// (willMove) {
			//AddSequential(new DriveBackwardCommand(0.5,5));
			/*AddSequential(new TurnLeftCommand(0.5, 1.5));
			AddSequential(new DriveForwardCommand(0.5, 10));
			AddSequential(new TurnLeftCommand(0.5, 1.5));
			AddSequential(new StopDriveCommand());*/
		//}
	}
	virtual ~AutonomousBackReturnFire() {
		
	}
};

#endif /* AUTONOMOUSBACKRETURNFIRE_H_ */
