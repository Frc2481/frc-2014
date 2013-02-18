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
	Solenoid *lidSolenoid;
	
public:
	Hopper(UINT32 solenoidChannel, UINT32 lidSolenoidChannel);
	virtual ~Hopper();
	void Load();
	void Retract();
	void IncrementFrisbeeCount();
	void DecrementFrisbeeCount();
	short GetFrisbeeCount();
	void open();
	void close();
	bool isOpen();
};

#endif /* HOPPER_H_ */
