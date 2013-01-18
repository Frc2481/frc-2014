#include "DriveTrain.h"
#include "../Commands/DriveWithJoystickCommand.h"
#include "../Robotmap.h"

DriveTrain::DriveTrain(UINT32 motorL, UINT32 motorR, 
					   UINT32 encoderLA, UINT32 encoderLB, UINT32 encoderRA, UINT32 encoderRB, 
					   UINT32 solenoidL, UINT32 solenoidR) 
: Subsystem("DriveTrain")
{
	shifterR = new ShiftingTransmission(new Talon (motorR),new Encoder (encoderRA, encoderRB),new Solenoid (solenoidR));
	shifterL = new ShiftingTransmission(new Talon (motorL),new Encoder (encoderLA, encoderLB),new Solenoid (solenoidL));
	drive = new RobotDrive(shifterL, shifterR);
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
void DriveTrain::SetShiftEnabled(bool state) {
	shifterL->SetEnabled(state);
	shifterR->SetEnabled(state);
}
void DriveTrain::DriveWithJoystick(Joystick *stick) {
	drive->ArcadeDrive(stick);
}

void DriveTrain::Periodic() {
	shifterL->Run();
	shifterR->Run();
}
