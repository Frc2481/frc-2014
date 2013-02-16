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
	speedTotal = 0;
	counter = 0;
	rpm = 0;
}

Encoder2481::~Encoder2481() {
	delete pulseCounter;
}

float Encoder2481::GetPeriod() {
	float currentPeriod = 0;
	
	currentPeriod = (1 / (pulseCounter->GetPeriod())) * 60;
	
	if (currentPeriod > 10000) currentPeriod = 0; // handle inf
	
	speedTotal += currentPeriod;
	counter ++;
	
	if (counter == 9){
		rpm = speedTotal / counter;
		speedTotal = 0;
		counter = 0;
	}

	return rpm;
}

double Encoder2481::PIDGet() {
	//printf("PulseCounter: %d", pulseCounter->Get());
	return GetPeriod(); 
}
void Encoder2481::UpdateTable(){
	if (m_table != NULL) {
	        m_table->PutNumber("Speed", GetPeriod());
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
