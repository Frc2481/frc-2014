/*
 * ArmPositionCommandBase.h
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#ifndef ARMPOSITIONCOMMANDBASE_H_
#define ARMPOSITIONCOMMANDBASE_H_

#include "WPILib.h"
#include "../Components/DeadmanCommand.h"

class ArmPositionCommandBase: public DeadmanCommand {
private:
	float armPosition;
	char *childCommandType;
public:
	ArmPositionCommandBase(float position, const char *name);
	virtual ~ArmPositionCommandBase();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual void DeadmanInterrupt();
	virtual void DeadmanExecute();
};

#endif /* ARMPOSITIONCOMMANDBASE_H_ */
