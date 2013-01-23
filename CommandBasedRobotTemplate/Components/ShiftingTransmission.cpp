#include "ShiftingTransmission.h"

#define DISTANCE_PER_PULSE 2.31792417968 / 360.0

ShiftingTransmission::ShiftingTransmission(SpeedController* m, Encoder* e, Solenoid* s)
	: motor(m), encoder(e), solenoid(s){
	encoder->SetDistancePerPulse(DISTANCE_PER_PULSE);
	encoder->Start();
	upShiftThreshold = -1;
	downShiftThreshold = -1;
	loopCount = 0;
	isShiftingUp = 0;
	isShiftingDown = 0;
	beforeShiftSpeed = 0;
	motorSpeed = 0;
	enabled = true;
	
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
	return !solenoid->Get();
}
void ShiftingTransmission::SetUpShiftThreshold(UINT32 t){
	upShiftThreshold = t;
}
void ShiftingTransmission::SetDownShiftTheshold(UINT32 t){
	downShiftThreshold = t;
}
UINT32 ShiftingTransmission::GetUpShiftThreshold(){
	return upShiftThreshold;
}
UINT32 ShiftingTransmission::GetDownShiftThreshold(){
	return downShiftThreshold;
}
/*
 * Run: check if we need to shift based on wheel speed then shift up or down accordingly
 *		this must be called once every loop (assume 20ms loops)
 */
void ShiftingTransmission::Run(){
	if (encoder->GetRate() > upShiftThreshold && IsLowSpeed() && !isShiftingUp && !isShiftingDown && enabled){	//Do we need to shift up? 
		isShiftingUp = true;														// Set the state 
		loopCount = 0;
	}
	
	if (encoder->GetRate() < downShiftThreshold && !IsLowSpeed() && (!isShiftingDown && !isShiftingUp)){	//Do we need to shift down?
		isShiftingDown = true;															//Set the state 
		loopCount = 0;
	}
	
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
		}
		loopCount++;
	}
	else {
		motor->Set(motorSpeed);
	}
}
void ShiftingTransmission::PIDWrite(float output) {
	
}
void ShiftingTransmission::SetEnabled(bool enableState){
	enabled = enableState;
	if (!enabled){
		isShiftingDown = !IsLowSpeed(); 		//If we are not in low gear, shift down
		loopCount = 0;
	}
}
void ShiftingTransmission::Disable(){
	motor->Disable();
	
}
void ShiftingTransmission::SetSolenoid(bool position){
	if (solenoid){
		solenoid ->Set(position);
	}
}
