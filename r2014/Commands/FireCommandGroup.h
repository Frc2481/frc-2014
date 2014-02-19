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
#include "AutoCockShooterCommand.h"
#include "AutoSetShooterCommand.h"

class FireCommandGroup: public CommandGroup{
public:
	FireCommandGroup(bool auton = false){
		AddSequential(new ManualFireShooterCommand(auton));
		AddSequential(new WaitCommand(.25));
		AddSequential(new AutoCockShooterCommand());
	}
	virtual ~FireCommandGroup(){
		
	}
};

#endif
