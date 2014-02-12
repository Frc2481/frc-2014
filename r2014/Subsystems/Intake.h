/*	
 * 
 *  Author: thomasSpeciale, paulRich
*/
#ifndef INTAKE_H_
#define INTAKE_H_

#include "WPILIB.h"

class Intake : public Subsystem {
private:
	Solenoid *ready;
	Solenoid *capture;
	Talon *roller;
public:
	Intake();
	virtual ~Intake();
	void RollerOn();
	void RollerOff();
	void Vomit();
	void SetReadySolenoid(bool readyOn);
	void SetCaptureSolenoid(bool captureOn);
	bool GetReadySolenoid();
	bool GetPosition();
};

#endif /*INTAKE_H_*/
