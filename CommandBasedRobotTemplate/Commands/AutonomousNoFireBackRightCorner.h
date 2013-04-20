/*
 * AutonomousNoFireBackRightCorner.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Team2481
 */

#ifndef AUTONOMOUSNOFIREBACKRIGHTCORNER_H_
#define AUTONOMOUSNOFIREBACKRIGHTCORNER_H_

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

class AutonomousNoFireBackRightCorner: public CommandGroup {
public:
	AutonomousNoFireBackRightCorner() {
		//AddSequential(new FireDiscCommand());
		//AddSequential(new FireDiscCommand());
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
	virtual ~AutonomousNoFireBackRightCorner() {
		
	}
};

#endif /* AUTONOMOUSNOFIREBACKRIGHTCORNER_H_ */
