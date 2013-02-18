/*
 * DynamicPIDSubsystem.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: Team2481
 */

#include "DynamicPIDSubsystem.h"

DynamicPIDSubsystem::DynamicPIDSubsystem(const char *name, double p, double i, double d):PIDSubsystem(name,p,i,d)
{
}
DynamicPIDSubsystem::DynamicPIDSubsystem(const char *name, double p, double i, double d, double f):PIDSubsystem(name,p,i,d,f)
{
}
DynamicPIDSubsystem::DynamicPIDSubsystem(const char *name, double p, double i, double d, double f, double period):PIDSubsystem(name,p,i,d,period)
{
}
DynamicPIDSubsystem::DynamicPIDSubsystem(double p, double i, double d):PIDSubsystem(p,i,d)
{
}
DynamicPIDSubsystem::DynamicPIDSubsystem(double p, double i, double d, double f):PIDSubsystem(p,i,d,f)
{
}
DynamicPIDSubsystem::DynamicPIDSubsystem(double p, double i, double d, double f, double period):PIDSubsystem(p,i,d,f,period)
{
}
DynamicPIDSubsystem::~DynamicPIDSubsystem(){
	
}

PIDController* DynamicPIDSubsystem::GetController()
{
	return this->GetPIDController();
}

