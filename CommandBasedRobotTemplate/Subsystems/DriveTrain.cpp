#include "DriveTrain.h"
#include "../Commands/DriveWithJoystickCommand.h"
#include "../Robotmap.h"

#define DISTANCE_PER_PULSE 2.31792417968 / 360.0

float DriveTrain::tolerance = .5;

DriveTrain::DriveTrain(UINT32 motorL, UINT32 motorR, 
					   UINT32 encoderLA, UINT32 encoderLB, UINT32 encoderRA, UINT32 encoderRB, 
					   UINT32 solenoidL) 
: Subsystem("DriveTrain")
{
	rightMotor = new Talon(motorR);
	leftMotor = new Talon(motorL);
	rightEncoder = new Encoder(encoderRA, encoderRB);
	leftEncoder = new Encoder(encoderLA, encoderLB);
	leftSolenoid = new Solenoid(solenoidL);
	
	//shifterR = new ShiftingTransmission(rightMotor, rightEncoder, rightSolenoid);
	shifterR = new ShiftingTransmission(rightMotor, NULL);
	shifterL = new ShiftingTransmission(leftMotor, leftSolenoid);
	shiftUpThreshold = 60;
	shiftDownThreshold = 50;
	drive = new RobotDrive(shifterL, shifterR);
//	drive = new RobotDrive(leftMotor, rightMotor);
	drive->SetSafetyEnabled(false);
	rightEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE);
	rightEncoder->Start();
	leftEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE);
	leftEncoder->Start();
	rightDriveAxis = 0;
	leftDriveAxis = 0;
	//fpsDrive = new FPSDrive();
	fpsTurnAxis = 0;
	driveType = 0; // 0 = tank, 1 = arcade, 2 = FPS. Note, for FPS drive the leftStick will likely need to be the x instead of y axis in CommandBase.cpp
	leftPID = new PIDController(1, 0, 0, leftEncoder, leftMotor);
	rightPID = new PIDController(1, 0, 0, rightEncoder, rightMotor);
//	
	leftPID->Disable();
	rightPID->Disable();
	leftPID->SetTolerance(tolerance);
	rightPID->SetTolerance(tolerance);
	leftEncoder->SetPIDSourceParameter(Encoder::kDistance);
	rightEncoder->SetPIDSourceParameter(Encoder::kDistance);
	
}
DriveTrain::~DriveTrain(){
	delete drive;
	delete shifterR;
	delete shifterL;
	delete rightMotor;
	delete leftMotor;
	delete rightEncoder;
	delete leftEncoder;
	delete leftSolenoid;
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystickCommand());
}

void DriveTrain::DriveForward(float speed) {
	drive->SetLeftRightMotorOutputs(speed, speed);
}
void DriveTrain::DriveBackward(float speed) {
	drive->SetLeftRightMotorOutputs(-speed, -speed);
}
void DriveTrain::TurnRight(float speed) {
	drive->SetLeftRightMotorOutputs(speed, -speed);
}
void DriveTrain::TurnLeft(float speed) {
	drive->SetLeftRightMotorOutputs(-speed, speed);
}
void DriveTrain::Stop() {
	drive->SetLeftRightMotorOutputs(0, 0);
}

void DriveTrain::ShiftUp() {
	shifterR->ShiftUp();
	shifterL->ShiftUp();
}

void DriveTrain::ShiftDown() {
	shifterR->ShiftDown();
	shifterL->ShiftDown();
}

void DriveTrain::SetShiftEnabled(bool state) {
	shifterL->SetEnabled(state);
	shifterR->SetEnabled(state);
}
void DriveTrain::DriveWithJoystick(Joystick *stick) {
	//drive->ArcadeDrive(stick);
	if (driveType == 0){
		drive->TankDrive(stick, leftDriveAxis, stick, rightDriveAxis);
	}
	if (driveType == 1){
		drive->ArcadeDrive(stick, rightDriveAxis);
	}
//	if (driveType == 2){
//		fpsDrive->Drive(stick, leftDriveAxis, stick, fpsTurnAxis, drive);
//	}
	
	//***For somereason uncommenting out these put numbers*** 
	//***causes random IO errors and 100% CPU***
	SmartDashboard::PutNumber("Left Drive Joystick Value" , stick->GetRawAxis(leftDriveAxis));
	SmartDashboard::PutNumber("Right Drive Joystick Value" , stick->GetRawAxis(rightDriveAxis));
	
	//Periodic();
}

void DriveTrain::Periodic() {
	SmartDashboard::PutNumber("Left Encoder Value" , leftEncoder->GetRate());
	SmartDashboard::PutNumber("Right Encoder Value" , rightEncoder->GetRate());
	SmartDashboard::PutBoolean("Status is Fatal L", leftEncoder->StatusIsFatal());
	SmartDashboard::PutBoolean("Status is Fatal R", rightEncoder->StatusIsFatal());
	SmartDashboard::PutNumber("ArmSensorValue", CommandBase::climbingArm->getCurrentPosition());
	shifterL->Run();
	shifterR->Run();
	
	if ((rightEncoder->GetRate() + leftEncoder->GetRate())/2 > shiftUpThreshold) {
		shifterR->ShiftUp();
		shifterL->ShiftUp();
	}
	else if ((rightEncoder->GetRate() + leftEncoder->GetRate())/2 < shiftDownThreshold) {
		shifterR->ShiftDown();
		shifterL->ShiftDown();
	}
}
void DriveTrain::SetLeftDriveAxis(UINT32 leftAxis){
	leftDriveAxis = leftAxis;
}
void DriveTrain::SetRightDriveAxis(UINT32 rightAxis){
	rightDriveAxis = rightAxis;
}
void DriveTrain::SetFPSTurnAxis(UINT32 turnAxis){
	fpsTurnAxis = turnAxis;
}
UINT32 DriveTrain::GetRightDriveAxis(){
	return rightDriveAxis;
}
UINT32 DriveTrain::GetLeftDriveAxis(){
	return leftDriveAxis;
}
void DriveTrain::SetPID(float leftSetpoint, float rightSetpoint){
	leftEncoder->Reset();
	rightEncoder->Reset();
	leftPID->Enable();
	rightPID->Enable();
	leftPID->SetSetpoint(leftSetpoint);
	rightPID->SetSetpoint(rightSetpoint);
}
bool DriveTrain::IsPIDAtDistance(){
	if (rightPID->Get() < rightPID->GetSetpoint() + tolerance && 
		rightPID->Get() > rightPID->GetSetpoint() - tolerance &&
		leftPID->Get() < leftPID->GetSetpoint() + tolerance && 
		leftPID->Get() > leftPID->GetSetpoint() - tolerance){
		leftPID->Disable();
		rightPID->Disable();
		return true;
	}
	return false;
	
}
