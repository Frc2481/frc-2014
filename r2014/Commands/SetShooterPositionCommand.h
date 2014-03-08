#ifndef SetSHOOTERPOSITIONCOMMAND_H
#define SetSHOOTERPOSITIONCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class SetShooterPositionCommand : public CommandBase {
private:
	float distance;
	bool earsUp;
public:
	SetShooterPositionCommand(float setDistance, bool setEarsUp){
		distance = setDistance;
		earsUp = setEarsUp;
	}
	virtual void Initialize(){
		printf(" %f %d \n", distance , earsUp);
		shooter->SetPosition(distance, earsUp);
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
