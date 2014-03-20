#ifndef MANUALSETSHOOTERPOSITIONCOMMAND_H
#define MANUALSETSHOOTERPOSITIONCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ManualSetShooterPositionCommand : public CommandBase {
private:
	float distance;
	bool earsUp;
public:
	ManualSetShooterPositionCommand(float setDistance, bool setEarsUp){
		distance = setDistance;
		earsUp = setEarsUp;
	}
	virtual void Initialize(){
		printf(" %f %d \n", distance , earsUp);
		shooter->ManualSetDistance(distance, earsUp);
		intake->SetReadySolenoid(true);
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return shooter->OnTarget();
	}
	virtual void End(){
		
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
