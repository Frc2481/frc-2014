/*
 * TipSensor.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: Team2481
 */

#include "TipSensor.h"

TipSensor::TipSensor() : Subsystem("TipSensor"){
	accelYAxis = new AnalogChannel(ACCEL_Y_CHANNEL);
	accelZAxis = new AnalogChannel(ACCEL_Z_CHANNEL);
	isTipped = false;
	ZAxisCounter = 0;
	ZAxisBackCounter = 0;
}

TipSensor::~TipSensor() {
	delete accelZAxis;
	delete accelYAxis;
}
float TipSensor::GetYAxis(){
	return accelYAxis->GetAverageVoltage();
}
float TipSensor::GetZAxis(){
	return accelZAxis->GetAverageVoltage();
}
void TipSensor::Periodic(){
	if (!isTipped){
		if (GetZAxis() > TIP_FORWARD_THRESHOLD){
			ZAxisCounter = ZAxisCounter < 0 ? 0 : ZAxisCounter;
			ZAxisCounter++;
		}
		else if (GetZAxis() < TIP_BACKWARD_THRESHOLD){
			ZAxisCounter = ZAxisCounter > 0 ? 0 : ZAxisCounter; 
			ZAxisCounter--;
		}
		else {
			ZAxisCounter = 0;
		}

		if (ZAxisCounter > 6){
			isTipped = true;
			ZAxisBackCounter = 0;
		}
		else if (ZAxisCounter < -4){
			isTipped = true;
			ZAxisBackCounter = 0;
		}
	}
	
	if (isTipped){
		if (GetZAxis() < TIP_FORWARD_THRESHOLD - 0.1 && GetZAxis() > TIP_BACKWARD_THRESHOLD + 0.1){
			ZAxisBackCounter++;
		}
		
		if (ZAxisBackCounter > 3){
			isTipped = false;
			ZAxisCounter = 0;
		}
	}	
}
int TipSensor::IsTipped(){
	if (ZAxisCounter > 6){
		return 1;
	}
	else if (ZAxisCounter < -4){
		return -1;
	}
	else {
		return 0; 
	}
}
