#include "RGBLed.h"

RGBLed::RGBLed(UINT32 r, UINT32 g, UINT32 b, UINT32 m){
	mRed = new Solenoid(m, r);
	mGreen = new Solenoid(m, g);
	mBlue = new Solenoid(m, b);
	mColor = 0;
}
RGBLed::~RGBLed(){
	delete mRed;
	delete mGreen;
	delete mBlue;
}
void RGBLed::set(bool r, bool g, bool b){	
	mRed->Set(r);
	mGreen->Set(!g);
	mBlue->Set(b);
}
int RGBLed::get(){
	return mColor;
}
