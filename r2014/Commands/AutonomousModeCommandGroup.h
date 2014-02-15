#ifndef AUTONOMOUSMODECOMMANDGROUP_H_
#define AUTONOMOUSMODECOMMANDGROUP_H_
#include "WPILib.h"
#include "ShootBallCommand.h"
#include "DriveForwardCommand.h"
#include "PickupBallCommand.h"
#include "DriveBackwardsCommand.h"

class AutonomousModeCommandGroup: public CommandBase {
public:
	AutonomousModeCommandGroup() {
		AddSequential(new ShootBallCommand());
		AddSequential();
		AddParallel(new PickUpBallCommand());
		AddSequential(new DriveForwardCommand(.5, 3));
		AddSequential(new DriveBackwardCommand(-.5, 3));
		AddSequential(new ShootBallCommand());
	}
	virtual ~AutonomousModeCommandGroup() {
		
	}
};
#endif /*AUTONOMOUSMODECOMMANDGROUP_H_*/
