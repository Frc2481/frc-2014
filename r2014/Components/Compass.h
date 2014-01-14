/*
 * Compass.h
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#ifndef COMPASS_H_
#define COMPASS_H_
#include <WPILib.h>

class Compass {
public:
	Compass(uint8_t moduleNumber);
	virtual ~Compass();
	double GetAngle();
};

#endif /* COMPASS_H_ */
