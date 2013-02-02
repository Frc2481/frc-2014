#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Components/ShiftingTransmission.h"
//#include "../Components/RobotDrive2481.h"

class DriveTrain: public Subsystem {
private:
	
	UINT32 leftDriveAxis;
	UINT32 rightDriveAxis;
	ShiftingTransmission *shifterL;
	ShiftingTransmission *shifterR;
	RobotDrive *drive;
	Talon *rightMotor;
	Talon *leftMotor;
	Encoder *rightEncoder;
	Encoder *leftEncoder;
	Solenoid *leftSolenoid;
	DigitalInput *testCompressorSensor;
	int shiftUpThreshold;
	int shiftDownThreshold;
	int driveType;

public:
	//DriveTrain();
	DriveTrain(UINT32 motorL, UINT32 motorR, UINT32 encoderLA, UINT32 encoderLB, UINT32 encoderRA, UINT32 encoderRB, UINT32 solenoidL);
	~DriveTrain();
	void InitDefaultCommand();
	void DriveForward(float speed);
	void DriveBackward(float speed);
	void TurnRight(float speed);
	void TurnLeft(float speed);
	void Stop();
	void SetShiftEnabled(bool state);
	void DriveWithJoystick(Joystick *stick);
	void Periodic();
	void SetLeftDriveAxis(UINT32 leftAxis);
	void SetRightDriveAxis(UINT32 rightAxis);
	void ShiftUp();
	void ShiftDown();
	UINT32 GetRightDriveAxis();
	UINT32 GetLeftDriveAxis();
};
#endif
