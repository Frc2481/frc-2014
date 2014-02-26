/*
 * Lights.cpp
 *
 *  Created on: Feb 25, 2014
 *      Author: thomasSpeciale, paulRich
 */

#include "Lights.h"

Lights::Lights(uint32_t DO1Channel, uint32_t DO2Channel, uint32_t DO3Channel, uint32_t DO4Channel) : Subsystem("Lights") {
	DO1 = new DigitalOutput(DO1Channel);
	DO2 = new DigitalOutput(DO2Channel);
	DO3 = new DigitalOutput(DO3Channel);
	DO4 = new DigitalOutput(DO4Channel);
}

void Lights::SetColor(bool r, bool g, bool b){
	if (!r && !g && !b) {
		DO1->Set(1);
		DO2->Set(0);
		DO3->Set(0);
		DO4->Set(0);
	}
	else if (!r && !g && b){
		DO1->Set(1);
		DO2->Set(0);
		DO3->Set(0);
		DO4->Set(1);
	}
	else if (!r && !b && g){
		DO1->Set(1);
		DO2->Set(0);
		DO3->Set(1);
		DO4->Set(0);
	}
	else if (!b && r && g){
		DO1->Set(1);
		DO2->Set(0);
		DO3->Set(1);
		DO4->Set(1);
	}
	else if (!b && !g && r){
		DO1->Set(1);
		DO2->Set(1);
		DO3->Set(0);
		DO4->Set(0);
	}
	else if (!g && r && b){
		DO1->Set(1);
		DO2->Set(1);
		DO3->Set(0);
		DO4->Set(1);
	}
	else if (!r && g && b){
		DO1->Set(1);
		DO2->Set(1);
		DO3->Set(1);
		DO4->Set(0);
	}
	else if (r && g && b){
		DO1->Set(1);
		DO2->Set(1);
		DO3->Set(1);
		DO4->Set(1);
	}
}

void Lights::Standby(){
	DO1->Set(0);
	DO2->Set(0);
	DO3->Set(0);
	DO4->Set(0);

}

void Lights::SetForward(bool forward){
	if (forward = true){
		DO1->Set(0);
		DO2->Set(0);
		DO3->Set(0);
		DO4->Set(1);
	}
	else {
		DO1->Set(0);
		DO2->Set(0);
		DO3->Set(1);
		DO4->Set(0);
	}
}

Lights::~Lights() {
	// TODO Auto-generated destructor stub
}
