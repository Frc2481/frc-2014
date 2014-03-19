/*
 * LowPassFilter.cpp
 *
 *  Created on: Mar 10, 2014
 *      Author: Team2481
 */

#include "LowPassFilter.h"
#include <cmath>

LowPassFilter::LowPassFilter(double dt, double fc)
		: mDT(dt), mRC(0), mAlpha(0), mPrev(-1){
	SetCutoffFreq(fc);

}

LowPassFilter::~LowPassFilter() {
	// TODO Auto-generated destructor stub
}

void LowPassFilter::SetCutoffFreq(double fc) {
	mRC = 1 / (fc * 2 * pi);
	mAlpha = mDT / (mRC + mDT);
}

double LowPassFilter::Filter(double s) {
	if (mPrev == -1) {
		mPrev = s;
	} else {
		mPrev = mAlpha * s + (1-mAlpha) * mPrev;
	}
	return mPrev;
}
