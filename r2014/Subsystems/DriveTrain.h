/*
 * DriveTrain.h
 *
 *  Created on: Jan 9, 2014
 *      Author: Team2481
 */

#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

class DriveTrain {

private:
	static const double pi = 3.14159;
	static const float baseWidth = 0;
	static const float baseLength = 0;
public:
	DriveTrain();
	virtual ~DriveTrain();
	void Crab(float xPos, float yPos, float twist, bool useGyro);
};

#endif /* DRIVETRAIN_H_ */
