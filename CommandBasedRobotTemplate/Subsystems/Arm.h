/*
 * Arm.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef Arm_H_
#define Arm_H_

#include "WPILib.h"

class Arm : public PIDSubsystem {
private:
	static float speedRatioUp;
	static float speedRatioDown;
	static float armPositionTolerance;
	Talon *armLift;
	Talon *robotLift;
	DigitalInput *armPositionFar;
	DigitalInput *armPositionClose;
	AnalogChannel *armExtensionChannel;
	Solenoid *liftSolenoid;
	DigitalInput *liftExtendedSensor;
	DigitalInput *liftRetractedSensor;
	static float armSpeed;

public:
	Arm(UINT32 armLiftChannel, UINT32 robotLiftChannel, UINT32 armPosFarChannel, UINT32 armPosCloseChannel, UINT32 armExtendChannel);
	virtual ~Arm();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
	void setPosition(double position);
	float getCurrentPosition();
	double getDesiredPosition();
	void extendArm();
	void retractArm();
	void stopArm();
	bool isAtPosition();
};

#endif /* Arm_H_ */
