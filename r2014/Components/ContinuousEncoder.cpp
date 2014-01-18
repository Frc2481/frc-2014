/*
 * ContinuousEncoder.cpp
 *
 *  Created on: Jan 16, 2014
 *      Author: Team2481
 */

#include "ContinuousEncoder.h"

ContinuousEncoder::ContinuousEncoder(uint32_t encoderChannel):mEncoder(new AnalogChannel(encoderChannel)) {
	// TODO Auto-generated constructor stub
}

ContinuousEncoder::~ContinuousEncoder() {
	// TODO Auto-generated destructor stub
}
double ContinuousEncoder::PIDGet(){
	return ((mEncoder->GetAverageVoltage() - 0.015) / 4.972) * 360;
}

float ContinuousEncoder::getVoltage() {
	return mEncoder->GetAverageVoltage();
}
