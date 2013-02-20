/*
 * Lights.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Team2481
 */

#ifndef LIGHTS_H_
#define LIGHTS_H_

#include "Commands/Subsystem.h"
#include "../Components/RGBLed.h"
#include "../RobotMap.h"

class Lights: public Subsystem {

private:
	RGBLed* mBottom;
	RGBLed* mTop;
public:
	Lights();
	virtual ~Lights();
	void setTop(bool r, bool g, bool b);
	void setBottom(bool r, bool g, bool b);
	int getTop();
	int getBottom();
};

#endif /* LIGHTS_H_ */
