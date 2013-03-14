#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Components/ShiftingTransmission.h"
#include "../Components/FPSDrive.h"

class DriveTrain: public Subsystem {
private:
	static float tolerance;
	UINT32 leftDriveAxis;
	UINT32 rightDriveAxis;
	UINT32 fpsTurnAxis;
	ShiftingTransmission *shifterL;
	ShiftingTransmission *shifterR;
	RobotDrive *drive;
	Talon *rightMotor;
	Talon *leftMotor;
	Encoder *rightEncoder;
	Encoder *leftEncoder;
	Solenoid *leftSolenoid;
	FPSDrive *fpsDrive;
	PIDController *leftPID;
	PIDController *rightPID;
	int shiftUpThreshold;
	int shiftDownThreshold;
	int driveType;
	bool isFineTuneSpeed;
	int spedUpCount;
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
	void DriveWithJoystick(Joystick *stick);
	void Periodic();
	void SetLeftDriveAxis(UINT32 leftAxis);
	void SetRightDriveAxis(UINT32 rightAxis);
	void SetFPSTurnAxis(UINT32 turnAxis);
	void ShiftUp();
	void ShiftDown();
	void SetPID(float leftSetpoint, float rightSetpoint);
	bool IsPIDAtDistance();
	UINT32 GetRightDriveAxis();
	UINT32 GetLeftDriveAxis();
	void SetFineTuned(bool isFine);
	bool IsFineTuned();
	bool IsSpedUp();
	bool IsShifted();
};
#endif
