/*
 * Hopper.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Team2481
 */

#ifndef HOPPER_H_
#define HOPPER_H_

#include "Commands/Subsystem.h"
#include "Solenoid.h"
#include "Servo.h"

class Hopper: public Subsystem {

private:
	Solenoid *solenoid;
	short frisbeeCount;
	Servo *hopperPressurizer;
	
public:
	Hopper(UINT32 solenoidChannel, UINT32 servoChannel);
	virtual ~Hopper();
	void Load();
	void Retract();
	void IncrementFrisbeeCount();
	void DecrementFrisbeeCount();
	short GetFrisbeeCount();
	void addPressure();
	void removePressure();
	bool isPressurized();
};

#endif /* HOPPER_H_ */
