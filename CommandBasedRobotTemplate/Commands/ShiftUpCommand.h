#ifndef SHIFT_UP_COMMAND_H
#define SHIFT_UP_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class ShiftUpCommand: public CommandBase {
public:
	ShiftUpCommand() : CommandBase("ShiftUpCommand") {}
	void Initialize() {	}
	void Execute(){
		if(/*driveTrain->IsSpedUp()&&*/ !driveTrain->IsShifted()){
			driveTrain->ShiftUp();
		}
	}
	bool IsFinished() {
		return false;
	}
	void End() {}
	void Interrupted() {
		driveTrain->ShiftDown();
	}
};

#endif
