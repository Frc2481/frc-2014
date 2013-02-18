/*
 * SetLightsCommand.h
 *
 *  Created on: Jan 29, 2013
 *      Author: Team2481
 */

#ifndef SETLIGHTSCOMMAND_H_
#define SETLIGHTSCOMMAND_H_

#include "../CommandBase.h"

class SetLightsCommand: public CommandBase {
private:
	int color;
public:
	SetLightsCommand(int c) : color(c){}
	virtual ~SetLightsCommand(){}
	void Initialize(){
		lights->setBottom(color);
		lights->setTop(color);
	}
	void Execute(){
	}
	bool IsFinished(){
		return true;
	}
	void Interrupted(){}
	void End(){}
};

#endif /* TOGGLELiftCOMMAND_H_ */
