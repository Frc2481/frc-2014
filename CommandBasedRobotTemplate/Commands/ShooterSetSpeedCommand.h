/*
 * ShooterSetSpeedCommand.h
 *
 *  Created on: Apr 26, 2013
 *      Author: Team2481
 */

#ifndef SHOOTERSETSPEEDCOMMAND_H_
#define SHOOTERSETSPEEDCOMMAND_H_

#include "../CommandBase.h"

class ShooterSetSpeedCommand: public CommandBase {
private:
	float userSpeed;
public:
	ShooterSetSpeedCommand(float speed){
		userSpeed = speed;
	}
	virtual ~ShooterSetSpeedCommand(){}
	void Initialize(){
		shooter->SetSetpoint(userSpeed);
	}
	void Execute(){}
	void Interrupted(){}
	void End(){}
	bool IsFinished(){
		return true;
	}
};

#endif /* SHOOTERSETSPEEDCOMMAND_H_ */
