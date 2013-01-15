#ifndef SHIFTINGTRANSMISSION_H
#define SHIFTINGTRANSMISSION_H

#include "WPILib.h"
class ShiftingTransmission {
private:
	SpeedController* motor;
	Encoder* encoder;
	Solenoid* solenoid;
	INT32 upShiftThreshold;
	INT32 downShiftThreshold; 
	int loopCount;
	float motorSpeed; 
	float beforeShiftSpeed;
	bool isShiftingUp;
	bool isShiftingDown;
	bool enabled;

	void UpShift();
	void DownShift();
	
public:
	ShiftingTransmission(SpeedController* m, Encoder* e, Solenoid* s);
	~ShiftingTransmission();
	void Set(float speed);
	float Get();
	bool IsHighSpeed();
	bool IsLowSpeed();
	void SetUpShiftThreshold(UINT32);
	void SetDownShiftTheshold(UINT32);
	UINT32 GetUpShiftThreshold();
	UINT32 GetDownShiftThreshold();
	void Run();
	void SetEnabled(bool enableState);
	
};
#endif
