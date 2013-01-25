/*
 * AirCompressor.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: Team2481
 */

#include "AirCompressor.h"

AirCompressor::AirCompressor(UINT32 sensor, UINT32 spike) : Subsystem("AirCompressor") {
	// TODO Auto-generated constructor stub
	compress = new Compressor(sensor, spike);
	compress->Start();

}

AirCompressor::~AirCompressor() {
	// TODO Auto-generated destructor stub
	delete compress;
}
