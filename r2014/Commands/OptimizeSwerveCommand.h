/*
 * OptimizeSwerveCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef OPTIMIZESWERVECOMMAND_H_
#define OPTIMIZESWERVECOMMAND_H_

#include "../CommandBase.h"

class OptimizeSwerveCommand: public CommandBase {
public:
	OptimizeSwerveCommand(){
	}
	virtual ~OptimizeSwerveCommand(){
		
	}
	virtual void Initialize(){
		driveTrain->SetOptimized(false);
	}
	virtual void Execute(){
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		driveTrain->SetOptimized(true);
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
