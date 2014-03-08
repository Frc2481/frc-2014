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
	double d;

	CRITICAL_REGION(ultrasonicSemaphore) {
		d = distance;
	}
	END_REGION

	return d;
}
void Ultrasonic2481::SetInchesPerVolt(float inchesPerVolt){
	CRITICAL_REGION(ultrasonicSemaphore) {
		this->inchesPerVolt = inchesPerVolt;
	}
	END_REGION
}
float Ultrasonic2481::GetRawVoltage(){
	CRITICAL_REGION(ultrasonicSemaphore) {
		voltageAccum.add(ultrasonic->GetVoltage());
		return voltageAccum.avg();
	}
	END_REGION
}

void Ultrasonic2481::Update(){
	float volt = ultrasonic->GetAverageVoltage();

	CRITICAL_REGION(ultrasonicSemaphore) {
		voltageAccum.add(volt);
		distance  = voltageAccum.avg() * inchesPerVolt;
	}
	END_REGION
}

void Ultrasonic2481::LoopPeriodic(void* instance) {
	Ultrasonic2481* ultrasonic = (Ultrasonic2481*) instance;
	ultrasonic->Update();
}
