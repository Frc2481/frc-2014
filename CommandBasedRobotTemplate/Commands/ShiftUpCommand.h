#ifndef SHIFTER_UP_COMMAND_H
#define SHIFTER_UP_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class ShiftUpCommand: public CommandBase {
public:
	ShiftUpCommand() : CommandBase("ShiftUpCommand") {}
	void Initialize() {
		driveTrain->ShiftUp();
	}
	void Execute() {}
	bool IsFinished() {
		return true;
	}
	void End() {}
	void Interrupted() {}
};

#endif
