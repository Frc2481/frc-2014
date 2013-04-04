/*
 * Shooter.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: Team2481
 */

#include "Shooter.h"
#include "../RobotMap.h"
#include <math.h>

float Shooter::shooterSpeedTolerance = SHOOTER_UP_TOLERANCE;
double Shooter::pValue = SHOOTER_UP_P;
double Shooter::iValue = SHOOTER_UP_I;
double Shooter::dValue = SHOOTER_UP_D;
double Shooter::fValue = 0;
double Shooter::periodValue = SHOOTER_PERIOD;
int Shooter::autoSpeed = SHOOTER_AUTO_SPEED;

Shooter::Shooter(UINT32 motorChannel, UINT32 encoderChannel, UINT32 solenoidChannel, UINT32 solenoidDownChannel) : DynamicPIDSubsystem(pValue,iValue,dValue,fValue,periodValue){
	shooterMotor = new Talon(motorChannel);
	//shooterEncoder = new RoEncoder(encoderChannel, 4);
	shooterEncoder = new Encoder2481(encoderChannel);
	shooterState = 0;
	shooterLiftSolenoid = new Solenoid(solenoidChannel);
	SetSetpoint(autoSpeed);
	//SetPercentTolerance(5);
	SetAbsoluteTolerance(shooterSpeedTolerance / 2.0);
	GetController()->SetOutputRange(0,1);
	settledCount = 0;
	shooterSpeed = SHOOTER_UP_SPEED;
	shooterDownSolenoid = new Solenoid(LED_MODULE, solenoidDownChannel);
}

Shooter::~Shooter() {
	delete shooterMotor;
	delete shooterEncoder;
	delete shooterLiftSolenoid;
}

void Shooter::setSpeed(double speed){
	
	if (isShooterUp())
			shooterSpeed = speed;
	this->SetSetpoint(speed);
			
}
void Shooter::turnOn(){
	printf("Speed: %f \n", GetSetpoint());
	updatePID();
	this->Enable();
	shooterState = 1;
	
}
void Shooter::turnOff(){
	this->Disable();
	shooterState = 0;
	shooterEncoder->resetAverage();
}
double Shooter::ReturnPIDInput(){
	//SmartDashboard::PutBoolean("Shooter Encoder" , shooterEncoder->getIO());
	double pid = shooterEncoder->GetAveragePeriod();
	
	SmartDashboard::PutNumber("Shooter Encoder PID" , pid);
	printf("PID In: %f\n", pid);
	printf("P Value: %f \n",GetController()->GetP());
	printf("I Value: %f \n",GetController()->GetI());
	if (isAtSpeed()) {
		settledCount++;
	}
	else {
		settledCount = 0;
	}
	return pid;
}
void Shooter::UsePIDOutput(double output){
	printf("PID Out: %f\n", output);
	shooterMotor->Set((float) -output);
	//shooterMotor->Set(.5);
}

bool Shooter::isShooterOn(){
	return shooterState;
}

void Shooter::LiftShooter()  {
	shooterLiftSolenoid->Set(0);
	shooterDownSolenoid->Set(1);
	updatePID();
}

void Shooter::LowerShooter()  {
	shooterLiftSolenoid->Set(1);
	shooterDownSolenoid->Set(0);
	updatePID();
}

bool Shooter::isShooterUp() {
	//TODO implement magnetic sensor ????!!??
	return !shooterLiftSolenoid->Get();
}

float Shooter::getCurrentSpeed(){
	return shooterEncoder->PIDGet();
}

double Shooter::getDesiredSpeed(){
	return GetSetpoint();
}

bool Shooter::isAtSpeed() {
	float tolerance = isShooterUp()?SHOOTER_UP_TOLERANCE:SHOOTER_DOWN_TOLERANCE;
	return getCurrentSpeed() < getDesiredSpeed() + tolerance &&
			getCurrentSpeed() > getDesiredSpeed() - tolerance;
}

float Shooter::getErrorRPM() {
	return fabs(getCurrentSpeed() - getDesiredSpeed());
}

float Shooter::getTollerance() {
	return isShooterUp()?SHOOTER_UP_TOLERANCE:SHOOTER_DOWN_TOLERANCE;
}

bool Shooter::isSettled() {
	return settledCount > 10;
}

void Shooter::updatePID() {
	if (isShooterUp()) {
		GetController()->SetPID(SHOOTER_UP_P, SHOOTER_UP_I, SHOOTER_UP_D);
		GetController()->SetOutputRange(0,1);
		setSpeed(shooterSpeed);
	} else {
		GetController()->SetPID(SHOOTER_DOWN_P, SHOOTER_DOWN_I, SHOOTER_DOWN_D);
		setSpeed(SHOOTER_DOWN_SPEED);
		GetController()->SetOutputRange(-0.1,0.5);
	}
	//printf("Shooter P, I, D: %f, %f, %f \n", GetController()->GetP(), GetController()->GetI(), GetController()->GetD());
	
}
