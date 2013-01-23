/*
 * Shooter.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#include "Shooter.h"

Shooter::Shooter(UINT32 motorChannel, UINT32 encoderChannelA, UINT32 encoderChannelB, UINT32 solenoidChannel) : PIDSubsystem(1,0,0){
	shooterMotor = new Talon(motorChannel);
	shooterEncoder = new Encoder(encoderChannelA, encoderChannelB);
	shooterState = 0;
	shooterLiftSolenoid = new Solenoid(solenoidChannel);
}

Shooter::~Shooter() {
	delete shooterMotor;
	delete shooterEncoder;
}

void Shooter::setSpeed(double speed){
	this->SetSetpoint(speed);
}
void Shooter::turnOn(){
	this->Enable();
	shooterState = 1;
}
void Shooter::tunOff(){
	this->Disable();
	shooterState = 0;
}
double Shooter::ReturnPIDInput(){
	return shooterEncoder->GetRate();
}
void Shooter::UsePIDOutput(double output){
	shooterMotor->Set((float)output);
}

bool Shooter::isShooterOn(){
	return shooterState;
}

void Shooter::LiftShooter()  {
	shooterLiftSolenoid->Set(1);
}

void Shooter::LowerShooter()  {
	shooterLiftSolenoid->Set(0);
}

bool Shooter::isShooterUp() {
	return shooterLiftSolenoid->Get();
}
