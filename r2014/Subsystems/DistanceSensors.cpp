/*
 * DistanceSensors.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#include "DistanceSensors.h"

DistanceSensors::DistanceSensors(uint32_t rightSensorChannel, uint32_t leftSensorChannel)
		: Subsystem("DistanceSensors"),
		rightSensor(new Ultrasonic2481(rightSensorChannel)),
		leftSensor(new Ultrasonic2481(leftSensorChannel)){
	rightSensor->SetInchesPerVolt(102.041);
	leftSensor->SetInchesPerVolt(102.041);
}

DistanceSensors::~DistanceSensors() {
	delete rightSensor;
	delete leftSensor;
}

float DistanceSensors::Get(){
	float sum = rightSensor->GetDistance() + leftSensor->GetDistance();
	float avg = sum / 2;
	return avg / 12;
}
float DistanceSensors::GetRight(){
	return rightSensor->GetDistance();
}
float DistanceSensors::GetLeft(){
	return leftSensor->GetDistance();
}
