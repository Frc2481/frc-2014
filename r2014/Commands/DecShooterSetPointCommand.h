/*
 * CrabDriveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef DECSHOOTERSETPOINTCOMMAND_H_
#define DECSHOOTERSETPOINTCOMMAND_H_

#include "../CommandBase.h"

class DecShooterSetPointCommand: public CommandBase {
public:
	DecShooterSetPointCommand(){
		
	}
	virtual ~DecShooterSetPointCommand(){
		
	}
	virtual void Initialize(){
		shooter->SetPosition(shooter->GetSetPoint() - .25);
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End(){
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* CRABDRIVECOMMAND_H_ */
