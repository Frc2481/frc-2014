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

class Hopper: public Subsystem {

private:
	Solenoid *solenoid;
	short frisbeeCount;
	
public:
	Hopper(UINT32 solenoidChannel);
	virtual ~Hopper();
	void Load();
	void Retract();
	void IncrementFrisbeeCount();
	void DecrementFrisbeeCount();
};

#endif /* HOPPER_H_ */
