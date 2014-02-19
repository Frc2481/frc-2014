/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOSHOOTDRIVECOMMANDGROUP_H_
#define AUTOSHOOTDRIVECOMMANDGROUP_H_

#include "../CommandBase.h"
#include "ManualFireShooterCommand.h"
#include "DriveForwardCommand.h"
#include "FireCommandGroup.h"
#include "AutoSetShooterCommand.h"
#include "SetForwardCommand.h"

class AutoDriveShootCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootCommandGroup(){
		AddSequential(new SetForwardCommand(true));
		AddSequential(new DriveForwardCommand(.5, 2));
		AddSequential(new AutoSetShooterCommand());
		AddSequential(new WaitCommand(.25));
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoDriveShootCommandGroup(){
		
	}
};

#endif
