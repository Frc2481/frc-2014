#include <cmath>
#include "SwerveModule.h"


SwerveModule::SwerveModule(uint32_t driveChannel, uint32_t steerChannel, uint32_t encoderChannel) : 
				mDrive(new Talon(driveChannel)), 
				mSteer(new Talon(steerChannel)), 
				mEncoder(new AnalogChannel(encoderChannel)), 
				mSteerController(new PIDController(0,1,0, mEncoder, mSteer))
{
}

SwerveModule::~SwerveModule()
{
	delete mDrive;
	delete mSteer;
	delete mEncoder;
}
float SwerveModule::GetAngle()const{
	return (mEncoder->GetAverageVoltage() / 5) * 360;
}
float SwerveModule::GetSpeed()const{
	return mDrive->Get();
}

void SwerveModule::Set(float speed, float angle){
	if (fabs(angle - (mEncoder->GetAverageVoltage() / 5 *360)) > 90 ){
		angle = -angle;
		speed = -speed;
	}
	mSteerController->SetSetpoint(angle);
	mDrive->Set(speed);
}
