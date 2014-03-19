/*
 * LowPassFilter.h
 *
 *  Created on: Mar 10, 2014
 *      Author: Team2481
 */

#ifndef LOWPASSFILTER_H_
#define LOWPASSFILTER_H_

class LowPassFilter {

private:
	double mDT;
	double mRC;
	double mAlpha;
	double mPrev;
	static const double pi = 3.14159;

public:
	LowPassFilter(double dt, double fc);
	virtual ~LowPassFilter();
	void SetCutoffFreq(double fc);
	double Filter(double s);

};

#endif /* LOWPASSFILTER_H_ */
