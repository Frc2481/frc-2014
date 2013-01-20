/*
 * Shooter.h
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"

class Shooter: public PIDSubsystem {
private:
	Talon *shooterMotor;
	Encoder *shooterEncoder;
	bool shooterState;
public:
	Shooter(UINT32 motorChannel, UINT32 encoderChannelA, UINT32 encoderChannelB);
	virtual ~Shooter();
	void setSpeed(double speed);
	void turnOn();
	void tunOff();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
	bool isShooterOn();
	
};

#endif /* SHOOTER_H_ */
