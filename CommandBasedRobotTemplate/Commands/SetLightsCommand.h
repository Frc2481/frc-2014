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
	bool r,g,b;
public:
	SetLightsCommand(bool R, bool G, bool B){
		r = R;
		g = G;
		b = B;
		Requires(lights);
	}
	virtual ~SetLightsCommand(){}
	void Initialize(){
		lights->setBottom(r, g, b);
		lights->setTop(r, g, b);
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
