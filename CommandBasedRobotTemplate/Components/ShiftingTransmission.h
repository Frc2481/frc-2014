#ifndef SHIFTINGTRANSMISSION_H
#define SHIFTINGTRANSMISSION_H

#include "WPILib.h"
class ShiftingTransmission : public SpeedController {
private:
	SpeedController* motor;
	Solenoid* solenoid; 
	int loopCount;
	float motorSpeed; 
	bool isShiftingUp;
	bool isShiftingDown;
	bool isLowSpeed;

	void UpShift();
	void DownShift();
	void SetSolenoid(bool position);
	
public:
	ShiftingTransmission(SpeedController* m, Solenoid* s);
	~ShiftingTransmission();
	void Set(float speed, UINT8 syncGroup=0);
	float Get();
	bool IsLowSpeed();
	void Run();
	void Disable();
	void PIDWrite(float output);
	void ShiftUp();
	void ShiftDown();
};
#endif
