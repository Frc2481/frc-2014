#ifndef SWERVEMODULE_H_
#define SWERVEMODULE_H_
#include <WPILib.h>
#include "ContinuousEncoder.h"
#include "PController.h"
#define private public

class SwerveModule {
private:
	SpeedController *mDrive;
	SpeedController *mSteer;
	ContinuousEncoder *mEncoder;
	PController *mSteerController;
	float prevAngle;
	
public:
	SwerveModule(uint32_t driveChannel, uint32_t steerChannel, uint32_t steerEncoder);
	virtual ~SwerveModule();
	void Set(float speed, float angle);
	float GetSpeed()const;
	float GetAngle()const;
	float DegToVolts(float deg);
};

#endif /*SWERVEMODULE_H_*/
