/*
 * HeadingSource.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Team2481
 */

#ifndef HEADINGSOURCE_H_
#define HEADINGSOURCE_H_
#include <WPILib.h>
#include <cmath>
#include "Compass.h"


class HeadingSource {
private:
	Gyro *gyro;
	Compass *compass;
	int gyroCounter;
	int compassCounter;
	float prevHeading;
	float prevCompass;
	
public:
	HeadingSource(uint32_t gyroChannel, uint8_t compassChannel);
	virtual ~HeadingSource();
	float GetHeading();
	void periodic();
	
};

#endif /* HEADINGSOURCE_H_ */
