/*
 * TipCorrectionCommand.h
 *
 *  Created on: Mar 28, 2013
 *      Author: Team2481
 */

#ifndef TIPDETECTIONCOMMAND_H_
#define TIPDETECTIONCOMMAND_H_

#include "../CommandBase.H"
#include "DriveBackwardCommand.h"
#include "DriveForwardCommand.h"
#include "TipCorrectionCommand.h"

class TipDetectionCommand: public CommandBase {
private:
	TipCorrectionCommand *tipCorrection;
public:
	TipDetectionCommand() : CommandBase("TipDetectionCommand"){
		tipCorrection = new TipCorrectionCommand();
	}
	virtual ~TipDetectionCommand(){}
	void Initialize(){}
	void Execute(){		
		if (tipSensor->IsTipped() != 0){
			if (tipCorrectionEnabled){
				tipCorrection->Start();
			} else {
				tipCorrection->Cancel();
			}
		} else {
			tipCorrection->Cancel();
			robotLift->retractFlip();
		}
	}
	bool IsFinished(){
		return false;
	}
	void End(){}
	void Interrupted(){}
};

#endif /* TIPDetectionCOMMAND_H_ */
