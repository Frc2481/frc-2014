/*
 * HeadingSource.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Team2481
 */

#include "HeadingSource.h"

HeadingSource::HeadingSource(uint32_t gyroChannel, uint8_t compassChannel) {
	gyro = new Gyro(gyroChannel);
	compass = new Compass(compassChannel);
	prevHeading = 0;
	compassCounter = 0;
	gyroCounter = 0;
	prevCompass = 0;
}

HeadingSource::~HeadingSource() {
	delete gyro;
	delete compass;
}

float HeadingSource::GetHeading(){
	return (int)(fieldHeadingOffset + prevHeading + gyro->GetAngle())%360;
}


void HeadingSource::setFieldHeadingOffset(float offset)
{
    fieldHeadingOffset = offset;
}

void HeadingSource::periodic(){
	double compassAngle = compass->GetAngle();
	
	if (gyro->GetRate() < 1){  // !!! need to make sure we get absolute value
		gyroCounter++;
	}
	else {
		gyroCounter = 0;
	}
	   // Is Compass stable?
    if(fabs(prevCompass - compassAngle) < 10){  // !!! Need to better handle slow change over time in compass
		compassCounter++;
	}
	else {
		compassCounter = 0;
	}
	
	if (compassCounter > 50 && gyroCounter > 50){
		prevHeading = compassAngle;
		gyro->Reset();   // !!! Jonathan:  Reset counter vars!
	}
	
	prevCompass = compassAngle;
}
