/*
 * Shooter.h
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "WPILIB.h"
#include "../Components/PController.h"
#include "../RobotParameters.h"

class Shooter: public Subsystem {
private:
	Talon *winch;
	AnalogChannel *winchSensor;
	Solenoid *shooterEars;
	Solenoid *release;
	float position;
public:
	Shooter(uint32_t winchChannel, uint32_t winchSensorChannel, uint32_t earChannel, uint32_t releaseChannel);
	virtual ~Shooter();
	void Fire(float distance);
	void Load();
	void SetEars(bool position);
	bool GetEars();
	void Periodic();
	void ManualRetractWinch();
	void ManualReleaseWinch();
	void ManualFire();
	void ManualStopWinch();
	void ManualLatch();
	void SetPosition(float pos);
	float GetSetPoint();
};

#endif /* SHOOTER_H_ */
