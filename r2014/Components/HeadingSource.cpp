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
	return prevHeading + gyro->GetAngle();
}

void HeadingSource::periodic(){
	if (gyro->GetRate() < 1){
		gyroCounter++;
	}
	else {
		gyroCounter = 0;
	}
	
	if (fabs(prevCompass - compass->GetAngle()) < 10){
		compassCounter++;
	}
	else {
		compassCounter = 0;
	}
	
	if (compassCounter > 50 && gyroCounter > 50){
		prevHeading = compass->GetAngle();
		gyro->Reset();
	}
	prevCompass = compass->GetAngle();
	
}
