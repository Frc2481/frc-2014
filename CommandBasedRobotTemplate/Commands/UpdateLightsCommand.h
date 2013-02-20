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
	int allianceColor;
public:
	UpdateLightsCommand(int color) {
		Requires(lights);
		allianceColor = color;
	}
	virtual ~UpdateLightsCommand() {
		
	}
	virtual void Initialize(){
		int r,g,b = 0;
		switch (allianceColor) {
		case 0:
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
			break;
		case 1:
			r = 1;
			g = b = 0;
			break;
		case 2:
			g = 1;
			r = b = 0;
			break;
		case 3:
			b = 1;
			r = g = 0;
			break;
		case 4:
			r = g = 1;
			b = 0;
			break;
		case 5:
			r = b = 1;
			g = 0;
			break;
		case 6:
			g = b = 1;
			r = 0;
			break;
		case 7:
			r = g = b = 1;
			break;
		}
		lights->setBottom(r,g,b);
	}
	virtual void Execute(){
		if (shooter->getErrorRPM() < shooter->getTollerance() * 2){
			lights->setTop(0,1,0);
		}
		else {
			lights->setTop(1,0,0);
		}
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){}
	virtual void Interrupted(){}
};

#endif /* UPDATELIGHTSCOMMAND_H_ */
