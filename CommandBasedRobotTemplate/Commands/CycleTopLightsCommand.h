/*
 * CycleLightsCommand.h
 *
 *  Created on: Feb 18, 2013
 *      Author: Team2481
 */

#ifndef CYCLETOPLIGHTSCOMMAND_H_
#define CYCLETOPLIGHTSCOMMAND_H_
#include "../CommandBase.h"



class CycleTopLightsCommand : public CommandBase{
private:
	static int color;
public:
	CycleTopLightsCommand() : CommandBase("cycleTopLightsCommand"){
		Requires(lights);
	}
	virtual ~CycleTopLightsCommand(){}
	void Initialize(){
		
	}
	void Execute(){
		int r,g,b = 0;
		switch (color) {
		case 0:
			r = g = b = 0;
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
		lights->setTop(r,g,b);
		
	}
	bool IsFinished(){
		return true;
	}
	void End(){
		color = (color + 1) %8;
	}
	void Interrupted(){
		color = (color + 1) %8;
	}
};
int CycleTopLightsCommand::color = 0;

#endif /* CYCLETOPLIGHTSCOMMAND_H_ */
