/*
 * AutonomousBackNoFire.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSBACKNOFIRE_H_
#define AUTONOMOUSBACKNOFIRE_H_

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

class AutonomousBackNoFire: public CommandGroup {
public:AutonomousBackNoFire
	() {
		AddSequential(new DriveBackwardCommand(.75, 1.6));
		AddSequential(new StopDriveCommand());
	}
	virtual ~AutonomousBackNoFire() {
		
	}
};

#endif /* AUTONOMOUSBACKNOFIRE_H_ */
