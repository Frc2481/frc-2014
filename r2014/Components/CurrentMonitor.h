#include "WPILib.h"

class CurrentMonitor {
private:
	AnalogChannel *currentMonitor;
	float prev;
public:
	CurrentMonitor(UINT32 currentMonitorChannel);
	float GetScaledAmps();
};
