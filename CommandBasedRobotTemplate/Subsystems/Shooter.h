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
#include "../Components/Encoder2481.h"

class Shooter: public PIDSubsystem {
private:
	Talon *shooterMotor;
	//RoEncoder *shooterEncoder;
	Encoder2481 *shooterEncoder;
	bool shooterState;
	Solenoid *shooterLiftSolenoid;
	Servo *hopperPressurizer;
	static float shooterSpeedTolerance;
	static double pValue;
	static double iValue;
	static double dValue;
	static double fValue;
	static double periodValue;
public:
	Shooter(UINT32 motorChannel, UINT32 encoderChannel, UINT32 solenoidChannel);
	virtual ~Shooter();
	void setSpeed(double speed);
	void turnOn();
	void turnOff();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
	bool isShooterOn();
	void LiftShooter();
	void LowerShooter();
	bool isShooterUp();
	bool isAtSpeed();
	float getCurrentSpeed();
	double getDesiredSpeed();
};

#endif /* SHOOTER_H_ */
