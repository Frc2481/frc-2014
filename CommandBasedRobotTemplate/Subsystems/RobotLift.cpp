/*
 * RobotLift.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Team2481
 */

#include "RobotLift.h"

RobotLift::RobotLift(UINT32 liftSolenoidChannel, UINT32 liftSensorChannel) : Subsystem("RobotLift") {
	liftSolenoid = new Solenoid(liftSolenoidChannel);
	liftSensor = new DigitalInput(liftSensorChannel);
}

RobotLift::~RobotLift() {
	delete liftSolenoid;
	delete liftSensor;
}
void RobotLift::lift(){
	liftSolenoid->Set(1);
}
void RobotLift::lower(){
	liftSolenoid->Set(0);
}
bool RobotLift::isLifted(){
	return liftSolenoid->Get(); //TODO change to sensor
}
