/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef WRITETOCSVCOMMAND_H_
#define WRITETOCSVCOMMAND_H_

#include "../CommandBase.h"

class WriteToCSVCommand: public CommandBase {
public:
	WriteToCSVCommand(){
	}
	virtual ~WriteToCSVCommand(){
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
