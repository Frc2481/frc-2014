/*
 * Climber.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef CLIMBER_H_
#define CLIMBER_H_

#include "WPILib.h"

class Climber : public PIDSubsystem {
private:
	Talon *armLift;
	Talon *robotLift;
	DigitalInput *armPositionFar;
	DigitalInput *armPositionClose;
	AnalogChannel *armExtensionChannel;
	Solenoid *hookSolenoid;
	Solenoid *liftSolenoid;
	
	
public:
	Climber();
	virtual ~Climber();
};

#endif /* CLIMBER_H_ */
