#ifndef FIREDISTANCECOMMAND_H
#define FIREDISTANCECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class FireDistanceCommand : public CommandBase {
private:
	float distance;
	bool earsUp;
public:
	FireDistanceCommand(float setDistance, bool setEarsUp){
		distance = setDistance;
		earsUp = setEarsUp;
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		shooter->SetPosition(distance, earsUp);
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

#endif
