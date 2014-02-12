/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef FIRECOMMANDGROUP_H_
#define FIRECOMMANDGROUP_H_

#include "../CommandBase.h"
#include "FireCommandGroup.h"
#include "ManualFireShooterCommand.h"

class FireCommandGroup: public CommandGroup{
private:
public:
	FireCommandGroup(){
		AddSequential(new ManualFireShooterCommand());
		AddSequential(new WaitCommand(1.5));
		AddSequential(new AutoCockShooterCommand());
	}
	virtual ~FireCommandGroup(){
		
	}
};

#endif
