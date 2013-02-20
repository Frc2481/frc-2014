#ifndef RGB_LED_H_
#define RGB_LED_H_

#include "WPILib.h"

class RGBLed {
private:
	Solenoid* mRed;
	Solenoid* mGreen;
	Solenoid* mBlue;
	int mColor;
	
public:
	RGBLed(UINT32 r, UINT32 g, UINT32 b, UINT32 m = 1);
	virtual ~RGBLed();
	void set(bool r, bool g, bool b);
	int get();
};
#endif
