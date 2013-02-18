/*
 * Encoder2481.cpp
 *
 *  Created on: Feb 5, 2013
 *      Author: Team2481
 */

#include "Encoder2481.h"
#include "ErrorBase.h"

Encoder2481::Encoder2481(UINT32 channel){
	pulseCounter = new Counter(channel);
	pulseCounter->Start();
	averageRPM = 0;
	memset(speedArray, 0, 9 * sizeof(float));
	speedArrayIndex = 0;
}

Encoder2481::~Encoder2481() {
	delete pulseCounter;
}

float Encoder2481::GetAveragePeriod() {
	float currentPeriod = (1 / (pulseCounter->GetPeriod())) * 60;
	
	if (currentPeriod > 500 && currentPeriod < 6000) {
		averageRPM = (averageRPM * 9) - speedArray[speedArrayIndex];
		speedArray[speedArrayIndex++] = currentPeriod;
		speedArrayIndex = speedArrayIndex % 10;
		averageRPM = (averageRPM + currentPeriod) / 9;
	}
	return averageRPM;
}

double Encoder2481::PIDGet() {
	//printf("PulseCounter: %d", pulseCounter->Get());
	return GetAveragePeriod(); 
}
void Encoder2481::UpdateTable(){
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
