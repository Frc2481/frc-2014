/*
 * FireDiscCommand.h
 *
 *  Created on: Feb 23, 2013
 *      Author: Team2481
 */

#ifndef FIREDISCCOMMAND_H_
#define FIREDISCCOMMAND_H_

#include "../CommandBase.h"

class FireDiscCommand: public CommandBase {
private:
	bool startedFiring;
	bool hasFired;
	bool hasRetracted;
	double startedFiringTime;
	double startedRetractingTime;
	bool isAuto;
	
public:
	FireDiscCommand(bool autoCmd = true) {
		SetInterruptible(false);
		isAuto = autoCmd;
	}
	virtual ~FireDiscCommand() {}
	virtual void Initialize(){
		startedFiring = false;
		hasFired = false;
		hasRetracted = false;
		startedFiringTime = 0;
		startedRetractingTime = 0;
	}
	virtual void Execute(){
		printf("Settled = %d \n", shooter->isSettled());
		if (shooter->isSettled() && !startedFiring) {
			hopper->Fire();
			startedFiring = true;
			startedFiringTime = TimeSinceInitialized();
		}
		else if (startedFiring && TimeSinceInitialized() - startedFiringTime > HOPPER_EXTEND_TIME && !hasFired) {
			hopper->Retract();
			startedRetractingTime = TimeSinceInitialized();
			hasFired = true;
		}
		else if (hasFired && TimeSinceInitialized() - startedRetractingTime > HOPPER_LOCKOUT_TIME) {
			hasRetracted = true;
		}
	}
	virtual bool IsFinished(){
		if (!startedFiring && !oi->GetFireDiscButton()->Get() && !isAuto) {
			return true;
		}
		else {
			return hasRetracted;
		}
	}
	virtual void End(){
		hopper->Retract();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif /* FIREDISCCOMMAND_H_ */
