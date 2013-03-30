/*
 * TipCorrectionCommand.h
 *
 *  Created on: Mar 28, 2013
 *      Author: Team2481
 */

#ifndef TIPCORRECTIONCOMMAND_H_
#define TIPCORRECTIONCOMMAND_H_

#include "../CommandBase.h"

class TipCorrectionCommand: public CommandBase{
public:
	TipCorrectionCommand() : CommandBase("TipCorrectionCommadn"){
		Requires(driveTrain);
	}
	virtual ~TipCorrectionCommand(){}
	void Initialize(){	}
	void Execute(){
		if (tipSensor->IsTipped() > 0){
			driveTrain->DriveBackward(.75);
		}
		else if (tipSensor->IsTipped() < 0){
			driveTrain->DriveForward(.75);
		}
	}
	void Interrupted(){}
	bool IsFinished(){
		return false;
	}
	void End(){}
};

#endif /* TIPCORRECTIONCOMMAND_H_ */
