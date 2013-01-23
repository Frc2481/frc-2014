/*
 * Hopper.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Team2481
 */

#include "Hopper.h"

Hopper::Hopper(UINT32 solenoidChannel) : Subsystem("Hopper") {
	// TODO Auto-generated constructor stub
	solenoid = new Solenoid(solenoidChannel);
	frisbeeCount = 0;
}

Hopper::~Hopper() {
	// TODO Auto-generated destructor stub
}

void Hopper::Load() {
	solenoid->Set(1);
}

void Hopper::Retract() {
	solenoid->Set(0);
}

void Hopper::IncrementFrisbeeCount() {
	frisbeeCount++;
}

void Hopper::DecrementFrisbeeCount() {
	frisbeeCount--;
}

short Hopper::GetFrisbeeCount() {
	return frisbeeCount;
}
