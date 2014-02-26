/*
 * Lights.h
 *
 *  Created on: Feb 25, 2014
 *      Author: thomasSpeciale
 */

#ifndef LIGHTS_H_
#define LIGHTS_H_

#include <WPILib.h>

class Lights : public Subsystem {
private:
	DigitalOutput *DO1;
	DigitalOutput *DO2;
	DigitalOutput *DO3;
	DigitalOutput *DO4;
public:
	Lights(uint32_t DO1Channel, uint32_t DO2Channel, uint32_t DO3Channel, uint32_t DO4Channel);
	virtual ~Lights();
	void SetColor(bool r, bool g, bool b);
	void Standby();
	void SetForward(bool forward);
};

#endif /* LIGHTS_H_ */
