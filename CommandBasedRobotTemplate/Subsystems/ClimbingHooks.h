/*
 * ClimbingHooks.h
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#ifndef CLIMBINGHOOKS_H_
#define CLIMBINGHOOKS_H_

#include "WPILib.h"

class ClimbingHooks : public Subsystem {
private:
	DigitalInput *leftHookSensor;
	DigitalInput *rightHookSensor;;
	Solenoid *lockHookSolenoid;
	Solenoid *unlockHookSolenoid;
	
public:
	ClimbingHooks(UINT32 lockSolenoidChannel, UINT32 unlockSolenoidChannel, UINT32 leftMangetChannel, UINT32 rightMagnetChannel);
	ClimbingHooks(UINT32 lockSolenoidChannel, UINT32 unlockSolenoidChannel);
	virtual ~ClimbingHooks();
	void latch();
	void unlatch();
	bool isLatched();
};

#endif /* CLIMBINGHOOKS_H_ */
