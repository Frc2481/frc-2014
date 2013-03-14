#include "ShiftingTransmission.h"

ShiftingTransmission::ShiftingTransmission(SpeedController* m, Solenoid* s)
	: motor(m), solenoid(s){
	loopCount = 0;
	isShiftingUp = 0;
	isShiftingDown = 0;
	motorSpeed = 0;
	isLowSpeed = true;
	
}
ShiftingTransmission::~ShiftingTransmission(){
}

void ShiftingTransmission::Set(float speed, UINT8 syncGroup){
	motorSpeed = -speed;
}
float ShiftingTransmission::Get(){
	return motor->Get();
}
bool ShiftingTransmission::IsLowSpeed(){
	return isLowSpeed;
}
/*
 * Run: check if we need to shift based on wheel speed then shift up or down accordingly
 *		this must be called once every loop (assume 20ms loops)
 */
void ShiftingTransmission::Run(){
	if (isShiftingUp){
		
		if (loopCount == 0){			// turn the motor off for two loops 
			motor->Set(0); 			//TODO change this if we implement break
		}
		else if (loopCount == 2){
			SetSolenoid(1);		// shift gears 
		}
		else if (loopCount == 6){	// keep the motor off for another two loops and start the motor again
			motor->Set(motorSpeed);
		}
		else if (loopCount == 16){  //We back off for approx 200ms for a debounce effect.
			isShiftingUp = false;
			isLowSpeed = false;
		}
		else if (loopCount > 6) {
			motor->Set(motorSpeed);
		}
		loopCount++;
	}
	
	else if (isShiftingDown){
		
		if (loopCount == 0){			// turn the motor off for two loops 
			motor->Set(0); 			//TODO change this if we implement break
		}
		else if (loopCount == 2){
			SetSolenoid(0);		// shift gears 
		}
		else if (loopCount == 6){	// keep the motor off for another two loops and start the motor again
			motor->Set(motorSpeed);
		}
		else if (loopCount == 16){	//We back off for approx 200ms for a debounce effect.
			isShiftingDown = false;
			isLowSpeed = true;
		}
		else if (loopCount > 6) {
			motor->Set(motorSpeed);
		}
		loopCount++;
	}
	else {
		motor->Set(motorSpeed);
	}
}
void ShiftingTransmission::PIDWrite(float output) {
	
}
void ShiftingTransmission::Disable(){
	motor->Disable();
	
}
void ShiftingTransmission::SetSolenoid(bool position){
	if (solenoid){
		solenoid ->Set(position);
	}
}

void ShiftingTransmission::ShiftUp() {
	if (IsLowSpeed() && !isShiftingUp){	//Do we need to shift up? 
		isShiftingUp = true; // Set the state 
		isShiftingDown = false;
		loopCount = 0;
	}
}

void ShiftingTransmission::ShiftDown() {
	if (!IsLowSpeed() && !isShiftingDown){	//Do we need to shift down?
		isShiftingDown = true; //Set the state
		isShiftingUp = false;
		loopCount = 0;
	}
}
