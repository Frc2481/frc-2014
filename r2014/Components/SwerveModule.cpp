
#include <cmath>
#include "SwerveModule.h"
//#include "PController.h"


SwerveModule::SwerveModule(uint32_t driveChannel, uint32_t steerChannel, uint32_t steerEncoder) : 
				mDrive(new Talon(driveChannel)), 
				mSteer(new Talon(steerChannel)), 
				mEncoder(new ContinuousEncoder(steerEncoder)),
				mSteerController(new PController( mEncoder, mSteer, .007, 0.0)),
				prevAngle(0)
{
	
	mSteerController->SetOutputRange(-1,1);

	mSteerController->SetInputRange(0, 360);
	mSteerController->SetTolerance(5);
//	mSteerController->SetInputRange(0.015, 4.987);
//	mSteerController->SetInputRange(0, 360);
//	mSteerController->SetAbsoluteTolerance(2);
//	mSteerController->SetContinuous(true);
//	mSteerController->Enable();
//	mSteerController->
	
}

SwerveModule::~SwerveModule()
{
	delete mDrive;
	delete mSteer;
	delete mEncoder;
}
float SwerveModule::GetAngle()const{
	return mEncoder->GetAngle();
}

float SwerveModule::GetRawAngle()const{
	return mEncoder->GetRawAngle();
}

float SwerveModule::GetSpeed()const{
	return mDrive->Get();
}

float SwerveModule::DegToVolts(float deg) {
	return (deg + 180) / 80 + 0.25;
}

void SwerveModule::Set(float speed, float angle){
//	if (fabs(angle - GetAngle()) > 90 ){
//		angle = ((int)angle + 180) % 360;
//		speed = -speed;
//		//printf("reverse");
//	}

	if (fabs(speed) < .2){
		angle = prevAngle;
	}
	else {
		prevAngle = angle;
	}
	//printf("angle = %f \n", GetAngle());
	//SmartDashboard::PutNumber("Angle", GetAngle());
	float temp;
	temp = GetAngle();
	//mSteerController->SetSetpoint(angle + 180);
	//if (mSteerController->OnTarget())
		mDrive->Set(speed);
	//else 
		//mDrive->Set(0);
	mSteerController->Set(angle);
}

float SwerveModule::GetOffset() const
{
    return mEncoder->GetOffset();
}

void SwerveModule::SetOffset(float offset)
{
    mEncoder->SetOffset(offset);
}

PController* SwerveModule::GetController() {
	return mSteerController;
}
