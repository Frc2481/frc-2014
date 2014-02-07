/*
 * AutonomousFireBackLeftCorner.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSFIREBACKLEFTCORNER_H_
#define AUTONOMOUSFIREBACKLEFTCORNER_H_

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
#include "ShooterSetSpeedCommand.h"

class AutonomousFireBackLeftCorner: public CommandGroup {
public:
	AutonomousFireBackLeftCorner() {
		AddSequential(new LiftShooterCommand());
		AddSequential(new ShooterSetSpeedCommand(SHOOTER_TWO_PT_SPEED));
		AddSequential(new ShooterOnCommand());
		AddSequential(new WaitCommand(2.5));
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddParallel(new FireDiscCommand());
		AddSequential(new WaitCommand(.5));
		AddSequential(new ShooterUpToggleCommand());
		//AddSequential(new DriveBackwardCommand(.75, 1.6));
		//AddSequential(new StopDriveCommand());

	}
	virtual ~AutonomousFireBackLeftCorner() {
		
	}
};

#endif /* AUTONOMOUSCOMMANDGROUP_H_ */
