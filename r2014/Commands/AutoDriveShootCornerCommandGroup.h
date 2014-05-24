/*
 * 	AutoDriveShootCornerCommandGroup.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOSHOOTDRIVECORNERCOMMANDGROUP_H_
#define AUTOSHOOTDRIVECORNERCOMMANDGROUP_H_

#include "../CommandBase.h"
#include "ManualFireShooterCommand.h"
#include "DriveForwardCommand.h"
#include "FireCommandGroup.h"
#include "AutoSetShooterCommand.h"
#include "SetForwardCommand.h"
#include "SetShooterPositionCommand.h"
#include "../RobotParameters.h"
#include "DriveBackwardsCommand.h"
#include "ManualSetShooterPositionCommand.h"

class AutoDriveShootCornerCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootCornerCommandGroup(){
		AddSequential(new SetForwardCommand(true));
		AddSequential(new DriveForwardCommand(.5, 2.3));
		AddSequential(new DriveForwardCommand(.25, 2));
//		AddSequential(new WaitCommand(.25));
//		AddSequential(new DriveBackwardsCommand(.5, .2));
//		AddSequential(new WaitCommand(1.5));
//		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoDriveShootCornerCommandGroup(){
		
	}
};

#endif
