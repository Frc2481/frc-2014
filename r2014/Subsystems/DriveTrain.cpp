/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: Team2481
 */

#include <cmath>
#include "DriveTrain.h"

DriveTrain::DriveTrain() {
	// TODO Auto-generated constructor stub
}

void DriveTrain::Crab(float xPos, float yPos, float twist, bool useGyro) {
	twist = (twist + 1) * pi;
	float FWD = yPos;
	float STR = xPos;
	// TODO get gyro angle
	if (useGyro) {
		// TODO FWD = yPos * cosf(gyro angle) + xPos * sinf(gyro angle);
		// TODO STR = -yPos * sinf(gyro angle) + xPos * cosf(gyro angle);
	}
	float A = STR - twist * baseLength / 2;
	float B = STR + twist * baseLength / 2;
	float C = FWD + twist * baseWidth / 2;
	float D = FWD + twist * baseWidth / 2;
	float wheelSpeedFR = sqrtf(powf(B, 2) + powf(C, 2));
	float wheelSpeedFL = sqrtf(powf(B, 2) + powf(D, 2));
	float wheelSpeedBR = sqrtf(powf(A, 2) + powf(C, 2));
	float wheelSpeedBL = sqrtf(powf(A, 2) + powf(D, 2));
	float wheelAngleFR = atan2f(B, C) * 180 / pi;
	float wheelAngleFL = atan2f(B, D) * 180 / pi;
	float wheelAngleBR = atan2f(A, C) * 180 / pi;
	float wheelAngleBL = atan2f(A, D) * 180 / pi;
	//speeds normalized 0 to 1
	//maybe eventually reverse motor instead of turning far and going forward
	float maxWheelSpeed = wheelSpeedFR;
	if (wheelSpeedFL > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedFL;
	}
	if (wheelSpeedBR > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedBR;
	}
	if (wheelSpeedBL > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedBL;
	}
	if (maxWheelSpeed > 1) {
		wheelSpeedFR /= maxWheelSpeed;
		wheelSpeedFL /= maxWheelSpeed;
		wheelSpeedBR /= maxWheelSpeed;
		wheelSpeedBL /= maxWheelSpeed;
	}
}

DriveTrain::~DriveTrain() {
	// TODO Auto-generated destructor stub
}
