/*
 * Joystick2481.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Team2481
 */

#include "Joystick2481.h"

#define MAX_AXIS_VALUE 0.126
#define MIN_AXIS_VALUE -0.102

Joystick2481::Joystick2481(UINT32 port) : Joystick(port) {
	// TODO Auto-generated constructor stub

}

Joystick2481::~Joystick2481() {
	// TODO Auto-generated destructor stub
}

float Joystick2481::GetRawAxis(UINT32 axis) {
	float axisValue = Joystick::GetRawAxis(axis);
	if (axisValue > MAX_AXIS_VALUE || axisValue < MIN_AXIS_VALUE) {
		return axisValue;
	}
	else {
		return 0;
	}
	
}

