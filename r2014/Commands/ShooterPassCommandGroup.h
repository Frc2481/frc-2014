
#ifndef SHOOTERPASSCOMMANDGROUP_H_
#define SHOOTERPASSCOMMANDGROUP_H_

#include "../CommandBase.h"
#include "FireDistanceCommand.h"
#include "ManualFireShooterCommand.h"
#include "ReleaseShooterCommand.h"
#include "AutoCockShooterCommand.h"
#include "ManualSetShooterPositionCommand.h"

class ShooterPassCommandGroup: public CommandGroup{
private:
public:
	ShooterPassCommandGroup(){
		AddSequential(new ManualSetShooterPositionCommand(.125, true));
		AddSequential(new ManualFireShooterCommand());
		AddSequential(new WaitCommand(.5));
		AddParallel(new ReleaseShooterCommand());
		AddSequential(new WaitCommand(.5));
		AddSequential(new AutoCockShooterCommand());
		
	}
	virtual ~ShooterPassCommandGroup(){
		
	}
};
#endif

