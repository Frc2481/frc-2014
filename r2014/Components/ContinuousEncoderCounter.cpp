/*
 * ContinuousEncoder.cpp
 *
 *  Created on: Jan 16, 2014
 *      Author: Team2481
 */

#include "ContinuousEncoderCounter.h"

ContinuousEncoderCounter::ContinuousEncoderCounter(uint32_t encoderChannel)
		:	mEncoder(new AnalogChannel(encoderChannel)),
		 	mPrevVoltage(0),
		 	mOffset(0),
		 	mRevCount(0),
		 	mSemaphore(semMCreate(SEM_Q_PRIORITY)),
		 	mUpdate(new Notifier(ContinuousEncoderCounter::UpdateEncoder, this)){
	
	mUpdate->StartPeriodic(.01);
}

ContinuousEncoderCounter::~ContinuousEncoderCounter() {
	// TODO Auto-generated destructor stub
}


void ContinuousEncoderCounter::UpdateEncoder(void* ptr) {
	ContinuousEncoderCounter* encoder = (ContinuousEncoderCounter*)ptr;
	encoder->Update();
}

void ContinuousEncoderCounter::Update() {
	float volts = GetVoltage();
	CRITICAL_REGION(mSemaphore) {
	
		if (mPrevVoltage > 4 && volts < 1) {
			mRevCount++;
		}
		
		if (mPrevVoltage < 1 && volts > 4) {
			mRevCount--;
		}
		mPrevVoltage = volts;
		printf("%d %f %f - %f = %f\n", mRevCount, GetVoltage(), 5 - mEncoder->GetAverageVoltage(), mOffset, GetScaledVoltage());
	}
	END_REGION;
}

float ContinuousEncoderCounter::GetVoltage() const {
	float volt;
	float offset;
	
	CRITICAL_REGION(mSemaphore) {
		volt = 5 - mEncoder->GetAverageVoltage();
		offset = mOffset;
	}
	END_REGION;
	
	if (volt - offset < 0)
		return (volt - offset) + 5;
	return volt - offset;
}

double ContinuousEncoderCounter::GetScaledVoltage() const {
	int count;
	float volt;
	
	CRITICAL_REGION(mSemaphore) {
		count = mRevCount;
		volt = GetVoltage();
	}
	END_REGION;
	
	return (count * .5) + ((volt /  5) * .5);
}

void ContinuousEncoderCounter::Zero() {
	CRITICAL_REGION(mSemaphore) {
		mRevCount = 0;
		mOffset = 5 - mEncoder->GetAverageVoltage();
		printf("RESET -- %d %f %f - %f = %f\n", mRevCount, GetVoltage(), 5 - mEncoder->GetAverageVoltage(), mOffset, GetScaledVoltage());
	}
	END_REGION;
}
