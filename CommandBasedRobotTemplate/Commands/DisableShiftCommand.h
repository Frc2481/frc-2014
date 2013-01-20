#ifndef DISABLE_SHIFT_COMMAND_H
#define DISABLE_SHIFT_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class DisableShiftCommand: public CommandBase {
public:
	DisableShiftCommand() : CommandBase("DisableShiftCommand") {}
	void Initialize() {
		driveTrain->SetShiftEnabled(false);
	}
	void Execute(){}
	bool IsFinished() {
		return false;
	}
	void End() {}
	void Interrupted() {
		driveTrain->SetShiftEnabled(true);
	}
};

#endif
