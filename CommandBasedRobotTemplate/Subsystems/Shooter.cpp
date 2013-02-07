/*
 * Shooter.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#include "Shooter.h"

Shooter::Shooter(UINT32 motorChannel, UINT32 encoderChannel, UINT32 solenoidChannel) : PIDSubsystem(.001,0,0){
	shooterMotor = new Talon(motorChannel);
	//shooterEncoder = new RoEncoder(encoderChannel, 4);
	shooterEncoder = new Encoder2481(encoderChannel);
	shooterState = 0;
	shooterLiftSolenoid = new Solenoid(solenoidChannel);
	SetSetpoint(2000);
	SetPercentTolerance(5);
}

Shooter::~Shooter() {
	delete shooterMotor;
	delete shooterEncoder;
	delete shooterLiftSolenoid;
}

void Shooter::setSpeed(double speed){
	this->SetSetpoint(speed);
}
void Shooter::turnOn(){
	printf("Speed: %f /n", GetSetpoint());
	this->Enable();
	shooterState = 1;
}
void Shooter::turnOff(){
	this->Disable();
	shooterState = 0;
}
double Shooter::ReturnPIDInput(){
	//SmartDashboard::PutBoolean("Shooter Encoder" , shooterEncoder->getIO());
	SmartDashboard::PutNumber("Shooter Encoder PID" , shooterEncoder->PIDGet());
	printf("PID In: %f\n", shooterEncoder->PIDGet());
	return shooterEncoder->PIDGet();
}
void Shooter::UsePIDOutput(double output){
	printf("PID Out: %f\n", output);
	shooterMotor->Set((float)-output);
	//shooterMotor->Set(.5);
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
	//TODO implement magnetic sensor ????!!??
	return shooterLiftSolenoid->Get();
}

void Shooter::update() {
	//shooterEncoder->update();
}
