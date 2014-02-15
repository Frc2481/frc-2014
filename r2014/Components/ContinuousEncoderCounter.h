/*
 * ContinuousEncoder.h
 *
 *  Created on: Jan 16, 2014
 *      Author: Team2481
 */

#ifndef CONTINUOUSENCODERCOUNTER_H_
#define CONTINUOUSENCODERCOUNTER_H_
#include "WPILib.h"

class ContinuousEncoderCounter {//: public PIDSource {
private:
	AnalogChannel *mEncoder;
	float mPrevVoltage;
	float mOffset;
	int mRevCount;

	SEM_ID mSemaphore;
	Notifier* mUpdate;
	
public:
	ContinuousEncoderCounter(uint32_t encoderChannel);
	virtual ~ContinuousEncoderCounter();
    double GetScaledVoltage() const;
    float GetVoltage() const;
    void Zero();
    static void UpdateEncoder(void *ptr);
    void Update();
};

#endif /* CONTINUOUSENCODER_H_ */
