#include "Intake.h"

Intake::Intake() 
		: Subsystem("Intake"),
		roller(new Talon(1)),
		ballSwitch(new DigitalInput(1))
{
}

Intake::~Intake()
{
}

void Intake::SuckIn(){
	if (!HasBall())
		roller->Set(1);
}

void Intake::SpitOut(){
	roller->Set(-1);
}

void Intake::Stop(){
	roller->Set(0);
}

bool Intake::HasBall(){
	return ballSwitch->Get();
}
