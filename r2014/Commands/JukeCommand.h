// Author: thomasSpeciale, paulRich

#ifndef JUKECOMMAND_H_
#define JUKECOMMAND_H_

#include "../CommandBase.h"

class JukeCommand: public CommandBase {
public:
	JukeCommand(bool isRight);
	virtual ~JukeCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	bool isRight;
};

#endif /*JUKECOMMAND_H_*/
