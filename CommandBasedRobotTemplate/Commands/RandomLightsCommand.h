/*
 * RandomLightsCommand.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Team2481
 */

#ifndef RANDOMLIGHTSCOMMAND_H_
#define RANDOMLIGHTSCOMMAND_H_

#include "../CommandBase.h"
#include "SetLightsCommand.h"

class RandomLightsCommand: public CommandBase {
private:
	double previousTime;
public:
	RandomLightsCommand() {
		previousTime = 0;
	}
	virtual ~RandomLightsCommand() {
		
	}
	virtual void Initialize(){
	}
	virtual void Execute(){
		if (TimeSinceInitialized() - previousTime > 0.25) {
			lights->setTop(rand() > 0.5,rand() > 0.5,rand() > 0.5);
			lights->setBottom(rand() > 0.5,rand() > 0.5,rand() > 0.5);
			previousTime = TimeSinceInitialized();
		}
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* RANDOMLIGHTSCOMMAND_H_ */
