/*
 * AutonomousFireBackRightCorner.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSFIREBACKRIGHTCORNER_H_
#define AUTONOMOUSFIREBACKRIGHTCORNER_H_

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

class AutonomousFireBackRightCorner: public CommandGroup {
public:
	AutonomousFireBackRightCorner() {
		AddSequential(new LiftShooterCommand());
		AddSequential(new ShooterOnCommand());
		AddSequential(new WaitCommand(2));
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		AddSequential(new FireDiscCommand());
		//AddSequential(new FireDiscCommand());
		//AddSequential(new FireDiscCommand());
		AddSequential(new ShooterUpToggleCommand());
		AddSequential(new DriveBackwardCommand(1, .3));
		AddSequential(new WaitCommand(.2));
		AddSequential(new TurnLeftCommand(1,.27));
		//AddSequential(new DriveBackwardCommand(.75, 1.25));   // 75%
		AddSequential(new DriveBackwardCommand(1, .75));		// 100%
		AddSequential(new StopDriveCommand());
		// (willMove) {
			//AddSequential(new DriveBackwardCommand(0.5,5));
			/*AddSequential(new TurnLeftCommand(0.5, 1.5));
			AddSequential(new DriveForwardCommand(0.5, 10));
			AddSequential(new TurnLeftCommand(0.5, 1.5));
			AddSequential(new StopDriveCommand());*/
		//}
	}
	virtual ~AutonomousFireBackRightCorner() {
		
	}
};

#endif /* AUTONOMOUSFIREBACKRIGHTCORNER_H_ */
