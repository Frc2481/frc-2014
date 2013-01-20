#ifndef SHIFTER_DOWN_COMMAND_H
#define SHIFTER_DOWN_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class ShiftDownCommand: public CommandBase {
public:
	ShiftDownCommand() : CommandBase("ShiftDownCommand") {}
	void Initialize() {
		driveTrain->ShiftDown();
	}
	void Execute() {}
	bool IsFinished() {
		return true;
	}
	void End() {}
	void Interrupted() {}
};

#endif
