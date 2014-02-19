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
		printf("Fire Distance Command Distance: %f Ears: %d \n", distance , earsUp);
		shooter->SetPosition(distance, earsUp);
		
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
