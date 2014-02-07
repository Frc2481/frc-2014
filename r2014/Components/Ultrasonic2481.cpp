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
	return (ultrasonic->GetAverageVoltage() - 2.5) * inchesPerVolt / 3;
}
void Ultrasonic2481::SetInchesPerVolt(float inchesPerVolt){
	this->inchesPerVolt = inchesPerVolt;
}