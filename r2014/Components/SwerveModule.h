#ifndef SWERVEMODULE_H_
#define SWERVEMODULE_H_
#include <WPILib.h>

class SwerveModule {
private:
	SpeedController *mDrive;
	SpeedController *mSteer;
	AnalogChannel *mEncoder;
	PIDController *mSteerController;
	
public:
	SwerveModule(uint32_t driveChannel, uint32_t steerChannel, uint32_t encoderChannel);
	virtual ~SwerveModule();
	void Set(float speed, float angle);
	float GetSpeed()const;
	float GetAngle()const;
	
};

#endif /*SWERVEMODULE_H_*/
