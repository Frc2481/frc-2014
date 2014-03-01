/*
 * Ultrasonic2481.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#include "Ultrasonic2481.h"

Ultrasonic2481::Ultrasonic2481(uint32_t ultrasonicChannel) : 
			ultrasonic(new AnalogChannel(ultrasonicChannel)),
			ultrasonicSemaphore(semMCreate(SEM_Q_PRIORITY)),
			ultrasonicUpdate(new Notifier(Ultrasonic2481::LoopPeriodic, this)),
			distance(0){

	ultrasonicUpdate->StartPeriodic(.01);
}

Ultrasonic2481::~Ultrasonic2481() {
	// TODO Auto-generated destructor stub
}
float Ultrasonic2481::GetDistance(){
	return distance;
}
void Ultrasonic2481::SetInchesPerVolt(float inchesPerVolt){
	this->inchesPerVolt = inchesPerVolt;
}
float Ultrasonic2481::GetRawVoltage(){
	voltageAccum.add(ultrasonic->GetVoltage());
	return voltageAccum.avg();
}
void Ultrasonic2481::Update(){
	voltageAccum.add(ultrasonic->GetAverageVoltage());
	distance  = voltageAccum.avg() * inchesPerVolt;
}
void Ultrasonic2481::LoopPeriodic(void* instance) {
	Ultrasonic2481* ultrasonic = (Ultrasonic2481*) instance;
	ultrasonic->Update();
}
