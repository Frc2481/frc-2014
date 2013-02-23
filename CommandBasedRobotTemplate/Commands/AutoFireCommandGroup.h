/*
 * AutoFireCommandGroup.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Team2481
 */

#ifndef AUTOFIRECOMMANDGROUP_H_
#define AUTOFIRECOMMANDGROUP_H_

#include "WPILib.h"
#include "ShooterOnCommand.h"
#include "ShooterOffCommand.h"
#include "LowerShooterCommand.h"
#include "FireDiscCommandGroup.h"
#include "FireDiscCommand.h"
#include "SetLightsCommand.h"
#include "RandomLightsCommand.h"
class AutoFireCommandGroup: public CommandGroup {
public:
	AutoFireCommandGroup(){AddParallel(new SetLightsCommand(0,1,0));
	
	AddSequential(new ShooterOnCommand());
	AddSequential(new WaitCommand(3));
	//red
	AddSequential(new SetLightsCommand(1,0,0));
	
	AddSequential(new FireDiscCommand());
	//blue
	AddSequential(new SetLightsCommand(0,0,1));
	
	//AddSequential(new WaitCommand(.5));
	//red
	//AddParallel(new SetLightsCommand(1,0,0));
	
	AddSequential(new FireDiscCommand());
	//purple
	AddSequential(new SetLightsCommand(1,0,1));
	
	//AddSequential(new WaitCommand(.5));
	//red
	//AddParallel(new SetLightsCommand(1,0,0));
	
	AddSequential(new FireDiscCommand());
	//yellow
	AddSequential(new SetLightsCommand(1,1,0));
	
	//AddSequential(new WaitCommand(.5));
	//red
	//sAddParallel(new SetLightsCommand(1,0,0));
	
	AddSequential(new FireDiscCommand());
	//teal
	AddSequential(new SetLightsCommand(0,1,1));
	
	AddSequential(new ShooterOffCommand());
	AddSequential(new RandomLightsCommand);}
	virtual ~AutoFireCommandGroup(){}
};

#endif /* AUTOFIRECOMMANDGROUP_H_ */
