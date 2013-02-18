/*
 * LoadHopperCommand.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Team2481
 */

#ifndef LOADHOPPERCOMMAND_H_
#define LOADHOPPERCOMMAND_H_

#include "../CommandBase.h"

class LoadHopperCommand: public CommandBase {
public:
	LoadHopperCommand(){
		Requires(hopper);
	}
	virtual ~LoadHopperCommand(){}
	void Initialize(){
		printf("LoadHopper");
		printf("%d \n", shooter->isAtSpeed());
		if (shooter->isAtSpeed()) {
			hopper->Load();
			airCompressor->Stop();
		}
		else{
			printf("CancelFireCommand/n");
			GetGroup()->Cancel();
		}
	}
	virtual void Execute(){}
	bool IsFinished(){
		return true;
	}
	virtual void End(){}
	virtual void Interrupted(){}
	
};

#endif /* LOADHOPPERCOMMAND_H_ */
