/*
 * Compass.h
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#ifndef COMPASS_H_
#define COMPASS_H_
#include <WPILib.h>
#include "../Robotmap.h"

class Compass {
private:
	I2C* compass;
	double heading;
	SEM_ID semaphore;
	Notifier* update;
	
	enum Registers {
		CTRL1 = 0x20,
		CTRL5 = 0x24,
		CTRL6 = 0x25,
		CTRL7 = 0x26,
		CRA_REG_M = 0x00,
		MR_REG_M = 0x02,
		OUT_X_L_M = 0x08,
		OUT_X_H_M = 0x09,
		OUT_Y_L_M = 0x0a,
		OUT_Y_H_M = 0x0b,
		OUT_Z_L_M = 0x0c,
		OUT_Z_H_M = 0x0d,
	};
public:
	Compass(uint8_t moduleNumber);
	
	virtual ~Compass();
	void Init();
	void Update();
	static void UpdateCompass(void* compass);
	double GetAngle();
};

#endif /* COMPASS_H_ */
