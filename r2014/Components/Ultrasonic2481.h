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

class Ultrasonic2481 {
private:
	AnalogChannel *ultrasonic;
public:
	Ultrasonic2481(uint32_t ultrasonicChannel);
	virtual ~Ultrasonic2481();
	float GetDistance();
};

#endif /* ULTRASONIC2481_H_ */
