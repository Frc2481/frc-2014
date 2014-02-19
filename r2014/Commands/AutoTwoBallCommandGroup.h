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
#include "SetForwardCommand.h"

class AutoTwoBallCommandGroup: public CommandGroup{
private:
public:
	AutoTwoBallCommandGroup(){
		AddSequential(new SetForwardCommand(true));
		AddSequential(new VariableIntakeCommand(1.0));
		AddSequential(new WaitCommand(1.5));
		AddSequential(new DriveForwardCommand(.7,2));
		AddSequential(new AutoSetShooterCommand());
		AddSequential(new VariableIntakeCommand(.42));
		AddSequential(new WaitCommand(.5));
		AddSequential(new VariableIntakeCommand(-1));
		AddSequential(new WaitCommand(.47));
		AddSequential(new VariableIntakeCommand(0));
		AddSequential(new FireCommandGroup());
		AddSequential(new TurnOffIntakeCommand());
		AddSequential(new FireCommandGroup());
	}
	virtual ~AutoTwoBallCommandGroup(){
		
	}
};

#endif
