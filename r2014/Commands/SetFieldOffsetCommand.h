/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef SETFIELDOFFSET_H_
#define SETFIELDOFFSET_H_

#include "../CommandBase.h"

class SetFieldOffsetCommand: public CommandBase {
public:
	SetFieldOffsetCommand(){
		
	}
	virtual ~SetFieldOffsetCommand(){
		
	}
	virtual void Initialize(){
		driveTrain->SetFieldOffset();
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
