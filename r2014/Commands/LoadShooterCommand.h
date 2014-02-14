#ifndef LOADSHOOTERCOMMAND_H_
#define LOADSHOOTERCOMMAND_H_

#include "../CommandBase.h"

class LoadShooterCommand: public CommandBase {
public:
	LoadShooterCommand();
	virtual ~LoadShooterCommand();
	virtual void Initialize();
	virtual void Execute();	
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif /*LOADSHOOTERCOMMAND_H_*/
