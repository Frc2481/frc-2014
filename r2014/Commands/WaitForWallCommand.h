
// Author: paulRich
// Editor: thomasSpeciale

#ifndef WAITFORWALLCOMMAND_H_
#define WAITFORWALLCOMMAND_H_

#include "../Commandbase.h"

class WaitForWallCommand : public CommandBase {
public:
	WaitForWallCommand();
	virtual ~WaitForWallCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupt();
	
}

#endif /*WAITFORWALLCOMMAND_H_*/
