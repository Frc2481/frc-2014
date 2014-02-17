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
#include "VariableIntakeCommand.h"

class AutoTwoBallCommandGroup: public CommandGroup{
private:
public:
	AutoTwoBallCommandGroup(){
		//AddSequential(new TurnOnIntakeCommand);
		AddSequential(new VariableIntakeCommand(1.0));
		AddSequential(new DriveForwardCommand(0,1.5));
		AddSequential(new DriveForwardCommand(.70, 2));
		AddSequential(new VariableIntakeCommand(0.42));
		AddSequential(new DriveForwardCommand(0,0.5));
		AddSequential(new VariableIntakeCommand(-1.0));
		AddSequential(new DriveForwardCommand(0,0.47));
		AddSequential(new VariableIntakeCommand(0.0));
		
		//AddSequential(new AutoSetShooterCommand());
		
		//AddSequential(new FireCommandGroup());
		//AddSequential(new TurnOffIntakeCommand());
		//AddSequential(new FireCommandGroup());
	}
	virtual ~AutoTwoBallCommandGroup(){
		
	}
};

#endif
