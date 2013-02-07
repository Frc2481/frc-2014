#include "RoEncoder.h"

RoEncoder::RoEncoder(int sChannel, int sPulse){
	mEncoder = new DigitalInput(sChannel);
	mSpeed = 0;
	mLastState = 0;
	mStartTime = GetTime();
	mPulsePerRev = sPulse;
	mSpeedUpdateCounter = 0;
	mSpeedTotal = 0;
	tempcounter = 0;
}
RoEncoder::~RoEncoder(){
	delete mEncoder;
}
double RoEncoder::get(){
	//update();
	return mSpeed;
}
double RoEncoder::PIDGet(){
	return get();
}
void RoEncoder::update(){
	UINT32 encoderIsOn = mEncoder->Get();
	//if(encoderIsOn) {
		if (encoderIsOn != mLastState) {
			mSpeedTotal += 1 / ((GetTime() - mStartTime) * mPulsePerRev);
			mStartTime = GetTime();
			mSpeedUpdateCounter++;
			if (mSpeedUpdateCounter == 9) {
				mSpeed = mSpeedTotal / 9;
				mSpeedTotal = 0;
				mSpeedUpdateCounter = 0;
			}
		}
	//}
	mLastState = encoderIsOn;
}
