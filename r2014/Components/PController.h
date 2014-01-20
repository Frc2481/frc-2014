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
	float i;
	float totalError;
	float tolerance;
	float inputRangeUpper;
	float inputRangeLower;
	float inputRange;
	float outputRangeUpper;
	float outputRangeLower;
	bool enabled;
	bool onTarget;
	float pidOutput;
	float setPoint;
	SEM_ID pSemaphore;
	Notifier* pUpdate;
public:
	PController(PIDSource* userInput, PIDOutput* userOutput, float pValue, float iValue);
	virtual ~PController();
	void SetP(float pValue);
	float GetP();
	void SetI(float iValue);
	float GetI();
	void SetTolerance(float userTolerance);
	void Set(float setPoint);
	void SetInputRange(float lower, float uper);
	void SetOutputRange(float lower, float upwer);
	void Enable();
	void Disable();
	bool IsEnabled();
	bool OnTarget();
	static void UpdateController(void* controller);
	void Update();

};

#endif /* PCONTROLLER_H_ */