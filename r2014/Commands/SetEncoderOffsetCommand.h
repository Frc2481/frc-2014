/*
 * SetEncoderOffsetCommand.h
 *
 *  Created on: Jan 18, 2014
 *      Author: Team2481
 */

#ifndef SETENCODEROFFSETCOMMAND_H_
#define SETENCODEROFFSETCOMMAND_H_

#include "../CommandBase.h"

class SetEncoderOffsetCommand: public CommandBase {
private:
	int mWheel;
public:
	SetEncoderOffsetCommand(int wheel);
	virtual ~SetEncoderOffsetCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif /* SETENCODEROFFSETCOMMAND_H_ */
