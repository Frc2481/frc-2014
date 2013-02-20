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
	/*mColor = c;
	int r, g, b;
	switch (mColor) {
	case 0:
		r = g = b = 0;
		break;
	case 1:
		r = 1;
		g = b = 0;
		break;
	case 2:
		g = 1;
		r = b = 0;
		break;
	case 3:
		r = g = 1;
		b = 0;
		break;
	case 4:
		b = 1;
		r = g = 0;
		break;
	case 5:
		r = b = 1;
		g = 0;
		break;
	case 6:
		g = b = 1;
		r = 0;
		break;
	case 7:
		r = g = b = 1;
		break;
	}
	g = !(bool)g;*/
	
	mRed->Set(r);
	mGreen->Set(!g);
	mBlue->Set(b);
	
}
int RGBLed::get(){
	return mColor;
}
