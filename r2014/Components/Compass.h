/*
 * Compass.h
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#ifndef COMPASS_H_
#define COMPASS_H_
#include <WPILib.h>

class Compass {
private:
	I2C* compass;
	double heading;
	
	enum Registers {
		CRA_REG_M = 0x00,
		MR_REG_M = 0x02,
		OUT_X_H_M = 0x03,
		OUT_X_L_M = 0x04,
		OUT_Y_H_M = 0x05,
		OUT_Y_L_M = 0x06,
		OUT_Z_H_M = 0x07,
		OUT_Z_L_M = 0x08,
		
	};
public:
	Compass(uint8_t moduleNumber);
	
	virtual ~Compass();
	void Init();
	void Update();
	double GetAngle();
};

#endif /* COMPASS_H_ */
