#ifndef DRIVEBACKWARDSCOMMAND_H_
#define DRIVEBACKWARDSCOMMAND_H_

#include "DriveCommandbase.h"

class DriveBackwardsCommand : public DriveCommandBase{
public:
	DriveBackwardsCommand(float speed, double time)
			:DriveCommandBase(speed, time, "driveBackwardsCommand"){
	}
	virtual void Execute(){
		driveTrain->Crab(0,-driveSpeed,0,false);
	}
};

#endif /*DRIVEBACKWARDSCOMMAND_H_*/
