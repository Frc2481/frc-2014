/*
 * SpeedUpShooterCommand.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Team2481
 */

#ifndef SPEEDUPSHOOTERCOMMAND_H_
#define SPEEDUPHOOTERCOMMAND_H_

#include "../CommandBase.h"

class SpeedUpShooterCommand : public CommandBase{
public:
	SpeedUpShooterCommand(){}
	virtual ~SpeedUpShooterCommand(){}
	void Initialize(){
		CommandBase::shooter->setSpeed(CommandBase::shooter->GetSetpoint() + 25);
		//CommandBase::shooter->GetController()->SetPID(shooter->GetController()->GetP() + .0001, shooter->GetController()->GetI(), 0);
		//CommandBase::shooter->GetController()->SetPID(shooter->GetController()->GetP() , shooter->GetController()->GetI() + .00001, 0);
		//CommandBase::shooter->GetController()->SetPID( 0.0017 , shooter->GetController()->GetI() + .00001, 0);
		//printf("%f \n", CommandBase::shooter->GetController()->GetP() + .0001);
	}
	void Execute(){}
	bool IsFinished() {
		return true;
	}
	void End() {}
	void Interrupted(){}
	
};

#endif /* SPEEDUPSHOOTERCOMMAND_H_ */
