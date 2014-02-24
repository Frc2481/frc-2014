/*
 * DistanceSensors.h
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#ifndef DISTANCESENSORS_H_
#define DISTANCESENSORS_H_

#include <WPILib.h>
#include "../Components/Ultrasonic2481.h"

class DistanceSensors: public Subsystem {
private:
	Ultrasonic2481 *rightSensor;
	//Ultrasonic2481 *leftSensor;
public:
	DistanceSensors(uint32_t right);
	virtual ~DistanceSensors();
	float Get();
	float GetRight();
	float GetLeft();
};

#endif /* DISTANCESENSORS_H_ */
