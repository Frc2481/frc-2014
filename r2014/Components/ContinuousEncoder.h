/*
 * ContinuousEncoder.h
 *
 *  Created on: Jan 16, 2014
 *      Author: Team2481
 */

#ifndef CONTINUOUSENCODER_H_
#define CONTINUOUSENCODER_H_
#include "WPILib.h"

class ContinuousEncoder: public PIDSource {
private:
	AnalogChannel *mEncoder;
	
public:
	ContinuousEncoder(uint32_t encoderChannel);
	virtual ~ContinuousEncoder();
	virtual double PIDGet();
	float getVoltage();
	
};

#endif /* CONTINUOUSENCODER_H_ */
