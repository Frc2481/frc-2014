#ifndef ENABLE_SHIFT_COMMAND_H
#define ENABLE_SHIFT_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class EnableShiftCommand: public CommandBase {
public:
	EnableShiftCommand() : CommandBase("EnableShiftCommand") {}
	void Initialize() {
		driveTrain->SetShiftEnabled(true);
	}
	void Execute(){}
	bool IsFinished() {
		return false;
	}
	void End() {}
	void Interrupted() {
		driveTrain->SetShiftEnabled(false);
	}
};

#endif
