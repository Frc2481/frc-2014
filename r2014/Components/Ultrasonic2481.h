/*
 * Ultrasonic2481.h
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#ifndef ULTRASONIC2481_H_
#define ULTRASONIC2481_H_
#include <WPILib.h>
#include "../RobotParameters.h"
#include "RollingAccumulator.h"

class Ultrasonic2481 {
private:
	AnalogChannel *ultrasonic;
	float inchesPerVolt;
	RollingAccumulator<float, 30> voltageAccum;
	SEM_ID ultrasonicSemaphore;
	Notifier* ultrasonicUpdate;
	float distance;
public:
	Ultrasonic2481(uint32_t ultrasonicChannel);
	virtual ~Ultrasonic2481();
	float GetDistance();
	void SetInchesPerVolt(float inchesPerVolt);
	float GetRawVoltage();
	void Update();
	static void LoopPeriodic(void *controller);
};

#endif /* ULTRASONIC2481_H_ */
