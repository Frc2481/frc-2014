/*
 * ArmPositionCommandBase.h
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#ifndef ARMPOSITIONCOMMANDBASE_H_
#define ARMPOSITIONCOMMANDBASE_H_

#include "WPILib.h"
#include "ClimbCommandBase.h"

class ArmPositionCommandBase: public ClimbCommandBase {
private:
	float armPosition;
	char *childCommandType;
public:
	ArmPositionCommandBase(float position, int seq, bool autoCmd, const char * name);
	virtual ~ArmPositionCommandBase();
	virtual void ClimbInitialize();
	virtual bool IsFinished();
	virtual void ClimbExecute();
	virtual void ClimbEnd();
	virtual void Interrupted();
};

#endif /* ARMPOSITIONCOMMANDBASE_H_ */
