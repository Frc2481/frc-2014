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
	DisableShiftCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
