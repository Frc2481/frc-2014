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
#include "SetShooterPositionCommand.h"
#include "CheckHotGoalCommand.h"

class AutoDriveShootHotCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootHotCommandGroup(){
		AddParallel(new CheckHotGoalCommand());
		AddSequential(new SetForwardCommand(true));
		AddSequential(new DriveForwardCommand(.5, 2));
		AddSequential(new AutoSetShooterCommand());
//		AddSequential(new SetShooterPositionCommand(8, true));
		AddSequential(new WaitForHotGoalCommand());
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoDriveShootHotCommandGroup(){
		
	}
};
#endif
