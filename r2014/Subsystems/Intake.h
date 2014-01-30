#ifndef INTAKE_H_
#define INTAKE_H_
#include "WPILib.h"
class Intake: public Subsystem
{
private:
	SpeedController* roller;
	DigitalInput* ballSwitch;
public:
	Intake();
	virtual ~Intake();
	void SuckIn();
	void SpitOut();
	void Stop();
	bool HasBall();
};

#endif /*INTAKE_H_*/
