/*
 * Ultrasonic2481.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#include "Ultrasonic2481.h"

Ultrasonic2481::Ultrasonic2481(uint32_t ultrasonicChannel) : 
	ultrasonic(new AnalogChannel(ultrasonicChannel)){
}

Ultrasonic2481::~Ultrasonic2481() {
	// TODO Auto-generated destructor stub
}
float Ultrasonic2481::GetDistance(){
	voltageAccum.add(ultrasonic->GetAverageVoltage());
	return voltageAccum.avg() * inchesPerVolt;
}
void Ultrasonic2481::SetInchesPerVolt(float inchesPerVolt){
	this->inchesPerVolt = inchesPerVolt;
}
float Ultrasonic2481::GetRawVoltage(){
	voltageAccum.add(ultrasonic->GetAverageVoltage());
	return voltageAccum.avg();
}
