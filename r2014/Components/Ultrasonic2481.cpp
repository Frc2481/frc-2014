/*
 * Ultrasonic2481.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#include "Ultrasonic2481.h"

Ultrasonic2481::Ultrasonic2481(uint32_t ultrasonicChannel) : 
			ultrasonic(new AnalogChannel(ultrasonicChannel)),
			lowPassFilter(.01, 1),
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
	float lowPass = lowPassFilter.Filter(volt);
	SmartDashboard::PutNumber("Ultrasonic Raw", ((volt * inchesPerVolt) / 12));
	SmartDashboard::PutNumber("Ultrasonic Lowpass", ((lowPass * inchesPerVolt) / 12));

	CRITICAL_REGION(ultrasonicSemaphore) {
		voltageAccum.add(lowPass);
		distance  = voltageAccum.avg() * inchesPerVolt;
	}
	END_REGION
	SmartDashboard::PutNumber("Ultrasonic Average", (voltageAccum.avg() * (inchesPerVolt / 12)));
}

void Ultrasonic2481::LoopPeriodic(void* instance) {
	Ultrasonic2481* ultrasonic = (Ultrasonic2481*) instance;
	ultrasonic->Update();
}
