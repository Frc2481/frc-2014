#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Components/ShiftingTransmission.h"

class DriveTrain: public Subsystem {
private:
	
ShiftingTransmission *shifterL;
ShiftingTransmission *shifterR;
RobotDrive *drive;
Talon *rightMotor;
Talon *leftMotor;
Encoder *rightEncoder;
Encoder *leftEncoder;
Solenoid *rightSolenoid;
Solenoid *leftSolenoid;
float jsMax;
float jsMin;

public:
	//DriveTrain();
	DriveTrain(UINT32 motorL, UINT32 motorR, UINT32 encoderLA, UINT32 encoderLB, UINT32 encoderRA, UINT32 encoderRB, UINT32 solenoidL, UINT32 solenoidR);
	~DriveTrain();
	void InitDefaultCommand();
	void DriveForward(float speed);
	void DriveBackward(float speed);
	void TurnRight(float speed);
	void TurnLeft(float speed);
	void ShiftUp();
	void ShiftDown();
	void Stop();
	void SetShiftEnabled(bool state);
	void DriveWithJoystick(Joystick *stick);
	void Periodic();
};
#endif
