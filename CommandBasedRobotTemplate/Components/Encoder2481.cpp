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
}

Encoder2481::~Encoder2481() {
	delete pulseCounter;
}

float Encoder2481::GetPeriod() {
	float rpm = 0;
	//return 1;
	rpm = (1 / (pulseCounter->GetPeriod())) * 60;
	if (StatusIsFatal()) return 0.0;
	if (rpm > 10000) return 0;
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
