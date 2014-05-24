#include "CurrentMonitor.h"
#include <cmath>

CurrentMonitor::CurrentMonitor(UINT32 currentMonitorChannel) :
		prev(0) {
	currentMonitor = new AnalogChannel(currentMonitorChannel);
}
float CurrentMonitor::GetScaledAmps(){

	float amps = (200*(currentMonitor->GetVoltage() - 2.506123)) / -0.625;
	SmartDashboard::PutNumber("Raw Current", amps);
	float finalAmps = ((prev * 20) + amps) / 21;
	//float finalAmps = (prev + amps) / 2;
	prev = finalAmps;
	return fabs(finalAmps);
}
