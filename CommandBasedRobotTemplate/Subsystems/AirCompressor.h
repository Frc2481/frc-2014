/*
 * AirCompressor.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#ifndef AIRCOMPRESSOR_H_
#define AIRCOMPRESSOR_H_

#include "WPILib.h"

class AirCompressor: public Subsystem {
private:
	Compressor* compress;
public:
	AirCompressor(UINT32 sensor, UINT32 spike);
	virtual ~AirCompressor();
};

#endif /* AIRCOMPRESSOR_H_ */
