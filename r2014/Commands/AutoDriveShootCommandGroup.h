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
#include "SetShooterPositionCommand.h"

class AutoDriveShootCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootCommandGroup(){
		AddSequential(new SetForwardCommand(true));
		AddSequential(new DriveForwardCommand(.5, 1.6));
		AddSequential(new WaitCommand(1.5));
		AddSequential(new AutoSetShooterCommand());
//		AddSequential(new SetShooterPositionCommand(8, true));
		AddSequential(new WaitCommand(.25));
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoDriveShootCommandGroup(){
		
	}
};

#endif
