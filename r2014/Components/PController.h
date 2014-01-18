/*
 * PController.h
 *
 *  Created on: Jan 17, 2014
 *      Author: Team2481
 */

#ifndef PCONTROLLER_H_
#define PCONTROLLER_H_
#include "WPILib.h"

class PController {
private:
	PIDSource* input;
	PIDOutput* output;
	float p;
	float tolerance;
	float inputRangeUpper;
	float inputRangeLower;
	float inputRange;
	float outputRangeUpper;
	float outputRangeLower;
	bool enabled;
	bool onTarget;
public:
	PController(PIDSource* userInput, PIDOutput* userOutput, float pValue);
	virtual ~PController();
	void SetP(float pValue);
	float GetP();
	void SetTolerance(float userTolerance);
	void Set(float setPoint);
	void SetInputRange(float lower, float uper);
	void SetOutputRange(float lower, float upwer);
	void Enable();
	void Disable();
	bool IsEnabled();
	bool OnTarget();

};

#endif /* PCONTROLLER_H_ */
