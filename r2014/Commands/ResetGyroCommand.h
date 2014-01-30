/*
 * ResetGyroCommand.h
 *
 *  Created on: Jan 23, 2014
 *      Author: Team2481
 */

#ifndef RESETGYROCOMMAND_H_
#define RESETGYROCOMMAND_H_

#include "../CommandBase.h"

class ResetGyroCommand : public CommandBase {
public:
	ResetGyroCommand();
	virtual ~ResetGyroCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif /* RESETGYROCOMMAND_H_ */
