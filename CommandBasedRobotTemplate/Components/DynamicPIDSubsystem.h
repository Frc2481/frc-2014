#ifndef __PID_DYN_SUBSYSTEM_H__
#define __PID_DYN_SUBSYSTEM_H__

#include "Commands/PIDSubsystem.h"

class DynamicPIDSubsystem : public PIDSubsystem
{
public:
		DynamicPIDSubsystem(const char *name, double p, double i, double d);
		DynamicPIDSubsystem(const char *name, double p, double i, double d, double f);
		DynamicPIDSubsystem(const char *name, double p, double i, double d, double f, double period);
		DynamicPIDSubsystem(double p, double i, double d);
		DynamicPIDSubsystem(double p, double i, double d, double f);
		DynamicPIDSubsystem(double p, double i, double d, double f, double period);
		virtual ~DynamicPIDSubsystem();
		
		PIDController* GetController();
};


#endif
