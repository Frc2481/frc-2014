/*
 * PoliceLightsCommand.h
 *
 *  Created on: Apr 4, 2013
 *      Author: Team2481
 */

#ifndef POLICELIGHTSCOMMAND_H_
#define POLICELIGHTSCOMMAND_H_

#include "../CommandBase.h"

class PoliceLightsCommand: public CommandBase {
private:
	bool isBlue;
	double previousTime;
public:
	PoliceLightsCommand(){
		Requires(lights);
		previousTime = 0;
		isBlue = false;
	}
	virtual ~PoliceLightsCommand(){}
	virtual void Execute(){
		if (TimeSinceInitialized() - previousTime > 0.2) {
			isBlue = !isBlue;
			previousTime = TimeSinceInitialized();
		}
		lights->setTop(!isBlue, 0, isBlue);
		lights->setBottom(isBlue, 0 , !isBlue);
		printf("previousTime %f \n", previousTime);
		printf("isBlue %d \n", isBlue);
		
	}
	void Initialize(){}
	void End(){}
	void Interrupted(){}
	bool IsFinished(){
		return false;
	}
};

#endif /* POLICELIGHTSCOMMAND_H_ */
