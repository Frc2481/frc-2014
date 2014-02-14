#ifndef AUTOCOMMANDGROUP_H_
#define AUTOCOMMANDGROUP_H_

#include "DriveForwardCommand.h"
#include "DriveBackwardsCommand.h"
#include "ShootBallCommand.h"

class AutoCommandGroup: public CommandGroup {
public:
	AutoCommandGroup();
	virtual ~AutoCommandGroup();
};

#endif /*AUTOCOMMANDGROUP_H_*/
