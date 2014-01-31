/*
 * Shooter.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 */

#include "Shooter.h"

Shooter::Shooter(uint32_t winchChannel, uint32_t winchSensorChannel, uint32_t earChannel, uint32_t releaseChannel) : 
	Subsystem("shooter"), 
	winch(new Talon(winchChannel)),
	winchSensor(new AnalogChannel(winchSensorChannel)),
	shooterEars(new Solenoid(earChannel)),
	release(new Solenoid(releaseChannel)),
	position(0){

}

Shooter::~Shooter() {
	delete winch;
	delete winchSensor;
	delete shooterEars;
	delete release;
}

void Shooter::Fire(float distance){
	if(distance > 3){
		shooterEars->Set(1);
		position = distance;
	}
	else {
		shooterEars->Set(0);
		position = distance;
	}
}
void Shooter::Load(){
	SetPosition(LOADED_SHOOTER_POSITION);
}
void Shooter::SetEars(bool position){
	shooterEars->Set(position);
}

bool Shooter::GetEars(){
	return shooterEars->Get();
}

void Shooter::Periodic(){
	if (winchSensor->GetAverageVoltage() > position + WINCH_TOLERANCE){
		winch->Set(-1);
	}
	else if (winchSensor->GetAverageVoltage() < position - WINCH_TOLERANCE){
		winch->Set(1);
	}
	else {
		winch->Set(0);
	}
}
void Shooter::SetPosition(float pos){
	position = pos;
}
void Shooter::ManualRetractWinch(){
	release->Set(1);
	winch->Set(-1);
}
void Shooter::ManualReleaseWinch(){
	winch->Set(.5);
}
void Shooter::ManualFire(){
	release->Set(1);
}
void Shooter::ManualStopWinch(){
	winch->Set(0);
}
void Shooter::ManualLatch(){
	release->Set(0);
}
float Shooter::GetSetPoint(){
	return position;
}
