/*
 * Encoder2481.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Team2481
 */

#ifndef ENCODER2481_H_
#define ENCODER2481_H_

#include "Counter.h"
#include "PIDSource.h"
#include "CounterBase.h"
#include "LiveWindow/LiveWindowSendable.h"
#include "SensorBase.h"

class Encoder2481 : public PIDSource, public LiveWindowSendable, public SensorBase {
private:
	Counter *pulseCounter;
	ITable *m_table;
	float speedTotal;
	int counter;
	float rpm;
public:
	Encoder2481(UINT32 channel);
	virtual ~Encoder2481();
	float GetPeriod();
	double PIDGet();
	void UpdateTable();
	void InitTable(ITable *subTable);
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	ITable* GetTable();
	std::string GetSmartDashboardType();
};

#endif /* ENCODER2481_H_ */