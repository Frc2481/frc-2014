#ifndef SWERVEMODULE_H_
#define SWERVEMODULE_H_
#include <WPILib.h>
#include "ContinuousEncoder.h"
#include "PController.h"

class SwerveModule {
private:
    Talon *mDrive;
    Talon *mSteer;
    ContinuousEncoder *mEncoder;
    PController *mSteerController;
    float prevAngle;
    float offset;
    
	
public:
	SwerveModule(uint32_t driveChannel, uint32_t steerChannel, uint32_t steerEncoder);
	virtual ~SwerveModule();
	void Set(float speed, float angle);
	float GetSpeed()const;
	float GetAngle()const;
	float GetRawAngle()const;
	float GetOffset() const;
	void SetOffset(float offset);
	float DegToVolts(float deg);
	PController* GetController();
};

#endif /*SWERVEMODULE_H_*/
