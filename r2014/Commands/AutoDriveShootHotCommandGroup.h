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
#include "ManualSetShooterPositionCommand.h"
#include "WaitForShooterSetpointCommand.h"

class AutoDriveShootHotCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootHotCommandGroup(){
		AddParallel(new CheckHotGoalCommand());
		AddParallel(new ManualSetShooterPositionCommand(NORMAL_SHOT_DISTANCE, true));
		AddSequential(new SetForwardCommand(true));
		AddSequential(new DriveForwardCommand(.75, 1));
//		AddSequential(new SetShooterPositionCommand(8, true));
		AddSequential(new WaitForHotGoalCommand());
		AddSequential(new WaitForShooterSetpointCommand(.25));
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoDriveShootHotCommandGroup(){
		
	}
};
#endif
