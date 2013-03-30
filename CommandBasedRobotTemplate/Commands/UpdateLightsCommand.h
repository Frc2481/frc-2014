/*
 * UpdateLightsCommand.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Team2481
 */

#ifndef UPDATELIGHTSCOMMAND_H_
#define UPDATELIGHTSCOMMAND_H_

#include "../CommandBase.h"
#include "WPILib.h"

class UpdateLightsCommand: public CommandBase {
	int flashCount;
	int allianceColor;
	bool isFlashing;
	double flashStartTime;
public:
	UpdateLightsCommand(int color) {
		Requires(lights);
		allianceColor = color;
	}
	virtual ~UpdateLightsCommand() {
		
	}
	virtual void Initialize(){
		flashCount = 0;
		isFlashing = false;
		int r,g,b = 0;

		if (DriverStation::GetInstance()->GetAlliance() == DriverStation::kBlue){
			r = g = 0;
			b = 1;
		}
		else if (DriverStation::GetInstance()->GetAlliance() == DriverStation::kRed){
			b = g = 0;
			r = 1;
		}
		else {
			r = g = b = 1;
		}
		lights->setBottom(r,g,b);
	}
	virtual void Execute(){
		double timeRemaining = 2.25 - DriverStation::GetInstance()->GetMatchTime();
		if(timeRemaining < 60){
			if(!isFlashing && timeRemaining > 27.5){
				isFlashing = true;
				flashCount = 3;
				flashStartTime = timeRemaining;
			}
			if(!isFlashing){
				lights->setTop(1,0,0);
			}
		}
		else if(timeRemaining < 90){
			if(!isFlashing && timeRemaining > 57.5){
				isFlashing = true;
				flashCount = 2;
				flashStartTime = timeRemaining;
			}
			if(!isFlashing){
				lights->setTop(1,1,0);
			}
		}
		else {
			lights->setTop(0,1,0);
		}
		
		if(isFlashing){
			if(flashCount > 0 && timeRemaining - flashStartTime > .5){
				lights->setTop(1,1,1);
			}
			else if(flashCount > 0 && timeRemaining - flashStartTime > 1){
				lights->setTop(0,0,0);
				flashStartTime = timeRemaining;
				flashCount --;
			}
			else if (flashCount == 0){
				isFlashing = false;
			}
		}
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* UPDATELIGHTSCOMMAND_H_ */
