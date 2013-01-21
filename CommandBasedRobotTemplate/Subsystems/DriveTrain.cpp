#include "DriveTrain.h"
#include "../Commands/DriveWithJoystickCommand.h"
#include "../Robotmap.h"

DriveTrain::DriveTrain(UINT32 motorL, UINT32 motorR, 
					   UINT32 encoderLA, UINT32 encoderLB, UINT32 encoderRA, UINT32 encoderRB, 
					   UINT32 solenoidL, UINT32 solenoidR) 
: Subsystem("DriveTrain")
{
	rightMotor = new Talon(motorR);
	leftMotor = new Talon(motorL);
	rightEncoder = new Encoder(encoderRA, encoderRB);
	leftEncoder = new Encoder(encoderLA, encoderLB);
	rightSolenoid = new Solenoid(solenoidR);
	leftSolenoid = new Solenoid(solenoidL);
	
	//shifterR = new ShiftingTransmission(rightMotor, rightEncoder, rightSolenoid);
	shifterR = new ShiftingTransmission(rightMotor, rightEncoder, rightSolenoid);
	shifterR->SetUpShiftThreshold(70);
	shifterR->SetDownShiftTheshold(60);
	shifterL = new ShiftingTransmission(leftMotor,leftEncoder, leftSolenoid);
	shifterL->SetUpShiftThreshold(70);
	shifterL->SetDownShiftTheshold(60);
	
	drive = new RobotDrive(shifterL, shifterR);
	drive->SetSafetyEnabled(false);
	
	jsMax = 0;
	jsMin = 0;
	
}
DriveTrain::~DriveTrain(){
	delete drive;
	delete shifterR;
	delete shifterL;
	delete rightMotor;
	delete leftMotor;
	delete rightEncoder;
	delete leftEncoder;
	delete rightSolenoid;
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
	rightSolenoid->Set(true);
	leftSolenoid->Set(true);
}

void DriveTrain::ShiftDown() {
	rightSolenoid->Set(false);
	leftSolenoid->Set(false);
}

void DriveTrain::SetShiftEnabled(bool state) {
	shifterL->SetEnabled(state);
	shifterR->SetEnabled(state);
}
void DriveTrain::DriveWithJoystick(Joystick *stick) {
	//drive->ArcadeDrive(stick);
	drive->TankDrive(stick, 2, stick, 5);
	if (stick->GetRawAxis(5) > jsMax) {
		jsMax = stick->GetRawAxis(5);
	}
	else if (stick->GetRawAxis(5) < jsMin) {
		jsMin = stick->GetRawAxis(5);
	}
	SmartDashboard::PutNumber("jsMax" , jsMax);
	SmartDashboard::PutNumber("jsMin" , jsMin);
	SmartDashboard::PutNumber("Left Drive Joystick Value" , stick->GetRawAxis(2));
	SmartDashboard::PutNumber("Right Drive Joystick Value" , stick->GetRawAxis(5));
	Periodic();
}

void DriveTrain::Periodic() {
	SmartDashboard::PutNumber("Left Encoder Value" , leftEncoder->GetRate());
	SmartDashboard::PutNumber("Right Encoder Value" , rightEncoder->GetRate());
	SmartDashboard::PutBoolean("Status is Fatal L", leftEncoder->StatusIsFatal());
	SmartDashboard::PutBoolean("Status is Fatal R", rightEncoder->StatusIsFatal());
	shifterL->Run();
	shifterR->Run();
}
