//Author: Thomas Speciale

#include "Intake.h"
#include "../Robotmap.h"

Intake::Intake() : Subsystem("Intake"){
	ready = new Solenoid(READY);
	capture = new Solenoid(CAPTURE);
	roller = new Talon(INTAKE);
}

Intake::~Intake(){
	delete ready;
	delete capture;
	delete roller;
}

void Intake::RollerOn(){
	roller->SetSpeed(1);
}
void Intake::RollerOff(){
	roller->SetSpeed(0);
}
void Intake::Vomit(){
	roller->SetSpeed(-1);
}
void Intake::SetReadySolenoid(bool readyOn){
	ready->Set(readyOn);
}
void Intake::SetCaptureSolenoid(bool captureOn){
	capture->Set(captureOn);
}
