/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef CRABDRIVECOMMAND_H_
#define CRABDRIVECOMMAND_H_

#include "../CommandBase.h"

class CrabDriveCommand: public CommandBase {
public:
	CrabDriveCommand();
	virtual ~CrabDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif /* CRABDRIVECOMMAND_H_ */
