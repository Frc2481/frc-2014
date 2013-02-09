/*
 * Arm.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef Arm_H_
#define Arm_H_

#include "WPILib.h"

class Arm : public Subsystem {
private:
	static float speedRatioUp;
	static float speedRatioDown;
	static float armPositionTolerance;
	static float armHighPos;
	static float armLowPos;
	Talon *armLift;
	Talon *robotLift;
	AnalogChannel *armExtensionChannel;
	Solenoid *liftSolenoid;
	DigitalInput *liftExtendedSensor;
	DigitalInput *liftRetractedSensor;
	static float armSpeed;
	float desiredPosition;
	Solenoid *armTiltSolenoid;

public:
	Arm(UINT32 armLiftChannel, UINT32 robotLiftChannel, UINT32 armPosFarChannel, UINT32 armPosCloseChannel, UINT32 armExtendChannel, UINT32 armTiltChannel);
	virtual ~Arm();
//	virtual double ReturnPIDInput();
//	virtual void UsePIDOutput(double output);
	void setPosition(double position);
	float getCurrentPosition();
	double getDesiredPosition();
	void extendArm();
	void retractArm();
	void stopArm();
	bool isAtPosition();
	void run();
	void tiltForward();
	void tiltBackward();
};

#endif /* Arm_H_ */
