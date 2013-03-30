/*
 * TipSensor.h
 *
 *  Created on: Mar 28, 2013
 *      Author: Team2481
 */

#ifndef TIPSENSOR_H_
#define TIPSENSOR_H_

#include "WPILib.h"
#include "../Robotmap.h"
#include "../RobotParameters.h"

class TipSensor: public Subsystem {
private:
	AnalogChannel *accelYAxis;
	AnalogChannel *accelZAxis;
	int YAxisCounter;
	int ZAxisCounter;
	bool isTipped;
	int ZAxisBackCounter;
public:
	TipSensor();
	float GetYAxis();
	float GetZAxis();
	int IsTipped();
	void Periodic();
	virtual ~TipSensor();
};

#endif /* TIPSENSOR_H_ */
