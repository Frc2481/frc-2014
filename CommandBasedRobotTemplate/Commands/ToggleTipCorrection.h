/*
 * ToggleTipCorrection.h
 *
 *  Created on: Apr 4, 2013
 *      Author: Team2481
 */

#ifndef TOGGLETIPCORRECTION_H_
#define TOGGLETIPCORRECTION_H_


#include "../CommandBase.h"
class ToggleTipCorrection: public CommandBase {
public:
	ToggleTipCorrection(){}
	virtual ~ToggleTipCorrection(){}
	void Execute(){}
	void Initialize(){
		tipCorrectionEnabled = !tipCorrectionEnabled;
	}
	void Interrupted(){}
	bool IsFinished(){
		return false;
	}
	void End(){}
};

#endif /* TOGGLETIPCORRECTION_H_ */
