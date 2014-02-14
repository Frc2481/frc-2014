#ifndef DRIVEFORWARDCOMMAND_
#define DRIVEFORWARDCOMMAND_

#include "DriveCommandBase.h"

class DriveForwardCommand : public DriveCommandBase{
public:
	DriveForwardCommand(float speed, double time)
			:DriveCommandBase(speed, time, "driveForwardCommand"){
	}
	virtual void Execute(){
		driveTrain->Crab(0,driveSpeed,0);
	}
};
#endif /*DRIVEFORWARDCOMMAND_*/
