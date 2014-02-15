
/*
 * Shooter.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 * 		Editor: paulRich
 */

#include "Shooter.h"
#include "../Commands/UpdateShooterCommand.h"
#include <math.h>

Shooter::Shooter(uint32_t winchChannel, uint32_t winchSensorChannel, uint32_t earChannelL, uint32_t earChannelR, uint32_t releaseChannel, uint32_t potSwitchChannel) : 
	Subsystem("shooter"), 
	winch(new Talon(winchChannel)),
	winchSensor(new ContinuousEncoderCounter(winchSensorChannel)),
	shooterEarLeft(new Solenoid(earChannelL)),
	shooterEarRight(new Solenoid(earChannelR)),
	release(new Solenoid(releaseChannel)),
	position(0),
	potSwitch(new DigitalInput(potSwitchChannel)),
	offset(0),
	switchCounter(0),
	m_table(NULL){
	
	if(potSwitch->Get()){
		latched = true;
		offset = winchSensor->GetScaledVoltage();
	}
	else {
		latched = false;
	}
}

Shooter::~Shooter() {
	delete winch;
	delete winchSensor;
	delete release;
	delete potSwitch;
}
void Shooter::InitDefaultCommand(){
	SetDefaultCommand(new UpdateShooterCommand());
}

void Shooter::Fire(float distance){
}
void Shooter::Load(){
	SetPosition(LOADED_SHOOTER_POSITION);
}
void Shooter::SetRightEar(bool position){
	shooterEarRight->Set(position);
}
void Shooter::SetLeftEar(bool position){
	shooterEarLeft->Set(position);
}


bool Shooter::GetLeftEar(){
	return shooterEarLeft->Get();
}

bool Shooter::GetRightEar(){
	return shooterEarRight->Get();
}

void Shooter::Periodic(){
	if(latched){
		if (position  > GetPosition() + WINCH_TOLERANCE){
			ManualReleaseWinch(.25);
		}
		else if (position < GetPosition() - WINCH_TOLERANCE){
			ManualRetractWinch(.25);
		}
		else {
			ManualStopWinch();
		}
	}
	//printf("shooter position %f \n", position);
}
void Shooter::SetPosition(float pos){
	if(pos > 5){
//		position = ((0.0128 * pow(pos, 2)) - (0.1789 * pos)) + 2.2133;
		position = (0.1783 * pos) + 1.3027;
	}
	else {
		position = (.1 * pos) + .7;
	}

	if (position < 1.4){
		shooterEarLeft->Set(1);
		shooterEarRight->Set(1);
	}
	else {
		shooterEarLeft->Set(0);
		shooterEarRight->Set(0);
	}
	
	printf("Pos: %f Position: %f\n", pos, position);
}
float Shooter::GetPosition(){
	return winchSensor->GetScaledVoltage();// - offset;
	
}
void Shooter::ManualRetractWinch(float speed){
//	if (winchSensor->GetScaledVoltage() > .2){
//		winch->Set(speed);
//	}
//	else{
//		ManualStopWinch();
//	}
	winch->Set(speed);
}
void Shooter::ManualReleaseWinch(float speed){
	if(winchSensor->GetScaledVoltage() < 4.8){
		winch->Set(-speed);
	}
	else{
		ManualStopWinch();
	}
}
void Shooter::ManualFire(){
	latched = false;
	release->Set(1);
	position = 0;
}
void Shooter::ManualStopWinch(){
	winch->Set(0);
}
void Shooter::ManualLatch(){
	//latched = true;
	release->Set(0);
}
float Shooter::GetSetPoint(){
	return position;
}
bool Shooter::GetSwitch(){
	return potSwitch->Get();
}
bool Shooter::IsLatched(){
	return latched;
}
void Shooter::InitTable(ITable* table){
	if(m_table!=NULL)
		m_table->RemoveTableListener(this);
	m_table = table;
	if(m_table!=NULL){
		m_table->PutNumber("p", GetPosition());
		m_table->AddTableListener(this, false);
	}
}

ITable* Shooter::GetTable(){
	return m_table;
}

void Shooter::ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew){
	if (key == "p") {
		if (position != m_table->GetNumber("p")) {
			position = m_table->GetNumber("p", GetPosition());
		}
	}
}

void Shooter::UpdateTable() {
	
}

void Shooter::StartLiveWindowMode() {
	
}

void Shooter::StopLiveWindowMode() {
	
}

std::string Shooter::GetSmartDashboardType(){
	return "PIDController";
}
void Shooter::RetractSlack(){
	if (winchSensor->GetScaledVoltage() > .2){
		winch->Set(1);
	}
}
float Shooter::GetRawPosition(){
	return winchSensor->GetScaledVoltage();
}
void Shooter::CockWinch(){
	if(potSwitch->Get()){
		switchCounter++;
		ManualLatch();
	}
	else{
		switchCounter = 0;
		ManualFire();
		ManualRetractWinch();
	}
	if(switchCounter > 10){
		ManualStopWinch();
		switchCounter = 0;
		latched = true;
		if (potSwitch->Get()){
			winchSensor->Zero();
//			offset = winchSensor->GetScaledVoltage();
		}
	}
}
void Shooter::SetPositionVolts(float userPosition){
	position = userPosition;
}
float Shooter::GetDistance(){
	if (position > 5){
		return 8.83883 * (sqrt(position - 1.5862) + .790634);
	}
	else {
		return (position + 1.2727) / 2.6364;
	}
}
