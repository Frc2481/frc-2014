/*
 * ClimbingCommandGroup.h
 *
 *  Created on: Jan 26, 2013
 *      Author: Team2481
 */

#ifndef CLIMBINGCOMMANDGROUP_H_
#define CLIMBINGCOMMANDGROUP_H_

#include "WPILib.h"
#include "FirstRungPositionArmCommand.h"
#include "FullyExtendArmCommand.h"
#include "FullyRetractArmCommand.h"
#include "LatchCommand.h"
#include "UnlatchCommand.h"
#include "SafeUnlatchCommand.h"
#include "LiftRobotCommand.h"
#include "LowerRobotCommand.h"
#include "ClimbOneLevel.h"
#include "ClimbFirstLevel.h"
#include "ShooterOnCommand.h"
#include "ShooterOffCommand.h"
#include "LowerShooterCommand.h"
#include "FireDiscCommandGroup.h"
#include "FireDiscCommand.h"
#include "SetLightsCommand.h"
#include "RandomLightsCommand.h"
#include "AutoFireCommandGroup.h"
class ClimbingCommandGroup: public CommandGroup {
private:
	bool haveRun;
public:
	ClimbingCommandGroup() {
		haveRun = false;
		AddSequential(new LowerShooterCommand());
		AddSequential(new ShooterOffCommand());
		AddSequential(new ClimbFirstLevel());
		AddSequential(new ClimbOneLevel());
		AddSequential(new ClimbOneLevel());
		AddSequential(new AutoFireCommandGroup());
		//green
		
		
		/*AddSequential(new UnlatchCommand());
		AddSequential(new FirstRungArmPositionCommand());
		
		//Lift and give time for the robot to lift before
		//climbing on to the first rung.
		AddParallel(new LiftRobotCommand());
		AddSequential(new WaitCommand(1.5));
		
		AddSequential(new FullyRetractArmPositionCommand());
		
		//Latch and give time for the hooks to latch
		//before continuing.
		AddParallel(new LatchCommand());
		AddSequential(new WaitCommand(.5));
		AddSequential(new LowerRobotCommand());
		
		//2nd Level
		AddSequential(new FullyExtendArmPositionCommand());
		AddSequential(new WaitCommand(.25));
		
		AddParallel(new SafeUnlatchCommand());
		AddSequential(new FullyRetractArmPositionCommand());
//		
		AddParallel(new LatchCommand());
		AddSequential(new WaitCommand(.5));
		//AddSequential(new UnlatchCommand());
		
		//3rd Level
		AddSequential(new FullyExtendArmPositionCommand());
		AddSequential(new WaitCommand(.25));
		
		AddParallel(new SafeUnlatchCommand());
		AddSequential(new FullyRetractArmPositionCommand());
//		
		AddParallel(new LatchCommand());
		AddSequential(new WaitCommand(.5));
				
		
//		AddSequential(new FullyRetractArmPositionCommand());
//		AddSequential(new LatchCommand());
//		AddSequential(new FullyExtendArmPositionCommand());
//		AddSequential(new UnlatchCommand());
//		AddSequential(new FullyRetractArmPositionCommand());
//		AddSequential(new LatchCommand());
		//Shoot
		//spin up motor in parallel?*/
		
	}
	~ClimbingCommandGroup() {
		
	}
	void Initialize() {
		
	}
	void Execute() {
		
	}
	bool isFinished() {
		return haveRun;
	}
	void End() {
		haveRun = true;
	}
	void reset(){
		haveRun = false; 
	}
};

#endif /* CLIMBINGCOMMANDGROUP_H_ */
