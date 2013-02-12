/*
 * ToggleHopperPressureCommand.h
 *
 *  Created on: Jan 29, 2013
 *      Author: Team2481
 */

#ifndef TOGGLEHOPPERPRESSURECOMMAND_H_
#define TOGGLEHOPPERPRESSURECOMMAND_H_

#include "../CommandBase.h"

class ToggleHopperPressureCommand: public CommandBase {
public:
	ToggleHopperPressureCommand(){}
	virtual ~ToggleHopperPressureCommand(){}
	void Initialize(){
		if (hopper->isPressurized()){
			hopper->removePressure();
		}
		else {
			hopper->addPressure();
		}
	}
	void Execute(){
	}
	bool IsFinished(){
		return true;
	}
	void Interrupted(){}
	void End(){}
};

#endif /* TOGGLEHOPPERPRESSURECOMMAND_H_ */
