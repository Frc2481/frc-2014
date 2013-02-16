/*
 * DeadmanCommand.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Team2481
 */

#ifndef DEADMANCOMMAND_H_
#define DEADMANCOMMAND_H_
#include "../CommandBase.h"

class DeadmanCommand : public CommandBase{
	const char *commandName;
	bool firstRun;
	bool autoCommand;
public:
	DeadmanCommand(const char *name);
	virtual ~DeadmanCommand();
	virtual void DeadmanExecute() = 0;
	virtual void DeadmanInterrupt() = 0;
	virtual void Execute();
	virtual void Initialize();
	virtual void End();
	virtual void Interrupted();
};

#endif /* DEADMANCOMMAND_H_ */
