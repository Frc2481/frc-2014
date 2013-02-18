/*
 * Lights.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Team2481
 */

#include "Lights.h"

Lights::Lights() : Subsystem("Lights") {
	mTop = new RGBLed(LED_TOP_RED, LED_TOP_GREEN, LED_TOP_BLUE, LED_MODULE);
	mBottom = new RGBLed(LED_BOTTOM_RED, LED_BOTTOM_GREEN, LED_BOTTOM_BLUE, LED_MODULE);
}

Lights::~Lights() {
	delete mTop;
	delete mBottom;
}

void Lights::setTop(int c) {
	mTop->set(c);
}

void Lights::setBottom(int c) {
	mBottom->set(c);
}

int Lights::getTop() {
	return mTop->get();
}

int Lights::getBottom() {
	return mBottom->get();
}
