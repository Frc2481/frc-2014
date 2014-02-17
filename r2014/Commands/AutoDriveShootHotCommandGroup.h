/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTODRIVESHOOTCOMMANDGROUP_H_
#define AUTODRIVESHOOTCOMMANDGROUP_H_

#include "../CommandBase.h"
#include "ManualFireShooterCommand.h"
#include "DriveForwardCommand.h"
#include "FireCommandGroup.h"
#include "WaitForHotGoalCommand.h"
#include "AutoSetShooterCommand.h"
#include "SetForwardCommand.h"

class AutoDriveShootHotCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootHotCommandGroup(){
		AddSequential(new SetForwardCommand(false));
		AddSequential(new DriveForwardCommand(.5, .5));
		AddSequential(new AutoSetShooterCommand());
		AddSequential(new WaitForHotGoalCommand());
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoDriveShootHotCommandGroup(){
		
	}
};
#endif
