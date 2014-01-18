/*a
 * PController.cpp
 *
 *  Created on: Jan 17, 2014
 *      Author: Team2481
 */

#include "PController.h"
#include <cmath>
#include "SwerveModule.h"

PController::PController(PIDSource* userInput, PIDOutput* userOutput, float pValue) :
			input(userInput), 
			output(userOutput), 
			p(pValue),
			tolerance(0),
			inputRangeUpper(0),
			inputRangeLower(5),
			inputRange(5),
			outputRangeUpper(1),
			outputRangeLower(-1),
			enabled(true),		
			onTarget(false)	{

}

PController::~PController() {
	// TODO Auto-generated destructor stub
	
}
void PController::SetP(float pValue){
	p = pValue;
}

float PController::GetP(){
	return p;
}

void PController::SetTolerance(float userTolerance){
	tolerance = userTolerance;
}
void PController::Set(float setPoint){
	if(enabled){
		float error = setPoint - input->PIDGet();
		float correctedError = 0;
		
		if (fabs(error) < tolerance){
			correctedError = 0;
			onTarget = true;
		}
		else if (error < -inputRange / 2){
			onTarget = false;
			correctedError = error + inputRange;
		}
		
		else if(error > inputRange / 2) {
			onTarget = false;
			correctedError = error - inputRange;
		}
		else {
			onTarget = false;
			correctedError = error;
		}
		
		if (correctedError > outputRangeUpper){
			correctedError = outputRangeUpper;
		}
		else if (correctedError < outputRangeLower){
			correctedError = outputRangeLower;
		}
		SmartDashboard::PutNumber("corrected Error", correctedError);
		SmartDashboard::PutNumber("error", error);
			
		
		output->PIDWrite(-correctedError * p);
	}
	else {
		output->PIDWrite(0);
	}
}

void PController::SetInputRange(float lower, float upper){
	inputRangeUpper = upper;
	inputRangeLower = lower;
	inputRange = inputRangeUpper - inputRangeLower;
}

void PController::SetOutputRange(float lower, float upper){
	outputRangeUpper = upper;
	outputRangeLower = lower;
}

void PController::Enable(){
	enabled = true;
}

void PController::Disable(){
	enabled = false;
}

bool PController::IsEnabled(){
	return enabled;
}

bool PController::OnTarget(){
	return onTarget;
}
