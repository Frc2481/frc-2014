#include "../CommandBase.h"
#include "WPILib.h"
#include <stdio.h>
#include <string.h>

#ifndef CLIMBCOMMANDBASE_H
#define CLIMBCOMMANDBASE_H
/*
 * ClimbCommandBase: Any command that is used in the autonomous
 * 					 climb must inherit this class and provide a 
 * 					 sequence number.
 * 					 
 * 					 When running the command manually create it
 * 					 like normal with the same sequence number that
 * 					 would be used for auto.
 * 					 
 * 					 When running the command in auto create it
 * 					 passing in true for autoCmd with the correct
 * 					 sequence number.
 */
class ClimbCommandBase : public CommandBase {
public:
	static int curSeqNumber;
	static int climbLevel;
	
protected:
	int seqNumber;
	bool finished;
	bool autoCmd;
	
	const char* name;
	
public:
	ClimbCommandBase(int seqNum, const char *name, bool autoCmd=false);
	
	/*
	 * Initialize: Subclases should not reimplement this. 
	 */
	void Initialize();
	
	virtual void ClimbInitialize() = 0;
	virtual void Execute();
	virtual void ClimbExecute() = 0;
	virtual bool IsFinished();
	virtual void End();
	virtual void ClimbEnd() = 0;
	virtual void Interrupted() = 0;
};
#endif
