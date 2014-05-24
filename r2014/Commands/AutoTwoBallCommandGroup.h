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
#include "WaitForShooterSetpointCommand.h"
#include "ToggleLeftEarCommand.h"
#include "ToggleRightEarCommand.h"
#include "SetShooterPositionCommand.h"
#include "../RobotParameters.h"

//class AutoSetFireCommandGroup: public CommandGroup{
//	AutoSetFireCommandGroup(){
//		AddSequential(new AutoSetShooterCommand());
//		AddSequential(new FireCommandGroup(true));
//	}
//};

class AutoTwoBallCommandGroup: public CommandGroup{
private:
public:
	AutoTwoBallCommandGroup(){
		AddSequential(new SetForwardCommand(true));
		AddParallel(new ManualSetShooterPositionCommand(NORMAL_SHOT_DISTANCE, true));
		AddSequential(new VariableIntakeCommand(1.0));
		AddSequential(new WaitCommand(1));
		AddSequential(new VariableIntakeCommand(.2));
		AddSequential(new DriveForwardCommand(1,.85));
		//AddSequential(new WaitCommand(1));
		//AddParallel(new AutoSetShooterCommand());
		AddSequential(new VariableIntakeCommand(-.3));
		AddSequential(new WaitCommand(.9));
		AddSequential(new VariableIntakeCommand(0));
		AddSequential(new WaitForShooterSetpointCommand(.5));
		AddSequential(new WaitCommand(.5));
		AddSequential(new FireCommandGroup(true));
		AddParallel(new ManualSetShooterPositionCommand(NORMAL_SHOT_DISTANCE, true));
		AddSequential(new TurnOnIntakeCommand());
		//AddParallel(new AutoSetShooterCommand(true));
		AddSequential(new WaitCommand(.25));
		AddSequential(new ToggleRightEarCommand());
		AddSequential(new ToggleLeftEarCommand());
		//AddSequential(new WaitCommand(.25));
		AddSequential(new WaitCommand(.5));
		AddSequential(new TurnOffIntakeCommand(true));
		AddSequential(new WaitCommand(.25));
		AddSequential(new ToggleRightEarCommand());
		AddSequential(new ToggleLeftEarCommand());
		AddSequential(new WaitCommand(.25));
		AddSequential(new WaitForShooterSetpointCommand(.5));
		AddSequential(new FireCommandGroup());
		
	}
	virtual ~AutoTwoBallCommandGroup(){
		
	}
};

#endif
