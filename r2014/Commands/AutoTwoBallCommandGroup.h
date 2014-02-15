/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOTWOBALLCOMMANDGROUP_H_
#define AUTOTWOBALLCOMMANDGROUP_H_

#include "../CommandBase.h"
#include "ManualFireShooterCommand.h"
#include "TurnOffIntakeCommand.h"
#include "TurnOnIntakeCommand.h"
#include "AutoSetShooterCommand.h"

class AutoTwoBallCommandGroup: public CommandGroup{
private:
public:
	AutoTwoBallCommandGroup(){
		AddSequential(new TurnOnIntakeCommand);
		AddSequential(new DriveForwardCommand(.5, .5));
		AddSequential(new AutoSetShooterCommand());
		AddSequential(new FireCommandGroup());
		AddSequential(new TurnOffIntakeCommand());
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoTwoBallCommandGroup(){
		
	}
};

#endif
