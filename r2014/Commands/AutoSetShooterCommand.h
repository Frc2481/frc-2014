/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef AUTOSETSHOOTERCOMMAND_H_
#define AUTOSETSHOOTERCOMMAND_H_

#include "../CommandBase.h"

class AutoSetShooterCommand: public CommandBase {
private:
	bool auton;
public:
	AutoSetShooterCommand(bool autonomous = false){
		auton = autonomous;
	}
	virtual ~AutoSetShooterCommand(){
		
	}
	virtual void Initialize(){
		printf("AutoSetShooterCommand Distanc: %f \n", distanceSensors->GetRight());
		if(auton){
			shooter->SetPosition(distanceSensors->GetRight() / 12, false);
		}
		else {
			shooter->SetPosition(distanceSensors->GetRight() / 12);
		}
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return shooter->OnTarget();
	}
	virtual void End(){
	}
	virtual void Interrupted(){
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
