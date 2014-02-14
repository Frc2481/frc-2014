/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOSHOOTDRIVECOMMANDGROUP_H_
#define AUTOSHOOTDRIVECOMMANDGROUP_H_

#include "../CommandBase.h"
#include "AutoDriveShootCommandGroup.h"
#include "ManualFireShooterCommand.h"

class AutoDriveShootCommandGroup: public CommandGroup{
private:
public:
	AutoDriveShootCommandGroup(){
	}
	virtual ~AutoDriveShootCommandGroup(){
		
	}
};

#endif
