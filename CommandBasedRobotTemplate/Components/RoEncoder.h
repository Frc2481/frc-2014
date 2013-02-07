#ifndef RO_ENCODER_H_
#define RO_ENCODER_H_

#include "WPILib.h"
#include "Timer.h"

class RoEncoder : public PIDSource{
private:
	UINT32 mLastState;
	DigitalInput *mEncoder;
	float mSpeed;
	UINT32 tempcounter;
	double mStartTime;
	int mPulsePerRev;
	
	int mSpeedUpdateCounter;
	float mSpeedTotal;
public:
	RoEncoder(int sChannel, int sPulse = 6);
	virtual ~RoEncoder();
	double get();
	double PIDGet();
	void update();
	bool getIO () { return mEncoder->Get(); }
};
#endif
