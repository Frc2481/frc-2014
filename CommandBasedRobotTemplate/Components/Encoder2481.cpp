/*
 * Encoder2481.cpp
 *
 *  Created on: Feb 5, 2013
 *      Author: Team2481
 */

#include "Encoder2481.h"
#include "ErrorBase.h"

Encoder2481::Encoder2481(UINT32 channel) {
	pulseCounter = new Counter(channel);
	pulseCounter->Start();
	total = 0;
	memset(speedArray, 0, SHOOTER_AVERAGE_SAMPLES * sizeof(float));
	speedArrayIndex = 0;
}

Encoder2481::~Encoder2481() {
	delete pulseCounter;
}

float Encoder2481::GetAveragePeriod() {
	float currentPeriod = (1 / (pulseCounter->GetPeriod())) * 60;
//	return currentPeriod;
	if (currentPeriod > 100 && currentPeriod < 6000) {
		//printf("totalBefore %f \n", total);
		total -= speedArray[speedArrayIndex];
		//printf("totalAfter %f \n", total);
		//printf("CurrentPeriod %f \n", currentPeriod);
		//printf("SpeedArray at Index %f \n", speedArray[speedArrayIndex]);
		//printf("SpeedArrayIndex %d \n", speedArrayIndex);
		speedArray[speedArrayIndex++] = currentPeriod;
		speedArrayIndex = speedArrayIndex % SHOOTER_AVERAGE_SAMPLES;
		total += currentPeriod;
	}
	return total / SHOOTER_AVERAGE_SAMPLES;
}

double Encoder2481::PIDGet() {
	//printf("PulseCounter: %d", pulseCounter->Get());
	return GetAveragePeriod();
}
void Encoder2481::UpdateTable() {
	if (m_table != NULL) {
		m_table->PutNumber("Speed", GetAveragePeriod());
	}
}
void Encoder2481::InitTable(ITable *subTable) {
	m_table = subTable;
	UpdateTable();
}

void Encoder2481::StartLiveWindowMode() {

}

void Encoder2481::StopLiveWindowMode() {

}
std::string Encoder2481::GetSmartDashboardType() {
	return "Encoder";
}

ITable * Encoder2481::GetTable() {
	return m_table;
}
void Encoder2481::resetAverage(){
	total = 0;
	memset(speedArray, 0, 9 * sizeof(float));
}
