/*
 * HeadingSource.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Team2481
 */

#ifndef HEADINGSOURCE_H_
#define HEADINGSOURCE_H_
#include <WPILib.h>
#include <cmath>
//#include "Compass.h"
#include "LSM303.h"
#include "RollingAccumulator.h"
#include "../PersistedSettings.h"
#include "../CSVRecord.h"
#include <string>
#include "WiiGyro.h"

#define GYRO_AVG_SAMPLES 20
#define COMPASS_AVG_SAMPLES 10

class HeadingSource {
private:
	CSVRecord& csvFile;
	Gyro *gyro;
	LSM303 *compass;
	WiiGyro *wiiGyro;
	int gyroCounter;
	int compassCounter;
	float prevHeading;
	float prevCompass;
	float fieldHeadingOffset;
	float heading;
	float zeroCompassAngle;
	bool resetWii;

	
	LSM303::vector<int16_t> runningMin;
	LSM303::vector<int16_t> runningMax;
	

	RollingAccumulator<float, GYRO_AVG_SAMPLES> _gyroSinAccum;
	RollingAccumulator<float, GYRO_AVG_SAMPLES> _gyroCosAccum;

	RollingAccumulator<float, COMPASS_AVG_SAMPLES> _compassSinAccum;
	RollingAccumulator<float, COMPASS_AVG_SAMPLES> _compassCosAccum;
	RollingAccumulator<float, 10> _gyroRateAccum;
	
public:
	HeadingSource(uint32_t gyroChannel, uint8_t compassChannel);
	virtual ~HeadingSource();
	float GetHeading();
	void periodic();
    void setFieldHeadingOffset(float fieldHeadingOffset);
    void ResetGyro();
    void CalibrateCompass();
	void CompassPeriodic(bool done = false);
	void CompassInit();
	void SetOffset();
	bool ResetWii();
	void SetZeroAngle();
};

#endif /* HEADINGSOURCE_H_ */
