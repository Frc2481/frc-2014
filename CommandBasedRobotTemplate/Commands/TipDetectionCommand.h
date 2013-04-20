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
#include "PoliceLightsCommand.h"

class TipDetectionCommand: public CommandBase {
private:
	TipCorrectionCommand *tipCorrection;
	PoliceLightsCommand *policeLights;
public:
	TipDetectionCommand() : CommandBase("TipDetectionCommand"){
		tipCorrection = new TipCorrectionCommand();
		policeLights = new PoliceLightsCommand();
	}
	virtual ~TipDetectionCommand(){}
	void Initialize(){}
	void Execute(){		
		/*if (tipSensor->IsTipped() != 0){
			if (tipCorrectionEnabled){
				policeLights->Start();
				printf("TipDetected \n");
				//tipCorrection->Start();
			} /*else {
				//tipCorrection->Cancel();
				//policeLights->Cancel();
			//}
		} else {
			//tipCorrection->Cancel();
			policeLights->Cancel();
		}*/
	}
	bool IsFinished(){
		return false;
	}
	void End(){}
	void Interrupted(){}
};

#endif /* TIPDetectionCOMMAND_H_ */
