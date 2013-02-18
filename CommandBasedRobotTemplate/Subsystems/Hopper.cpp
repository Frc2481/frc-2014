/*
 * Hopper.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Team2481
 */

#include "Hopper.h"

Hopper::Hopper(UINT32 solenoidChannel, UINT32 lidSolenoidChannel) : Subsystem("Hopper") {
	solenoid = new Solenoid(solenoidChannel);
	frisbeeCount = 0;
	lidSolenoid = new Solenoid(lidSolenoidChannel);
	lidSolenoid->Set(1);
}

Hopper::~Hopper() {
	delete solenoid;
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

void Hopper::open(){
	lidSolenoid->Set(1);
}
void Hopper::close(){
	lidSolenoid->Set(0);
}
bool Hopper::isOpen(){
	return lidSolenoid->Get();
}
