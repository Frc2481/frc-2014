/*
 * ClimbingHooks.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#include "ClimbingHooks.h"

ClimbingHooks::ClimbingHooks(UINT32 lockSolenoidChannel, UINT32 unlockSolenoidChannel, UINT32 leftMagnetChannel, UINT32 rightMagnetChannel) : Subsystem("ClimbingHooks") {
	lockHookSolenoid = new Solenoid(lockSolenoidChannel);	
	unlockHookSolenoid = new Solenoid(unlockSolenoidChannel);
	leftHookSensor = new DigitalInput(leftMagnetChannel);
	rightHookSensor = new DigitalInput(rightMagnetChannel);

}ClimbingHooks::ClimbingHooks(UINT32 lockSolenoidChannel, UINT32 unlockSolenoidChannel) : Subsystem("ClimbingHooks"){
	lockHookSolenoid = new Solenoid(lockSolenoidChannel);
	unlockHookSolenoid = new Solenoid(unlockSolenoidChannel);
	leftHookSensor = rightHookSensor = 0;
}

ClimbingHooks::~ClimbingHooks() {
	delete lockHookSolenoid;
	delete unlockHookSolenoid;
	if (leftHookSensor)
		delete leftHookSensor;
	if (rightHookSensor)
		delete rightHookSensor;
}

void ClimbingHooks::latch(){
	unlockHookSolenoid->Set(0);
	lockHookSolenoid->Set(1);
}
void ClimbingHooks::unlatch(){
	unlockHookSolenoid->Set(1);
	lockHookSolenoid->Set(0);
}
bool ClimbingHooks::isLatched(){
	//if (leftHookSensor && rightHookSensor)	
		//return leftHookSensor->Get() && rightHookSensor->Get();
	//else 
	bool isLatched = lockHookSolenoid->Get();
		return isLatched;
}
