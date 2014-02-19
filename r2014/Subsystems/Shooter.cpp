
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
	m_table(NULL),
	hasSetPosition(false){
	
	winch->SetSafetyEnabled(true);
	
	if(potSwitch->Get()){
		latched = true;
		winchSensor->Zero();
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
	delete shooterEarLeft;
	delete shooterEarRight;
}
void Shooter::InitDefaultCommand(){
	//SetDefaultCommand(new UpdateShooterCommand());
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
	if(position < .125){
		position = .125;
	}
	if(latched && hasSetPosition){
		
		if(position > 3.6){
			position = 3.6;
		}
		else if (position < 0){
			position = 0;
		}
		if (position  > GetPosition() + WINCH_TOLERANCE){
			ManualReleaseWinch(1);
		}
		else if (position < GetPosition() - WINCH_TOLERANCE){
			ManualRetractWinch(1);
		}
		else {
			ManualStopWinch();
		}
	}
	SmartDashboard::PutNumber("Winch commanded value", winch->Get());
	SmartDashboard::PutNumber("Shooter Setpoint", position);
	//printf("shooter position %f \n", position);
}
void Shooter::SetPosition(float pos){
	if (!hasSetPosition) {
		winchSensor->Zero();
	}
	if(latched){
		if(pos > 16){
			position = 3.5;
		}
		else if(pos < 5){
	//		position = ((0.0128 * pow(pos, 2)) - (0.1789 * pos)) + 2.2133;
			//position = (-0.0104 * pow(pos, 3)) + (0.15 * pow(pos,2)) + (-0.5083 * pos) + 1.4;
			//position = -.0104 * pow(pos, 3) + .15 * pow(pos, 2) + .5083* pos + 1.4;
			
			
			position = (-0.1274 * pow(pos, 4)) + (1.6587 * pow(pos, 3)) + (-7.7484 * pow(pos, 2)) + (15.131 * pos) + -8.7925;
		}
		else {
			position = (-0.00004 * pow(pos, 6)) + (0.0025 * pow(pos, 5)) + (-0.0577 * pow(pos, 4)) + (0.6575 * pow(pos, 3)) + (-3.6608 * pow(pos, 2)) + (7.9492 * pos) + 2.3762;
			
			
			//position = (-0.0009 * pow(pos, 4)) + (0.0448 * pow(pos, 3)) + (-.0834 * pow(pos, 2)) + (6.8458 * pos) - 19.1;
			//position = (.1 * pos) + .7;
		}
		
		printf("Pos: %f Position: %f\n", pos, position);
		hasSetPosition = true;
		
		if (pos < 5){
			shooterEarLeft->Set(1);
			shooterEarRight->Set(1);
		}
		else {
			shooterEarLeft->Set(0);
			shooterEarRight->Set(0);
		}
		//printf("%f %f \n", pos, position);
	}
}

void Shooter::SetPosition(float pos, bool earsUp) {
	if (!hasSetPosition) {
		winchSensor->Zero();
	}
	if(latched){
		if(pos > 16){
			position = 3.5;
		}
		else if(pos < 5){
			position = (-0.1274 * pow(pos, 4)) + (1.6587 * pow(pos, 3)) + (-7.7484 * pow(pos, 2)) + (15.131 * pos) + -8.7925;
			//position = (0.1783 * pos) + 1.3027;
		}
		else {
			position = (-0.00004 * pow(pos, 6)) + (0.0025 * pow(pos, 5)) + (-0.0577 * pow(pos, 4)) + (0.6575 * pow(pos, 3)) + (-3.6608 * pow(pos, 2)) + (7.9492 * pos) + 2.3762;
			//position = (.1 * pos) + .7;
		}
		shooterEarLeft->Set(!earsUp);
		shooterEarRight->Set(!earsUp);
		hasSetPosition = true;
		//printf("%f %f \n", pos, position);
	}
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
//	if (!potSwitch->Get()){
		winch->Set(speed);
//	}
//	else {
//		winch->Set(0);
//	}
}
void Shooter::ManualReleaseWinch(float speed){
	if(winchSensor->GetScaledVoltage() < 3.7){
		winch->Set(-speed);
	}
	else{
		ManualStopWinch();
	}
}
void Shooter::ManualFire(){
	if (OnTarget()) {
		latched = false;
		release->Set(1);
		position = .125;
		hasSetPosition = false;
		ManualStopWinch();
	}
}
void Shooter::ManualStopWinch(){
	winch->Set(0);
}
void Shooter::ManualLatch(){
	//latched = true;
	release->Set(0);
}

void Shooter::ManualUnlatch() {
	latched = false;
	release->Set(1);
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
			if(!hasSetPosition){
//				winchSensor->Zero();
			}
			hasSetPosition = true;
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
		position = 0;
	}
	else{
		switchCounter = 0;
		ManualUnlatch();
		ManualRetractWinch();
	}
	if(switchCounter > 10){
		ManualStopWinch();
	}
	if(switchCounter > 20){
		switchCounter = 0;
		latched = true;
		winchSensor->Zero();
		
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

bool Shooter::OnTarget() {
	float actualPosition = GetPosition();
	printf("ontarget %d \n",(actualPosition > position - WINCH_TOLERANCE && actualPosition < position + WINCH_TOLERANCE));
	return (actualPosition > position - WINCH_TOLERANCE && actualPosition < position + WINCH_TOLERANCE);
}
void Shooter::ManualSetDistance(float pos, bool earsUp){
	if (!hasSetPosition) {
		winchSensor->Zero();
	}
	position = pos;
	shooterEarLeft->Set(!earsUp);
	shooterEarRight->Set(!earsUp);
	hasSetPosition = true;
}
bool Shooter::HasSetPosition(){
	return hasSetPosition;
}
