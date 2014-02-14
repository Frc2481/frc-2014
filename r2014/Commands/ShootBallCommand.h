#ifndef SHOOTBALLCOMMAND_H_
#define SHOOTBALLCOMMAND_H_

#include "../Subsystems/Shooter.h"
#include "../CommandBase.h"

class ShootBallCommand: public CommandBase {
public:
	ShootBallCommand(){
		Requires(shooter);
	}
	virtual void Initialize();
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End();
	virtual void Interrupted();
};
#endif /*SHOOTBALLCOMMAND_H_*/
