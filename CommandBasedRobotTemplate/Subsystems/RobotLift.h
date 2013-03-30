/*
 * RobotLift.h
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#ifndef ROBOTLIFT_H_
#define ROBOTLIFT_H_

#include "WPILib.h"

class RobotLift : Subsystem{
private:
	Solenoid *liftSolenoid;
	DigitalInput *liftSensor;
	Solenoid *lrRobotFlip;
public:
	RobotLift(UINT32 liftSolenoidChannel, UINT32 liftSensorChannel, UINT32 lrFlipChannel);
	virtual ~RobotLift();
	void lift();
	void lower();
	void flip();
	void retractFlip();
	bool isLifted();
};

#endif /* ROBOTLIFT_H_ */
